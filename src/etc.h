#include <Arduino.h>
#include <HTTPClient.h>
#include "FS.h"
const char *ssid = "POCOPHONE";
const char *password = "a1b2c3d4";

void Connect_Wifi()
{
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi");
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.print("OK! IP=");
    Serial.println(WiFi.localIP());
}