#include <Arduino.h>


void setup(){

    Serial.begin(9600);
    while(!Serial){;}

    pinMode(LED_GREEN, OUTPUT);
    Serial.printf("helloWorld\n");
}

void loop(void){

  int sensorValue = analogRead(PA0);
  // print out the value you read:
  Serial.println(sensorValue);

    delay(500);
    digitalWrite(LED_GREEN,HIGH);
    delay(500);
    digitalWrite(LED_GREEN,LOW);
}