#include "Arduino.h"
#include "FS.h"
#include "SD.h"
#include "SPI.h"
//Sd2Card card;
//SdVolume vol;
//SdFile root;

// Chip select pin for SD card.
const int sdCsPin = 4;

// Replace the -1 with the CS pin number of any shared SPI device.
const int sharedCsPin = 2;
const int sharedCsPin2 = 5;

void setup() {
  Serial.begin(115200);
  
  // Disable any other SPI devices
  if (sharedCsPin >= 0) {
    pinMode(sharedCsPin, OUTPUT);
    digitalWrite(sharedCsPin, HIGH);
  }

  // Disable any other SPI devices
  if (sharedCsPin2 >= 0) {
    pinMode(sharedCsPin2, OUTPUT);
    digitalWrite(sharedCsPin2, HIGH);
  }
  
  // Try to initialize the SD card
  if (card.init(SPI_HALF_SPEED, sdCsPin)) {
    Serial.println("card init OK");
  } else {
    Serial.print("errorCode: ");
    Serial.println(card.errorCode(), HEX);
    Serial.print("errorData: ");
    Serial.println(card.errorData(), HEX);
    return;
  }
  
  // Try to initialize the FAT volume.
  if (vol.init(&card)) {
    Serial.println("vol init OK");
  } else {
    Serial.println("vol init failed");
    return;
  }
  
  // Try to open root
  if (root.openRoot(&vol)) {
    Serial.println("open root OK");
  } else {
    Serial.println("open root failed");
  }
}
void loop() {}
