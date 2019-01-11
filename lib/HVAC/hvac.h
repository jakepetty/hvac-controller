/**
 * DO NOT MODIFY THIS FILE
*/
#ifndef HVAC_H_
#define HVAC_H_
#include <Arduino.h>
#include <configuration.h>
#include <pin_mapping.h>
#include <discovery.h>
#include <extern.h>
#include <helpers.h>
#include <relay.h>
class HVAC
{
public:
  void setup();
  void setMode(uint8_t);
  void setState(bool);
  void run();
  void reset();
  bool isReady();

private:
  uint8_t mode;
  bool state;
#ifdef THERMOSTAT_MODE_HEAT
  RELAY heat;
#endif
#ifdef THERMOSTAT_MODE_COOL
  RELAY cool;
#endif
#ifdef THERMOSTAT_MODE_FAN
  RELAY fan;
#endif
};
#endif // HVAC_H_