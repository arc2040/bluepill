#include <Arduino.h>

#define ANALOG_PIN PA0
#define PWN_PIN PA1
void setup(){

    Serial.begin(9600);
    while(!Serial){;}

    pinMode(LED_GREEN, OUTPUT);
    Serial.printf("helloWorld\n");
}

void loop(void){

    analogWrite(PWN_PIN,50);

  int sensorValue = analogRead(ANALOG_PIN);
  // print out the value you read:
  Serial.println(sensorValue/4);

    delay(500);
    digitalWrite(LED_GREEN,HIGH);
    delay(500);
    digitalWrite(LED_GREEN,LOW);
}