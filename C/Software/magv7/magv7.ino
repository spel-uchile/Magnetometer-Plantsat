// include the SPI library:
#include "SPI.h"
#include "esp_bt_main.h"
#include "esp_bt.h"
#include "esp_wifi.h"
#include "Esp.h"
#include "FS.h"
#include "SD.h"

// EEPROM
#include "SparkFun_External_EEPROM.h"
// I2C Slave
#ifndef Wire
#include <Wire.h>
#endif
#ifndef WireSlave
#include <WireSlave.h>
#endif


//Pines I2C a conectar al magnetometro
//Actualmente el trabajo lo hace el serial
//via serial mandamos un valor y este establece el modo de
//funcionamiento del dispositivo
// 10 (0x0A) modo espera
// 11 (0x0B) Eliminar archivo de datos y pasar al modo 2
// 12 (0x0C)Medir continuamente
// 13 (0x0D)Detener mediciones
// 14 (0x0E)Se renombra el alchivo de mediciones (mag a exmag) y se transmite via serial las mediciones tomadas
// 15 (0x0F)Reiniciar ESP32
// 16 (0x10)Leer datos desde el el archivo de mediciones renombrado (exmag)
// 17 (0x11)Escribir datos a la EEPROM (mag)
// 18 (0x12)Escribir datos a la EEPROM (exmag)
// 19 (0x13)Medir continuamente (pero guardando mediciones en la memoria volatil)
// 20 (0x14)borra la meomria volatil y comenzar Medir continuamente (pero guardando mediciones en la memoria volatil)
// 21 (0x15)escribir desde memoria volatil a la eeprom
// 22 (0x16)escribir desde memoria volatil al puerto serial
// Todas esas acciones debiesen ser hechas via I2C
// En el caso de usar EEPROM debiese haber un registro para leer el estado
// Y el restro para guardar los datos leidos
// Cada medicion de campo magnetico tiene 4 bits, las de temperaturas 2 bits
// ademas del numero de medicioens 1 bit
// En total el numero minimo de bits es de 30 bits por medicion

// Slave I2C
#define SDA_PIN 33
#define SCL_PIN 32

// Main I2C
#define SDA_1 21
#define SCL_1 22

// I2C freq
uint32_t freq = 1000000;
bool sd_flag = true;
uint16_t measurement_counter = 0;

// Activation Continuous mode
//bool act_cmm = true; //Continuous Mode Activated
//bool act_cmm = false;//Continuous Mode Deactivated

// Continuous Measurement Value
byte cmm_v = 0x79; // xyz

// Accumulation time (millis)
int acc_time = 10;

// Count Cycles Write Registers
byte cmm = 0x01;

byte sts;
byte msb;
byte lsb;


// set pin 10 as the slave select for the digital pot:
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

char option;
char option_set;

//TwoWire I2Czero = TwoWire(0);
TwoWire I2Cone = TwoWire(1);

ExternalEEPROM myMem;
#define EEPROM_ADDRESS 0x50

void receiveEvent(int numBytes);

byte I2C_SLAVE_ADDR = 0x58;
int howManyBytesReceived;
byte conserve[65536];
uint16_t con_counter = 0;

#define SPI_SS(y,x) digitalWrite(y, x)

