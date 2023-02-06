#include <Arduino.h>
#include "etc.h"
#include <ArduinoJson.h>

const String baseUrl = "https://jsonplaceholder.typicode.com/";

void setup()
{
  Serial.begin(115200);
  Connect_Wifi();
}

void loop()
{
  // put your main code here, to run repeatedly:
}