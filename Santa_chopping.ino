#include "func.h"

void setup() {
  neck_S.attach(neck);
  neck_S.write(z_deg);
  
  pinMode(arms, OUTPUT);

  chopping = false;
  started_chopping = millis();

  Serial.begin(9600);
}

void loop() {
  if (!chopping && millis() - started_chopping < chop_time){
    digitalWrite(arms, HIGH);
    chopping = true;
  }
  else if (chopping && millis() - started_chopping > chop_time){
    digitalWrite(arms, LOW);
    chopping = false;
    delay(1000);
  }
  else if (millis() - started_chopping > chop_time + pause_time){
    started_chopping = millis();
  }
}