void setup()
{

  option_set = 10;

  Serial.begin(115200);

  Serial.println("Disabling Bluetooth");

  esp_bluedroid_disable();
  esp_bt_controller_disable();

  // NOT working on SPARKFUN ESP32 Thing
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

  // MAG
  I2Cone.begin(SDA_1, SCL_1, 100000);

  /*
    // EEPROM
    I2Ctwo.begin(SDA_PIN, SCL_PIN, 100000);

    myMem.begin(EEPROM_ADDRESS, I2Ctwo);

    // Test EEPROM
    int randNumber = random(256);
    Serial.print("I generated: ");
    Serial.println(randNumber);
    myMem.put(1, randNumber);
    int readInt;
    myMem.get(1, readInt); //location to read, thing to put data into
    Serial.print("I read: ");
    Serial.println(readInt);
    if (readInt == randNumber){
    Serial.println("EEPROM Test OK!");
    }
    else {
    Serial.println("EEPROM Test failed!");
    }
  */

  Serial.println("Changing to slave mode");
  bool success = WireSlave.begin(SDA_PIN, SCL_PIN, I2C_SLAVE_ADDR);
  if (!success) {
    Serial.println("I2C slave init failed");
    return;
  }

  WireSlave.onReceive(receiveEvent);

  Serial.printf("Slave joined I2C bus with addr #%d\n", I2C_SLAVE_ADDR);

  /*
    Serial.println("Changing back to master");
    I2Ctwo.begin(SDA_PIN, SCL_PIN, 1000000);
    myMem.begin(EEPROM_ADDRESS, I2Ctwo);

    // Test EEPROM Number 2
    randNumber = random(256);
    Serial.print("I generated: ");
    Serial.println(randNumber);
    myMem.put(1, randNumber);
    myMem.get(1, readInt); //location to read, thing to put data into
    Serial.print("I read: ");
    Serial.println(readInt);
    if (readInt == randNumber){
    Serial.println("EEPROM Test 2 OK!");
    }
    else {
    Serial.println("EEPROM Test 2 failed!");
    }
  */

  // Check if SDCard is mounted
  if (!SD.begin(4, SPI, freq)) {
    Serial.println("Card Mount Failed");
    sd_flag = false;
    //return;
  }

  // initialize SPI:
  //SPI.begin();
  //SPI.beginTransaction(SPISettings(spiClk, MSBFIRST, SPI_MODE0));

  // Star Continuous Measurement Mode
  SPI_SS(pinSS1, LOW);
  sts = SPI.transfer(cmm);
  lsb = SPI.transfer(cmm_v);
  SPI_SS(pinSS1, HIGH);

  // ????
  SPI_SS(pinSS2, LOW);
  sts = SPI.transfer(cmm);
  lsb = SPI.transfer(cmm_v);
  SPI_SS(pinSS2, HIGH);

  time_c = millis();
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

  //if (Serial.available() > 0)
  //{
  //  option = Serial.parseInt();
  //  if (option > 0) {
  //    option_set = option;
  //  }
  //}

  time_c = millis();

  WireSlave.update();


  // =========================================================================================================

  if (option_set == 10)
  {
    //Wait
    Serial.println("Waiting");
    delay(5000);
  }

  // =========================================================================================================

  else if (option_set == 11)
  {
    //initializate
    Serial.println("Starting Mag");
    deleteFile(SD, "/mag");
    option_set = 12;
  }

  // =========================================================================================================

  else if ((option_set == 12) || (option_set == 19))
  {
    //Measuring

    while (1)
    {
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

      if (millis() >= time_c + 1000) {
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

        measurement_counter += 1;
        Serial.println(measurement_counter);

        if (option_set == 12)
        {
          if (writeFile(SD, "/mag"))
          {
          }
        }
        else if (option_set == 19)
        {
           con_counter = conserve_data(con_counter);
           Serial.print(con_counter);
        }

        counter1 = 0;
        counter2 = 0;

        accx1 = 0;
        accy1 = 0;
        accz1 = 0;

        accx2 = 0;
        accy2 = 0;
        accz2 = 0;


        if (measurement_counter >= 2048)
        {
          measurement_counter = 0;
          option_set = 10;
        }
        break;
      }
    }
  }

  // =========================================================================================================

  else if (option_set == 13)
  {
    //Stop measurement
    Serial.println("Stop");
    option_set = 10;
  }

  // =========================================================================================================

  else if (option_set == 14)
  {
    //Recovering data
    deleteFile(SD, "/exmag");
    readFile(SD, "/mag");
    renameFile(SD, "/mag", "/exmag");
    Serial.println("Recovering");

    option_set = 15;
  }

  // =========================================================================================================

  else if (option_set == 15)
  {
    //Esp Reset
    Serial.println("Restarting");
    delay(3000);
    ESP.restart();
  }

  // =========================================================================================================

  else if (option_set == 16)
  {
    //Read exmag
    readFile(SD, "/exmag");
    Serial.println("R exmag");

    option_set = 15;
  }

  // ===============DE SD mag A EEPROM====================================================================

  else if (option_set == 17)
  {
    //Write code to the eeprom

    //WireSlave.flush();


    Wire1.begin(SDA_PIN, SCL_PIN, 100000);
    myMem.begin(EEPROM_ADDRESS, Wire1);
    deleteFile(SD, "/exmag");
    write_eeprom(SD, "/mag");
    renameFile(SD, "/mag", "/exmag");
    Serial.println("Recovering");
    option_set = 15;

  }

  // ===============DE SD exmag A EEPROM====================================================================

  else if (option_set == 18)
  {
    //Write code to the eeprom

    //WireSlave.flush();


    Wire1.begin(SDA_PIN, SCL_PIN, 100000);
    myMem.begin(EEPROM_ADDRESS, Wire1);

    //Read exmag
    write_eeprom(SD, "/exmag");
    Serial.println("R exmag");

    option_set = 15;

  }
  // ===============19 junto a 12====================================================================
  // ===============DE SD exmag A EEPROM====================================================================

    else if (option_set == 20)
  {
    //initializate
    Serial.println("Starting Mag (volatil)");
//    for(uint32_t i = 0; i <= 65535; i++)
//    {
//      Serial.println(i);
//      conserve[i] = 0;
//      delay(1);
//    }
    con_counter = 0;
    option_set = 19;
  }

// ===============DE esp  A EEPROM====================================================================

  else if (option_set == 21)
  {
    //Write code to the eeprom

    //WireSlave.flush();


    Wire1.begin(SDA_PIN, SCL_PIN, 100000);
    myMem.begin(EEPROM_ADDRESS, Wire1);

    for(uint32_t i = 0; i <= 65535; i++)
    {
      myMem.put(i, conserve[i]);
    }
    
    option_set = 15;

  }

  // ===============DE esp  A EEPROM====================================================================

  else if (option_set == 22)
  {
    //Write code to the eeprom

    //WireSlave.flush();


    Wire1.begin(SDA_PIN, SCL_PIN, 100000);
    myMem.begin(EEPROM_ADDRESS, Wire1);

    for(uint32_t i = 0; i <= 65535; i++)
    {
      Serial.print(conserve[i]);
    }
    
    option_set = 15;

  }
  // =============Other Condition Reset=======================================================================

  else 
  {
    //Esp Reset
    Serial.println("Restarting");
    delay(3000);
    ESP.restart();
  }
}


