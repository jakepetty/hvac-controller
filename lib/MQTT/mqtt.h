/**
 * DO NOT MODIFY THIS FILE
*/
#ifndef MQTT_H_
#define MQTT_H_

#pragma GCC diagnostic ignored "-Waddress"
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <configuration.h>
#include <ArduinoJson.h>
#include <helpers.h>
#include <discovery.h>
class MQTT : PubSubClient
{
public:
  MQTT();
  void setup();
  bool run();
  WiFiClient espClient;
  PubSubClient client;

private:
#ifdef THERMOSTAT_MODE_HEAT
  void setupHeat();
#endif
#ifdef THERMOSTAT_MODE_COOL
  void setupCool();
#endif
#ifdef THERMOSTAT_MODE_FAN
  void setupFan();
#endif
};
#endif // MQTT_H_