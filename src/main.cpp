#include <Arduino.h>
#include "etc.h"
#include <ArduinoJson.h>

const String baseUrl = "https://jsonplaceholder.typicode.com/";

void GET_post()
{
  DynamicJsonDocument doc(2048);
  const String url = baseUrl + "posts/1";
  HTTPClient http;
  http.begin(url);
  int httpResponseCode = http.GET();

  if (httpResponseCode >= 200 && httpResponseCode < 300)
  {
    Serial.print("HTTP ");
    Serial.println(httpResponseCode);
    String payload = http.getString();
    deserializeJson(doc, payload);

    Serial.println();
    Serial.println((const char *)doc["title"]);
  }
  else
  {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
}

void setup()
{
  Serial.begin(115200);
  Connect_Wifi();
  GET_post();
}

void loop()
{
  // put your main code here, to run repeatedly:
}