// =========================================================================================================
// =========================================================================================================

/*
  void receiveEvent(int howMany)
  {
    option_set = WireSlave.read();
    Serial.print("Option selected is ");
    Serial.println(option_set);
  }
*/

void receiveEvent(int numBytes)
{
  Serial.print(F("---> received "));
  Serial.print(numBytes);
  howManyBytesReceived = numBytes;
  Serial.println(F(" events on i2c bus"));
  option_set = WireSlave.read();
  Serial.print(F("---> received option "));
  Serial.println(option_set + 32);

}

// =========================================================================================================
// Get Temperature from sensors
// =========================================================================================================
int getTemperature(int tmp) {
  I2Cone.requestFrom(tmp, 2);

  byte MSB = I2Cone.read();
  byte LSB = I2Cone.read();

  //it’s a 12bit int, using two’s compliment for negative
  int TemperatureSum = ((MSB << 8) | LSB) >> 4;

  //float celsius = TemperatureSum*0.0625;
  return TemperatureSum;
}

// =========================================================================================================
// =========================================================================================================
void deleteFile(fs::FS &fs, const char * path) {
  Serial.printf("Deleting file: %s\n", path);
  if (fs.remove(path)) {
    Serial.println("File deleted");
  } else {
    Serial.println("Delete failed");
  }
}

// =========================================================================================================
// =========================================================================================================
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

