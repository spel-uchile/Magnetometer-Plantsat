/* RM3100 Library
 *  Space and Planetary Laboratory, SPEL, University of Chile
 *  Developed By Cris Garrido, July 2021
 *  This library work in both, SPI and I2C Bus
 *                   ----------------------------------------
 *                  /                                        |
 *  SCLK/SCL   --> |CLK-SPI/SCL-I2C           Digital Ground |<-- DVSS
 *  SO / ADDR1 --> |MISO-SPI/ADDR1-I2C    Analog Power (3V3) |<-- AVVD
 *  SI / SDA   --> |MOSI-SPI/SDA-I2C      Dogital Power (3V3)|<-- DVDD
 *  SSN/ ADDR0 --> |SS-I2C/ADDR0-I2C                         | <-- NC
 *  DRDY       --> |1 Measurement                0-SPI/1-I2C | <-- I2C EN
 *  NC         --> |                                         | <-- NC
 *  AVSS       --> |Analog Ground      ^                     | <-- NC
 *                 |PNI                N               RM3100|
 *                  -----------------------------------------
 */

#include <Wire.h>
#include <SPI.h>
#include <PNI_RM3100.h>

#define MAG_SCK  (9)
#define MAG_MISO (10)
#define MAG_MOSI (8)
#define MAG_CS   (5)

byte beg;

int ccx = 800; /**< Count Cycles for x sensor measurement. It must be between 30 an 400 (default 200) */
int ccy = 800; /**< Count Cycles for y sensor measurement. It must be between 30 an 400 (default 200) */
int ccz = 800; /**< Count Cycles for z sensor measurement. It must be between 30 an 400 (default 200) */

PNI_RM3100 mag; // I2C
//PNI_RM3100 mag(MAG_CS); // hardware SPI
//PNI_RM3100 mag(MAG_CS, MAG_MOSI, MAG_MISO,  MAG_SCK);

void setup() {

  Serial.begin(115200);
  while(!Serial);
  delay(500);
  Serial.println(F("RM3100 test"));

  //if (!mag.begin(PNI_RM3100::RM3100_ADDRESS_ALT)) {  /*I2C Address SA0 High SA1 Low    0x21 */
  //if (!mag.begin(PNI_RM3100::RM3100_ADDRESS_ALT2)) { /*I2C Address SA0 Low SA1 High    0x22 */
  //if (!mag.begin(PNI_RM3100::RM3100_ADDRESS_ALT3)) { /*I2C Address SA0 High SA1 High   0x23 */
  if (!mag.begin()) { /*I2C Address SA0 Low SA1 Low  0x20 */
    Serial.println(F("Could not find a valid RM3100 sensor, check wiring or "
                     "try a different address!"));
    while (1) delay(10);
  }

  Serial.println("RM_3100 connceted");
  /* Default settings from datasheet. */
  mag.setSampling(PNI_RM3100::MODE_CMMXYZ,     /* Operating Mode. MODE_SINGLE MODE_CMMXYZ MODE_CMMX MODE_CMMY MODE_CMMZ*/
                  PNI_RM3100::TMRC_37HZ,     /* Max frequency */
                  ccx,    /**< Count Cycles for x sensor measurement. It must be between 30 an 400 (default 200) */
                  ccy,    /**< Count Cycles for y sensor measurement. It must be between 30 an 400 (default 200) */
                  ccz);   /**< Count Cycles for z sensor measurement. It must be between 30 an 400 (default 200) */
}

void loop() {
  bool checking;
  RM3100_measurements data;
  // put your main code here, to run repeatedly:
  checking = mag.check_masurement();
  //Serial.println(checking);
  if (checking)
  {
    data = mag.readMagneticField();
    Serial.print(data.mag_x); Serial.print(",");
    Serial.print(data.mag_y); Serial.print(",");
    Serial.println(data.mag_z);
  }
}
