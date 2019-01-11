/**
 * DO NOT MODIFY THIS FILE
*/
#ifndef DEVICE_H_
#define DEVICE_H_

#include <helpers.h>
#include <ArduinoJson.h>
#include <configuration.h>
#include <extern.h>
#include <wifi.h>
#include <hvac.h>

class DEVICE
{
public:
  void setup();
  void run();

private:
  WIFI wifi;
  HVAC hvac;
  void mqttCallback(char *topic, byte *payload, unsigned int length);
};
#endif
