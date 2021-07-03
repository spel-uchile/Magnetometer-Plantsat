/*
   There are three serial ports on the ESP known as U0UXD, U1UXD and U2UXD.

   U0UXD is used to communicate with the ESP32 for programming and during reset/boot.
   U1UXD is unused and can be used for your projects. Some boards use this port for SPI Flash access though
   U2UXD is unused and can be used for your projects.

*/

#define RXD2 16
#define TXD2 17

void setup() {
  // Note the format for setting a serial port is as follows: Serial2.begin(baud-rate, protocol, RX pin, TX pin);
  Serial.begin(115200);
  //Serial1.begin(9600, SERIAL_8N1, RXD2, TXD2);
  Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);
  Serial.println("Serial Txd is on pin: " + String(TX));
  Serial.println("Serial Rxd is on pin: " + String(RX));
}

void loop()
{ //Choose Serial1 or Serial2 as required
  //  int option;
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
  if (Serial.available()) {      // If anything comes in Serial (USB),
    Serial2.write(Serial.read());   // read it and send it out Serial1 (pins 0 & 1)
  }

  else if (Serial2.available()) {     // If anything comes in Serial1 (pins 0 & 1)
    Serial.println(millis());
    Serial.write(Serial2.read());   // read it and send it out Serial (USB)
    Serial.println(millis());
  }

}
