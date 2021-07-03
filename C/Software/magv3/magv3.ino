#include "Arduino.h"
#include "SPI.h"
#include "Wire.h"
#include "esp_bt_main.h"
#include "esp_bt.h"
#include "esp_wifi.h"
#include "Esp.h"
#include "WireSlave.h"
#include "FS.h"
#include "SD.h"

#define SDA_PIN 33
#define SCL_PIN 32
#define I2C_SLAVE_ADDR 0x52

uint32_t freq = 1000000;
// Continuous Measurement Value
byte cmm_v = 0x79; // xyz

// Accumulation time (millis)
int acc_time = 1000;

// Count Cycles Write Registers
byte cmm = 0x01;

byte sts;
byte msb;
byte lsb;

// set pin as the slave select for the digital pot:
const int pinSS1 = 2;
const int pinSS2 = 5;
//TMP102
int tmp102Address1 = 0x48;
int tmp102Address2 = 0x49;

static const int spiClk = 1000000; // 1 MHz

long time_c;
uint8_t counter1 = 0;
uint8_t counter2 = 0;

long mesx1 = 0;
long mesy1 = 0;
long mesz1 = 0;

long mesx2 = 0;
long mesy2 = 0;
long mesz2 = 0;

long accx1 = 0;
long accy1 = 0;
long accz1 = 0;

long accx2 = 0;
long accy2 = 0;
long accz2 = 0;

int celsius1;
int celsius2;
uint8_t number1;
uint8_t number2;

int option;
int option_set;

#define SPI_SS(y,x) digitalWrite(y, x)

void receiveEvent(int howMany);

void setup()
{
  esp_bluedroid_disable();
  esp_bt_controller_disable();
  esp_wifi_stop();

  byte high;
  byte low;
  // set the slaveSelectPin as an output:
  pinMode(pinSS1, OUTPUT);
  pinMode(pinSS2, OUTPUT);
  //pinMode(4, OUTPUT);
  digitalWrite(pinSS1, HIGH);
  digitalWrite(pinSS2, HIGH);
  //digitalWrite(4, HIGH);
  Serial.begin(115200);
  Wire.begin();

  bool success = WireSlave.begin(SDA_PIN, SCL_PIN, I2C_SLAVE_ADDR);
  if (!success) {
    Serial.println("I2C slave init failed");
    while (1) delay(100);
  }

  // initialize SPI:
  if (!SD.begin(4, SPI, freq)) {
    Serial.println("Card Mount Failed");
    return;
  }
  //SPI.begin();
  //SPI.beginTransaction(SPISettings(spiClk, MSBFIRST, SPI_MODE0));

  // Star Continuous Measurement Mode
  SPI_SS(pinSS1, LOW);
  sts = SPI.transfer(cmm);
  lsb = SPI.transfer(cmm_v);
  SPI_SS(pinSS1, HIGH);

  SPI_SS(pinSS2, LOW);
  sts = SPI.transfer(cmm);
  lsb = SPI.transfer(cmm_v);
  SPI_SS(pinSS2, HIGH);

  time_c = millis();

  WireSlave.onReceive(receiveEvent);
}

