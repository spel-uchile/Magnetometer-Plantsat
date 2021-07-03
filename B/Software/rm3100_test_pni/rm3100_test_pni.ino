// inslude the SPI library:
#include <SPI.h>

// Activation Continuous mode
bool act_cmm = true; //Continuous Mode Activated
//bool act_cmm = false;//Continuous Mode Deactivated

// Number of Count Cycles
//int cyclex = 200;
//int cycley = 200;
//int cyclez = 200;

// Max Sampling Rate Continuous Measurement Mode
//byte tmrc_v = 0x92; // max 600 Hz
//byte tmrc_v = 0x93; // max 300 Hz
//byte tmrc_v = 0x94; // max 150 Hz
//byte tmrc_v = 0x95; // max 75 Hz
//byte tmrc_v = 0x96; // max 37 Hz Default

// Continuous Measurement Value
byte cmm_v = 0x79; // xyz
//byte cmm_v = 0x49; // x
//byte cmm_v = 0x51; // y
//byte cmm_v = 0x61; // z

// Accumulation time (millis)
int acc_time = 2;

// Count Cycles Write Registers
byte cmm = 0x01;
//byte cmx = 0x04;
//byte clx = 0x05;
//byte cmy = 0x06;
//byte cly = 0x07;
//byte cmz = 0x08;
//byte clz = 0x09;
//byte tmrc = 0x0B;


// Count Cycles Read Registers
//byte rcmx = 0x84;
//byte rclx = 0x85;
//byte rcmy = 0x86;
//byte rcly = 0x87;
//byte rcmz = 0x88;
//byte rclz = 0x89;
//byte rtmrc = 0x8B;

byte sts;
byte msb;
byte lsb;


// set pin 10 as the slave select for the digital pot:
const int pinSS = 5;
const int pinSS2 = 2;
const int drpin = 32;

static const int spiClk = 1000000; // 1 MHz

long time_c;
int counter = 0;


long accx = 0;
long accy = 0;
long accz = 0;

long accx2 = 0;
long accy2 = 0;
long accz2 = 0;

