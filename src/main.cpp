/*
  Serial Event example

  When new serial data arrives, this sketch adds it to a String.
  When a newline is received, the loop prints the string and clears it.

  A good test for this is to try it with a GPS receiver that sends out
  NMEA 0183 sentences.

  NOTE: The serialEvent() feature is not available on the Leonardo, Micro, or
  other ATmega32U4 based boards.

  created 9 May 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/SerialEvent
*/

#include <Arduino.h>
#include "../Adafruit_ADS1X15/Adafruit_ADS1015.h"

String inputString = "";         // a String to hold incoming data
bool stringComplete = false;  // whether the string is complete
Adafruit_ADS1015 ads1015;
int16_t adc;
int16_t target = 300;
int16_t temperature;
#define MOSFET_PIN PA1

void setup() {

  // MOSFET
  pinMode(MOSFET_PIN,OUTPUT);

  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
  
  Serial.println("Getting single-ended readings from AIN0..3");
  Serial.println("ADC Range: +/- 6.144V (1 bit = 3mV)");
  ads1015.begin();
  //ads1015.setGain(GAIN_SIXTEEN);
}

void loop() {
 
 // get ADC
  adc = ads1015.readADC_SingleEnded(0);
  Serial.print("AIN0: "); Serial.println(adc);

// convert ADC to temperature
 int r_sensor_inOng = 0;
 r_sensor_inOng = adc*3;
   // convert R_sensor(ong) to temperature(ceilsis)
/**
200C R_sensor = 106 (ong)
480C R_sensor = 171 (ong)
Temperature = k*R_sensor + C
k = (480-200)/(171-106) = 280/65 = 56/13 = 4+4/13 = 4.3
C = 200 -  106*4.3 = -256
So, Temperature = 4.3*R_sensor - 256
*/

int16_t target = 300; 
 temperature = r_sensor_inOng * 4.3 - 256;
  
  Serial.println(temperature,DEC);
// determin to heat or not
  if (target > temperature){
    //heat
    digitalWrite(MOSFET_PIN,LOW);
  }else{
    //stop heating
    digitalWrite(MOSFET_PIN,HIGH);
  }

  if(stringComplete == true){
    Serial.print("target set to ");
    target = inputString.toInt();
    Serial.println(target,DEC);

    // clear the string:
    inputString = "";
    stringComplete = false;
  }


}

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
