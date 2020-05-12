// I2C Digital Potentiometer
// by Nicholas Zambetti <http://www.zambetti.com>
// and Shawn Bonkowski <http://people.interaction-ivrea.it/s.bonkowski/>

// Demonstrates use of the Wire library
// Controls AD5171 digital potentiometer via I2C/TWI

// Created 31 March 2006

// This example code is in the public domain.

// This example code is in the public domain.

#include <Arduino.h>
#include "../lib/Adafruit_ADS1X15/Adafruit_ADS1015.h"
#include <Wire.h>
// //#include "Adafruit_ADS1015.h"
// void setup()
// {
//   Wire.begin(); // join i2c bus (address optional for master)
// }

// byte val = 0;

// void loop()
// {
//   Wire.beginTransmission(44); // transmit to device #44 (0x2c)
//                               // device address is specified in datasheet
//   Wire.write(byte(0x00));            // sends instruction byte  
//   Wire.write(val);             // sends potentiometer value byte  
//   Wire.endTransmission();     // stop transmitting

//   val++;        // increment value
//   if(val == 64) // if reached 64th position (max)
//   {
//     val = 0;    // start over from lowest value
//   }
//   delay(500);
// }

Adafruit_ADS1015 ads1015;

void setup(void)
{
  Serial.begin(9600);
  Serial.println("Hello!");
  
  Serial.println("Getting single-ended readings from AIN0..3");
  Serial.println("ADC Range: +/- 6.144V (1 bit = 3mV)");
  ads1015.begin();
  //ads1015.setGain(GAIN_SIXTEEN);
}

  int16_t adc0, adc1, adc2, adc3;
void loop(void)
{

  //adc0 = ads1015.readADC_SingleEnded(0);
  //delay(1);
  adc1 = ads1015.readADC_SingleEnded(1);
  //adc2 = ads1015.readADC_SingleEnded(2);
  //adc3 = ads1015.readADC_SingleEnded(3);
  Serial.print("AIN0: "); Serial.println(adc0);
  Serial.print("AIN1: "); Serial.println(adc1);
  //Serial.print("AIN2: "); Serial.println(adc2);
  //Serial.print("AIN3: "); Serial.println(adc3);
  Serial.println(" ");
  
  delay(1000);
}