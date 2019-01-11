/**
 * DO NOT MODIFY THIS FILE
*/
#ifndef GLOBALS_H
#define GLOBALS_H
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <configuration.h>

// Generates a unique ID using devices MAC Address
static const char *getUniqueID()
{
    String callback = WiFi.macAddress(); // Format: XX:XX:XX:XX:XX:XX
    callback.replace(":", "");           // Converts XX:XX:XX:XX:XX:XX to XXXXXXXXXXXX
    callback.toLowerCase();              // Converts XXXXXXXXXXXX to xxxxxxxxxxxx
    return callback.c_str();             // Returns xxxxxxxxxxxx
}

#pragma GCC diagnostic ignored "-Wunused-function"

// Debugging functions
#ifdef DEBUG_ENABLED
#define DEBUG_PRINT(a, b) b ? Serial.println(a) : Serial.print(a)
#else
#define DEBUG_PRINT(a, b)
#endif

// MQTT Payload to String converter
static String payload2string(byte *payload, unsigned int len)
{
    payload[len] = '\0';
    return String((char *)payload);
}
// Translated thermostat modes
#define MODE_OFF 0x00
#define MODE_COOL 0x01
#define MODE_HEAT 0x02
#define MODE_FAN 0x03
#endif // GLOBALS_H