void loop()
{
  byte state;
  byte mx[4];
  byte my[4];
  byte mz[4];
  long mag_valuex = 0;
  long mag_valuey = 0;
  long mag_valuez = 0;
  byte val = 0x00;
  byte sxi = 0xA4;
  byte sensor = B01110000;
  byte dumy = B00000000;
  // the slave response time is directly related to how often
  // this update() method is called, so avoid using long delays
  // inside loop(), and be careful with time-consuming tasks
  WireSlave.update();

  // let I2C and other ESP32 peripherals interrupts work
  //delay(1);
    time_c = millis();

  if (option_set == 0)
  {
    //Wait
    Serial.println("Waiting");
    delay(1);
  }
  else if (option_set == 1)
  {
    //initializate
    Serial.println("Starting Mag");
    deleteFile(SD, "/mag");
    option_set = 2;
    delay(1);
  }
  else if (option_set == 2)
  {
    //Measuring

    while (1)
    {
      WireSlave.update();
      SPI_SS(pinSS1, LOW);
      state = SPI.transfer(0xB4);
      SPI_SS(pinSS1, HIGH);

      if (bitRead(state, 7))
      {
        SPI_SS(pinSS1, LOW);
        state = SPI.transfer(sxi);
        mx[1] = SPI.transfer(dumy);
        mx[2] = SPI.transfer(dumy);
        mx[3] = SPI.transfer(dumy);
        my[1] = SPI.transfer(dumy);
        my[2] = SPI.transfer(dumy);
        my[3] = SPI.transfer(dumy);
        mz[1] = SPI.transfer(dumy);
        mz[2] = SPI.transfer(dumy);
        mz[3] = SPI.transfer(dumy);
        SPI_SS(pinSS1, HIGH);

        mag_valuex = 0;
        if (mx[1] >= B10000000)
        {
          mx[0] = 0xFF;
        }
        else
        {
          mx[0] = 0x00;
        }
        mag_valuex += (long)mx[0] << 24;
        mag_valuex += (long)mx[1] << 16;
        mag_valuex += (long)mx[2] << 8;
        mag_valuex += (long)mx[3];

        mag_valuey = 0;
        if (my[1] >= B10000000)
        {
          my[0] = 0xFF;
        }
        else
        {
          my[0] = 0x00;
        }
        mag_valuey += (long)my[0] << 24;
        mag_valuey += (long)my[1] << 16;
        mag_valuey += (long)my[2] << 8;
        mag_valuey += (long)my[3];

        mag_valuez = 0;
        if (mz[1] >= B10000000)
        {
          mz[0] = 0xFF;
        }
        else
        {
          mz[0] = 0x00;
        }
        mag_valuez += (long)mz[0] << 24;
        mag_valuez += (long)mz[1] << 16;
        mag_valuez += (long)mz[2] << 8;
        mag_valuez += (long)mz[3];

        mesx1 = mag_valuex;
        mesy1 = mag_valuey;
        mesz1 = mag_valuez;

        accx1 += mag_valuex;
        accy1 += mag_valuey;
        accz1 += mag_valuez;
        counter1 += 1;
        //}

        mag_valuex = 0;
        mag_valuey = 0;
        mag_valuez = 0;

        SPI_SS(pinSS2, LOW);
        state = SPI.transfer(0xB4);
        SPI_SS(pinSS2, HIGH);

        if (bitRead(state, 7))
        {
          SPI_SS(pinSS2, LOW);
          state = SPI.transfer(sxi);
          mx[1] = SPI.transfer(dumy);
          mx[2] = SPI.transfer(dumy);
          mx[3] = SPI.transfer(dumy);
          my[1] = SPI.transfer(dumy);
          my[2] = SPI.transfer(dumy);
          my[3] = SPI.transfer(dumy);
          mz[1] = SPI.transfer(dumy);
          mz[2] = SPI.transfer(dumy);
          mz[3] = SPI.transfer(dumy);
          SPI_SS(pinSS2, HIGH);

          mag_valuex = 0;
          if (mx[1] >= B10000000)
          {
            mx[0] = 0xFF;
          }
          else
          {
            mx[0] = 0x00;
          }
          mag_valuex += (long)mx[0] << 24;
          mag_valuex += (long)mx[1] << 16;
          mag_valuex += (long)mx[2] << 8;
          mag_valuex += (long)mx[3];

          mag_valuey = 0;
          if (my[1] >= B10000000)
          {
            my[0] = 0xFF;
          }
          else
          {
            my[0] = 0x00;
          }
          mag_valuey += (long)my[0] << 24;
          mag_valuey += (long)my[1] << 16;
          mag_valuey += (long)my[2] << 8;
          mag_valuey += (long)my[3];

          mag_valuez = 0;
          if (mz[1] >= B10000000)
          {
            mz[0] = 0xFF;
          }
          else
          {
            mz[0] = 0x00;
          }
          mag_valuez += (long)mz[0] << 24;
          mag_valuez += (long)mz[1] << 16;
          mag_valuez += (long)mz[2] << 8;
          mag_valuez += (long)mz[3];

          mesx2 = mag_valuex;
          mesy2 = mag_valuey;
          mesz2 = mag_valuez;

          accx2 += mag_valuex;
          accy2 += mag_valuey;
          accz2 += mag_valuez;
          counter2 += 1;

          //Serial.print(mesx1); Serial.print(','); Serial.print(mesy1); Serial.print(','); Serial.println(mesz1);
        }
      }

      if (millis() >= time_c + acc_time) {
        celsius1 = getTemperature(tmp102Address1);
        celsius2 = getTemperature(tmp102Address2);
        number1 = 1;
        number2 = 2;
        Serial.print(number1); Serial.print(',');
        Serial.print(counter1); Serial.print(',');
        Serial.print(accx1); Serial.print(','); Serial.print(accy1); Serial.print(','); Serial.print(accz1);
        Serial.print(','); Serial.print(celsius1); Serial.print(',');
        Serial.print(number2); Serial.print(',');
        Serial.print(counter2); Serial.print(',');
        Serial.print(accx2); Serial.print(','); Serial.print(accy2); Serial.print(','); Serial.print(accz2); Serial.print(',');
        Serial.println(celsius2);

        if ( writeFile(SD, "/mag"))
        {
        }

        counter1 = 0;
        counter2 = 0;

        accx1 = 0;
        accy1 = 0;
        accz1 = 0;

        accx2 = 0;
        accy2 = 0;
        accz2 = 0;

        break;
      }
      delay(1);
    }
  }

  else if (option_set == 3)
  {
    //Stop measurement
    Serial.println("Stop");
    option_set = 0;
    delay(1);
  }

  else if (option_set == 4)
  {
    //Recovering data
    deleteFile(SD, "/exmag");
    readFile(SD, "/mag");
    renameFile(SD, "/mag", "/exmag");
    Serial.println("Recovering");
    option_set = 0;
    delay(1);
  }

  else if (option_set == 5)
  {
    //Esp Reset
    Serial.println("Restarting");
    delay(3000);
    ESP.restart();
  }
  
  else if (option_set == 6)
  {
    //Read exmag
    readFile(SD, "/exmag");
    Serial.println("R exmag");
    option_set = 0;
    delay(1);
  }
}

