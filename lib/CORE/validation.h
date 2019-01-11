/**
 * DO NOT MODIFY THIS FILE
*/
#ifndef VALIDATION_H_
#define VALIDATION_H_
#include <Arduino.h>
#if !defined(THERMOSTAT_MODE_HEAT) && !defined(THERMOSTAT_MODE_COOL) && !defined(THERMOSTAT_MODE_FAN)
#error "You must define THERMOSTAT_MODE_HEAT, THERMOSTAT_MODE_COOL and/or THERMOSTAT_MODE_FAN in configuration.h"
#endif
// WiFi Settings
#if !defined(WIFI_SSID)
#error "You must define WIFI_SSID in configuration.h"
#endif
#if !defined(WIFI_PASS)
#error "You must define WIFI_PASS in configuration.h"
#endif

// Debug Settings
#if defined(DEBUG_ENABLED) && !defined(SERIAL_BAUD)
#error "You must define SERIAL_BAUD in configuration.h"
#endif

// MQTT Settings
#if !defined(MQTT_HOST)
#error "You must define MQTT_HOST in configuration.h"
#endif
#if !defined(MQTT_PORT)
#error "You must define MQTT_PORT in configuration.h"
#elif (MQTT_PORT <= 0 || MQTT_PORT >= 65535)
#error "MQTT_PORT must be a number between 1 and 65534 in configuration.h"
#endif
#if !defined(MQTT_USER)
#error "You must define MQTT_USER in configuration.h"
#endif
#if !defined(MQTT_PASS)
#error "You must define MQTT_PASS in configuration.h"
#endif
#if !defined(MQTT_WILL_ONLINE)
#error "You must define MQTT_WILL_ONLINE in configuration.h"
#endif
#if !defined(MQTT_WILL_OFFLINE)
#error "You must define MQTT_WILL_OFFLINE in configuration.h"
#endif
#if !defined(MQTT_QOS)
#error "You must define MQTT_QOS in configuration.h"
#elif (MQTT_QOS != 0 && MQTT_QOS != 1 && MQTT_QOS != 2)
#error "MQTT_QOS must be either 0, 1 or 2 in configuration.h"
#endif
#if !defined(MQTT_RETAIN)
#error "You must define MQTT_RETAIN in configuration.h"
#elif (MQTT_RETAIN != true && MQTT_RETAIN != false)
#error "MQTT_RETAIN must be either true or false in configuration.h"
#endif
#if !defined(MQTT_CLEAN_SESSION)
#error "You must define MQTT_CLEAN_SESSION in configuration.h"
#elif (MQTT_CLEAN_SESSION != true && MQTT_CLEAN_SESSION != false)
#error "MQTT_CLEAN_SESSION must be either true or false in configuration.h"
#endif
#if !defined(MQTT_DISCOVERY_PREFIX)
#error "You must define MQTT_DISCOVERY_PREFIX in configuration.h"
#endif
#if !defined(MQTT_STATE_ON)
#error "You must define MQTT_STATE_ON in configuration.h"
#endif
#if !defined(MQTT_STATE_OFF)
#error "You must define MQTT_STATE_OFF in configuration.h"
#endif

// Relay Settings
#if !defined(RELAY_ACTIVE)
#error "You must define RELAY_ACTIVE in configuration.h"
#elif (RELAY_ACTIVE != HIGH && RELAY_ACTIVE != LOW)
#error "RELAY_ACTIVE must be either HIGH or LOW in configuration.h"
#endif

// OTA Settings
#if defined(OTA_ENABLED) && !defined(OTA_PORT)
#error "You must define OTA_PORT in configuration.h"
#endif
#if defined(OTA_ENABLED) && !defined(OTA_PASS)
#error "You must define OTA_PASS in configuration.h"
#endif
#endif // VALIDATION_H_
