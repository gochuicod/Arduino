#include <MQ2.h> // Library from github that calculates the values of each gas from the graph
#include <ArduinoJson.h> // Library that converts string to JSON

MQ2 mq2(A0);

void setup() {
  Serial.begin(9600);
  mq2.begin();
}

void loop() {
  int sensorValue = analogRead(A0);

  float lpg = mq2.readLPG(), co = mq2.readCO(), smoke = mq2.readSmoke();

  StaticJsonDocument<200> jsonDoc;
  jsonDoc["lpg"] = lpg;
  jsonDoc["co"] = co;
  jsonDoc["smoke"] = smoke;

  String jsonString;
  serializeJson(jsonDoc,jsonString);

  Serial.println(jsonString);

  delay(1000);
}