// function that executes whenever a complete and valid packet
// is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
  int option = WireSlave.read();   // receive byte as an integer
  Serial.println(option);// print the integer
  if (option > 0) {
    option_set = option;
  }
}

int getTemperature(int tmp) {
  Wire.requestFrom(tmp, 2);

  byte MSB = Wire.read();
  byte LSB = Wire.read();

  //it’s a 12bit int, using two’s compliment for negative
  int TemperatureSum = ((MSB << 8) | LSB) >> 4;

  //float celsius = TemperatureSum*0.0625;
  return TemperatureSum;
}

void deleteFile(fs::FS &fs, const char * path) {
  Serial.printf("Deleting file: %s\n", path);
  if (fs.remove(path)) {
    Serial.println("File deleted");
  } else {
    Serial.println("Delete failed");
  }
}

byte writeFile(fs::FS &fs, const char * path) {
  Serial.printf("Writing file: %s\n", path);

  File file = fs.open(path, FILE_APPEND);
  if (file) {
    file.write(number1);
    file.write(counter1);
    file.write(accx1);
    file.write(accy1);
    file.write(accz1);
    file.write(celsius1);

    file.write(number2);
    file.write(counter2);
    file.write(accx2);
    file.write(accy2);
    file.write(accz2);
    file.write(celsius2);
    file.close();
    return 1;
  }
  return 0;
}

void renameFile(fs::FS &fs, const char * path1, const char * path2) {
  Serial.printf("Renaming file %s to %s\n", path1, path2);
  if (fs.rename(path1, path2)) {
    Serial.println("File renamed");
  } else {
    Serial.println("Rename failed");
  }
}

void readFile(fs::FS &fs, const char * path) {
  Serial.printf("Reading file: %s\n", path);

  File file = fs.open(path);
  if (!file) {
    Serial.println("Failed to open file for reading");
    return;
  }

  Serial.print("Read from file: ");
  while (file.available()) {
    Serial.write(file.read());
  }
  file.close();
}
