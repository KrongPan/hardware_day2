#include <Arduino.h>
#include "etc.h"
#include <ArduinoJson.h>

const String baseUrl = "https://jsonplaceholder.typicode.com/";

void PUT_post(){
    String json;
    DynamicJsonDocument doc(2048);
    doc["userId"] = 1;
    doc["title"] = "Exceed AHHHHHH 22";
    doc["body"] = "THIS IS BODY XXX";
    doc["id"] = 1;
    serializeJson(doc,json);

    const String url = baseUrl + "posts/1";
    HTTPClient http;
    http.begin(url);
    http.addHeader("Content-Type","application/json");

    int httpResponseCode = http.PUT(json);
    if (httpResponseCode >= 200 && httpResponseCode < 300) {
        Serial.print("HTTP ");
        Serial.println(httpResponseCode);
    }
    else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
    }
}

void setup()
{
  Serial.begin(115200);
  Connect_Wifi();
  PUT_post();
}

void loop()
{
  // put your main code here, to run repeatedly:
}