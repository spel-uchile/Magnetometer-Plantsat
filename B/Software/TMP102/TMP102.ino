#include <Wire.h> // Used to establied serial communication on the I2C bus
int tmp102Address1 = 0x48;
int tmp102Address2 = 0x49;

void setup(){
Serial.begin(115200);
Wire.begin();
}

void loop(){                                                                                                                                                                                                                                                                                                                                                                                                                                                                                

float celsius1 = getTemperature(tmp102Address1);
float celsius2 = getTemperature(tmp102Address2);
Serial.print(celsius1); Serial.print(',');
Serial.println(celsius2);

delay(200); //just here to slow down the output. You can remove this
}

float getTemperature(int tmp){
Wire.requestFrom(tmp,2);

byte MSB = Wire.read();
byte LSB = Wire.read();

//it’s a 12bit int, using two’s compliment for negative
int TemperatureSum = ((MSB << 8) | LSB) >> 4;

float celsius = TemperatureSum*0.0625;
return celsius;
}