#define SPI_SS(x) digitalWrite(pinSS, x)
#define SPI_SS2(x) digitalWrite(pinSS2, x)
void setup()
{
  byte high;
  byte low;
  // set the slaveSelectPin as an output:
  pinMode(pinSS, OUTPUT);
  pinMode(drpin, INPUT);
  pinMode(pinSS2, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(pinSS, HIGH);
  digitalWrite(pinSS2, HIGH);
  digitalWrite(4, HIGH);
    
  Serial.begin(115200);

  //SPI.setClockDivider(8);
  // initialize SPI:
  SPI.begin();
  SPI.beginTransaction(SPISettings(spiClk, MSBFIRST, SPI_MODE0));

//  high = highByte(cyclex);
//  low = lowByte(cyclex);

//  SPI_SS(LOW);
//  sts = SPI.transfer(cmx);
//  msb = SPI.transfer(high);
//  SPI_SS(HIGH);
//
//  SPI_SS(LOW);
//  sts = SPI.transfer(clx);
//  lsb = SPI.transfer(low);
//  SPI_SS(HIGH);
//
//  high = highByte(cycley);
//  low = lowByte(cycley);
//
//  SPI_SS(LOW);
//  sts = SPI.transfer(cmy);
//  msb = SPI.transfer(high);
//  SPI_SS(HIGH);
//
//  SPI_SS(LOW);
//  sts = SPI.transfer(cly);
//  lsb = SPI.transfer(low);
//  SPI_SS(HIGH);
//
//  high = highByte(cyclez);
//  low = lowByte(cyclez);
//
//  SPI_SS(LOW);
//  sts = SPI.transfer(cmz);
//  msb = SPI.transfer(high);
//  SPI_SS(HIGH);
//
//  SPI_SS(LOW);
//  sts = SPI.transfer(clz);
//  lsb = SPI.transfer(low);
//  SPI_SS(HIGH);
//
//  SPI_SS(LOW);
//  sts = SPI.transfer(tmrc);
//  lsb = SPI.transfer(tmrc_v);
//  SPI_SS(HIGH);

  if (act_cmm)
  {
    SPI_SS(LOW);
    sts = SPI.transfer(cmm);
    lsb = SPI.transfer(cmm_v);
    SPI_SS(HIGH);
    delay(1);
    SPI_SS2(LOW);
    sts = SPI.transfer(cmm);
    lsb = SPI.transfer(cmm_v);
    SPI_SS2(HIGH);
  }
  else
  {
    SPI_SS(LOW);
    sts = SPI.transfer(cmm);
    lsb = SPI.transfer(0x78);
    SPI_SS(HIGH);
    delay(1);
    SPI_SS2(LOW);
    sts = SPI.transfer(cmm);
    lsb = SPI.transfer(0x78);
    SPI_SS2(HIGH);
  }


  /*
    SPI_SS(LOW);
    sts = SPI.transfer(rcmx);
    msb = SPI.transfer(0x80);
    SPI_SS(HIGH);

    SPI_SS(LOW);
    sts = SPI.transfer(rclx);
    lsb = SPI.transfer(0x80);
    SPI_SS(HIGH);

    Serial.println(msb);
    Serial.println(lsb);

    SPI_SS(LOW);
    sts = SPI.transfer(rcmy);
    msb = SPI.transfer(0x80);
    SPI_SS(HIGH);

    SPI_SS(LOW);
    sts = SPI.transfer(rcly);
    lsb = SPI.transfer(0x80);
    SPI_SS(HIGH);

    Serial.println(msb);
    Serial.println(lsb);

    SPI_SS(LOW);
    sts = SPI.transfer(rcmz);
    msb = SPI.transfer(0x80);
    SPI_SS(HIGH);

    SPI_SS(LOW);
    sts = SPI.transfer(clz);
    lsb = SPI.transfer(0x80);
    SPI_SS(HIGH);

    Serial.println(msb);
    Serial.println(lsb);

    SPI_SS(LOW);
    sts = SPI.transfer(rtmrc);
    lsb = SPI.transfer(0x80);
    SPI_SS(HIGH);

    Serial.println(lsb);

  */




  time_c = millis();
}

void loop()
{
  byte ans;
  byte ans2;
  byte ans3;
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

  if (act_cmm)
  {
    SPI_SS(LOW);
    ans3 = SPI.transfer(0xB4);
    SPI_SS(HIGH);
    
    if (bitRead(ans3,7))
    {
      SPI_SS(LOW);
      ans3 = SPI.transfer(sxi);
      mx[1] = SPI.transfer(dumy);
      mx[2] = SPI.transfer(dumy);
      mx[3] = SPI.transfer(dumy);
      my[1] = SPI.transfer(dumy);
      my[2] = SPI.transfer(dumy);
      my[3] = SPI.transfer(dumy);
      mz[1] = SPI.transfer(dumy);
      mz[2] = SPI.transfer(dumy);
      mz[3] = SPI.transfer(dumy);
      SPI_SS(HIGH);

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

      accx = mag_valuex;
      accy = mag_valuey;
      accz = mag_valuez;

      Serial.print(accx); Serial.print(','); Serial.print(accy); Serial.print(','); Serial.println(accz);
    }

  }
  else
  {
    SPI_SS(LOW);
    ans = SPI.transfer(val);
    ans2 = SPI.transfer(sensor);
    SPI_SS(HIGH);
    //Serial.print(ans, BIN); Serial.print(',');Serial.print(ans2, BIN); Serial.print(',');Serial.println(digitalRead(drpin));
    while (digitalRead(drpin) == 0)
    {
    }
    //Serial.println(digitalRead(drpin));
    SPI_SS(LOW);
    ans3 = SPI.transfer(sxi);
    mx[1] = SPI.transfer(dumy);
    mx[2] = SPI.transfer(dumy);
    mx[3] = SPI.transfer(dumy);
    my[1] = SPI.transfer(dumy);
    my[2] = SPI.transfer(dumy);
    my[3] = SPI.transfer(dumy);
    mz[1] = SPI.transfer(dumy);
    mz[2] = SPI.transfer(dumy);
    mz[3] = SPI.transfer(dumy);
    SPI_SS(HIGH);

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

    if (millis() < time_c + acc_time)
    {
      accx += mag_valuex;
      accy += mag_valuey;
      accz += mag_valuez;
      counter += 1;
    }
    else
    {
      //Serial.println(counter);
      Serial.print(accx / counter); Serial.print(','); Serial.print(accy / counter); Serial.print(','); Serial.println(accz / counter);

      //Serial.print(accx/counter);Serial.print(','); Serial.print(accy/counter);Serial.print(',');Serial.print(accz/counter);Serial.print(',');Serial.println(counter);
      //Serial.print(accx);Serial.print(','); Serial.print(accy);Serial.print(',');Serial.print(accz);Serial.print(',');Serial.println(counter);

      accx = 0;
      accy = 0;
      accz = 0;
      counter = 0;
      time_c = millis();

      //Serial.print(mag_valuex);Serial.print(','); Serial.print(mag_valuey);Serial.print(',');Serial.println(mag_valuez);
    }
  }
}