// ===================Save data in the program====================================================================
// =========================================================================================================
uint16_t conserve_data(uint16_t con_counter) {
  conserve[con_counter]=number1;
  con_counter += 1;
  conserve[con_counter]=counter1;
  con_counter += 1;
  conserve[con_counter]=(accx1 & 0xFF000000) >> 24;
  con_counter += 1;
  conserve[con_counter]=(accx1 & 0x00FF0000) >> 16;
  con_counter += 1;
  conserve[con_counter]=(accx1 & 0x0000FF00) >> 8;
  con_counter += 1;
  conserve[con_counter]=(accx1 & 0x000000FF);
  con_counter += 1;
  conserve[con_counter]=(accy1 & 0xFF000000) >> 24;
  con_counter += 1;
  conserve[con_counter]=(accy1 & 0x00FF0000) >> 16;
  con_counter += 1;
  conserve[con_counter]=(accy1 & 0x0000FF00) >> 8;
  con_counter += 1;
  conserve[con_counter]=(accy1 & 0x000000FF);
  con_counter += 1;
  conserve[con_counter]=(accz1 & 0xFF000000) >> 24;
  con_counter += 1;
  conserve[con_counter]=(accz1 & 0x00FF0000) >> 16;
  con_counter += 1;
  conserve[con_counter]=(accz1 & 0x0000FF00) >> 8;
  con_counter += 1;
  conserve[con_counter]=(accz1 & 0x000000FF);
  con_counter += 1;
  conserve[con_counter]=highByte(celsius1);
  con_counter += 1;
  conserve[con_counter]=lowByte(celsius1);
  con_counter += 1;
  
  conserve[con_counter]=number2;
  con_counter += 1;
  conserve[con_counter]=counter2;
  con_counter += 1;
  conserve[con_counter]=(accx2 & 0xFF000000) >> 24;
  con_counter += 1;
  conserve[con_counter]=(accx2 & 0x00FF0000) >> 16;
  con_counter += 1;
  conserve[con_counter]=(accx2 & 0x0000FF00) >> 8;
  con_counter += 1;
  conserve[con_counter]=(accx2 & 0x000000FF);
  con_counter += 1;
  conserve[con_counter]=(accy2 & 0xFF000000) >> 24;
  con_counter += 1;
  conserve[con_counter]=(accy2 & 0x00FF0000) >> 16;
  con_counter += 1;
  conserve[con_counter]=(accy2 & 0x0000FF00) >> 8;
  con_counter += 1;
  conserve[con_counter]=(accy2 & 0x000000FF);
  con_counter += 1;
  conserve[con_counter]=(accz2 & 0xFF000000) >> 24;
  con_counter += 1;
  conserve[con_counter]=(accz2 & 0x00FF0000) >> 16;
  con_counter += 1;
  conserve[con_counter]=(accz2 & 0x0000FF00) >> 8;
  con_counter += 1;
  conserve[con_counter]=(accz2 & 0x000000FF);
  con_counter += 1;
  conserve[con_counter]=highByte(celsius2);
  con_counter += 1;
  conserve[con_counter]=lowByte(celsius2);
  con_counter += 1;
  
  return con_counter;
}

// =========================================================================================================
// =========================================================================================================
void renameFile(fs::FS &fs, const char * path1, const char * path2) {
  Serial.printf("Renaming file %s to %s\n", path1, path2);
  if (fs.rename(path1, path2)) {
    Serial.println("File renamed");
  } else {
    Serial.println("Rename failed");
  }
}

// =========================================================================================================
// =========================================================================================================
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

// ===========================READ SD Write EEPPROM===============================================================
// =========================================================================================================
void write_eeprom(fs::FS &fs, const char * path) {
  uint8_t eeprom_addr = 0; 
  Serial.printf("Reading file: %s\n", path);

  File file = fs.open(path);
  if (!file) {
    Serial.println("Failed to open file for reading");
    //return;
  }
  Serial.print("Read from file: ");
  while (file.available()) {
    myMem.put(eeprom_addr, file.read());
    eeprom_addr += 1;
    if (eeprom_addr == 65535)
    {
      break;
    }
  }
  file.close();
  
  if (eeprom_addr < 65535)
  {
    for(uint32_t i = eeprom_addr; i <= 65535; i++)
    {
      myMem.put(eeprom_addr, 0);
    }
  }
  
}
