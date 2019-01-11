/**
 * DO NOT MODIFY THIS FILE
*/
#ifndef DISCOVERY_H_
#define DISCOVERY_H_
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <configuration.h>
#include <helpers.h>

// LWT Topics
const String MQTT_DEVICE_NAME = getUniqueID();
const String MQTT_AVAILABILITY_TOPIC = MQTT_DISCOVERY_PREFIX "/" + MQTT_DEVICE_NAME;

// HEAT Topics
#ifdef THERMOSTAT_MODE_HEAT
const String MQTT_HEATING_BASE = MQTT_DISCOVERY_PREFIX "/switch/heat_" + MQTT_DEVICE_NAME + "/";
const String MQTT_HEATING_CONFIG_TOPIC = MQTT_HEATING_BASE + "config";
const String MQTT_HEATING_COMMAND_TOPIC = MQTT_HEATING_BASE + "command";
const String MQTT_HEATING_STATE_TOPIC = MQTT_HEATING_BASE + "state";
#endif

// COOL Topics
#ifdef THERMOSTAT_MODE_COOL
const String MQTT_COOLING_BASE = MQTT_DISCOVERY_PREFIX "/switch/cool_" + MQTT_DEVICE_NAME + "/";
const String MQTT_COOLING_CONFIG_TOPIC = MQTT_COOLING_BASE + "config";
const String MQTT_COOLING_COMMAND_TOPIC = MQTT_COOLING_BASE + "command";
const String MQTT_COOLING_STATE_TOPIC = MQTT_COOLING_BASE + "state";
#endif

// FAN Topics
#ifdef THERMOSTAT_MODE_FAN
const String MQTT_FAN_BASE = MQTT_DISCOVERY_PREFIX "/switch/fan_" + MQTT_DEVICE_NAME + "/";
const String MQTT_FAN_CONFIG_TOPIC = MQTT_FAN_BASE + "config";
const String MQTT_FAN_COMMAND_TOPIC = MQTT_FAN_BASE + "command";
const String MQTT_FAN_STATE_TOPIC = MQTT_FAN_BASE + "state";
#endif
#endif // DISCOVERY_H_