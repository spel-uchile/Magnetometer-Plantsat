/*
   There are three serial ports on the ESP known as U0UXD, U1UXD and U2UXD.

   U0UXD is used to communicate with the ESP32 for programming and during reset/boot.
   U1UXD is unused and can be used for your projects. Some boards use this port for SPI Flash access though
   U2UXD is unused and can be used for your projects.

*/

#include "Arduino.h"
#include "FS.h"
#include "SD.h"
#include "SPI.h"

#define RXD2 16
#define TXD2 17

uint32_t freq = 1000000;

void writeFile(fs::FS &fs, const char * path) {
  long msec = millis();
  Serial.printf("Deleting file: %s\n", path);
  if (fs.remove(path)) {
    Serial.println("File deleted");
  } else {
    Serial.println("Delete failed");
  }
  Serial.printf("Writing file: %s\n", path);

  File file = fs.open(path, FILE_WRITE);
  if (!file) {
    Serial.println("Failed to open file in writing mode");
  }
  msec = millis();
  while (1)
  {
    if  (Serial2.available())
    {
      file.write(Serial2.read()); // payload (image), payload length
      msec = millis();
    }
    else if (millis() - msec > 1000)
    {
      break;
    }
  }
  //file.write(fb->buf, fb->len); // payload (image), payload length
  Serial.println("Saved");

  file.close();
}

void setup() {
  // Note the format for setting a serial port is as follows: Serial2.begin(baud-rate, protocol, RX pin, TX pin);

  Serial.begin(115200);
  //Serial1.begin(9600, SERIAL_8N1, RXD2, TXD2);
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);
  Serial.println("Serial Txd is on pin: " + String(TX));
  Serial.println("Serial Rxd is on pin: " + String(RX));

  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);

  digitalWrite(2, HIGH);
  digitalWrite(5, HIGH);



}

void loop()
{ //Choose Serial1 or Serial2 as required
  int option;
  int len;
  int width;
  int height;
  int format;

  //  Serial.println("Select Option");
  //  option = Serial.parseInt();
  //  //Serial.println(option);
  //  while (1)
  //  {
  //    if (Serial.available())
  //    {
  //      if (option == 1)
  //      {
  //        Serial2.write("1");
  //      }
  //      else if (option == 2)
  //      {
  //        Serial2.write("2");
  //      }
  //      else if (option == 3)
  //      {
  //        Serial2.write("3");
  //      }
  //      else if (option == 4)
  //      {
  //        Serial2.write("4");
  //      }
  //      else if (option == 5)
  //      {
  //        Serial2.write("5");
  //      }
  //      else if (option == 6)
  //      {
  //        Serial2.write("6");
  //      }
  //      break;
  //    }
  //  }
  //
  //  while (1)
  //  {
  //    while (Serial2.available())
  //    {
  //      //Serial.println(Serial2.available());
  //      Serial.write(char(Serial2.read()));
  //    }
  //    break;
  //  }

  long millisec = millis();

  Serial2.write("1");   // read it and send it out Serial1 (pins 0 & 1)
  delay(1000);
  Serial2.write("2");   // read it and send it out Serial1 (pins 0 & 1)
  while (1)
  {
    if  (Serial2.available())
    {
      len = Serial2.parseInt();
      break;
    }


  }
  Serial.print("len : ");
  Serial.println(len);
  Serial2.write("3");   // read it and send it out Serial1 (pins 0 & 1)
  while (1)
  {
    if  (Serial2.available())
    {
      width = Serial2.parseInt();
      break;
    }

  }
  Serial.print("width : ");
  Serial.println(width);

  Serial2.write("4");   // read it and send it out Serial1 (pins 0 & 1)
  while (1)
  {
    if  (Serial2.available())
    {
      height = Serial2.parseInt();
      break;
    }

  }
  Serial.print("height : ");
  Serial.println(height);

  Serial2.write("5");   // read it and send it out Serial1 (pins 0 & 1)
  while (1)
  {
    if  (Serial2.available())
    {
      format = Serial2.parseInt();
      break;
    }

  }
  Serial.print("format : ");
  Serial.println(format);

  if (!SD.begin(4, SPI, freq)) {
    Serial.println("Card Mount Failed");
    return;
  }

  Serial2.write("6");   // read it and send it out Serial1 (pins 0 & 1)
  writeFile(SD, "/foto.jpg");

  //  while (1)
  //  {
  //    if  (Serial2.available())
  //    {
  //      nbyte = Serial2.readBytes(buf, len);
  //      break;
  //    }
  //
  //  }
  //  Serial.print("number of bytes: ");
  //  Serial.println(nbyte);
  Serial2.write("7");   // read it and send it out Serial1 (pins 0 & 1)
  SD.end();
  //Serial2.end();
  Serial.println("end");
  

  while (1)
  {
    if (Serial.available()) {      // If anything comes in Serial (USB),
      option = Serial.read();
      if (option == 56)
      {
        break;
      }
      Serial2.write(option);   // read it and send it out Serial1 (pins 0 & 1)
      millisec = millis();
    }

    else if (Serial2.available()) {     // If anything comes in Serial1 (pins 0 & 1)
      Serial.write(Serial2.read());   // read it and send it out Serial (USB)
      millisec = millis();
    }
  }
}
