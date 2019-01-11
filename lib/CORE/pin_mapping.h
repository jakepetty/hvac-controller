/**
 * This file defines what pins to use for the relays modify it as needed
*/

#ifndef PIN_MAPPING_H_
#define PIN_MAPPING_H_
#include <configuration.h>

// Relay Pin For Heat
#ifdef THERMOSTAT_MODE_HEAT
#define PIN_HEAT D5
#endif

// Relay Pin For AC
#ifdef THERMOSTAT_MODE_COOL
#define PIN_COOL D6
#endif

// Relay Pin For Fan
#ifdef THERMOSTAT_MODE_FAN
#define PIN_FAN D7
#endif

#endif // PIN_MAPPING_H_