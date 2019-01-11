/**
 * DO NOT MODIFY THIS FILE
*/
#include "device.h"

void DEVICE::setup()
{
#ifdef DEBUG_ENABLED
    Serial.begin(SERIAL_BAUD);
    Serial.println(); // Inserts a new line for a clearner terminal
    delay(5000);      // Timeout to give the serial monitor time to connect
#endif

    // Setup Components
    hvac.setup();
    wifi.setup();
    mqtt->setup();

    // Setup MQTT Callback Function (Don't touch)
    mqtt->client.setCallback([this](char *_topic, byte *_payload, unsigned int _length) {
        mqttCallback(_topic, _payload, _length);
    });
}
void DEVICE::mqttCallback(char *_topic, byte *_payload, unsigned int _length)
{
    // Convert payload to a string
    String callback = payload2string(_payload, _length);
#ifdef THERMOSTAT_MODE_HEAT
    if (strcmp(_topic, MQTT_HEATING_COMMAND_TOPIC.c_str()) == 0) // Heating state change request
    {
        // Convert payload to an integer
        bool state = callback == MQTT_STATE_ON;
        // Set HVAC mode
        hvac.setMode(MODE_HEAT);
        // Set HVAC state
        hvac.setState(state);
    }
#endif
#ifdef THERMOSTAT_MODE_COOL
    if (strcmp(_topic, MQTT_COOLING_COMMAND_TOPIC.c_str()) == 0) // Cooling state change request
    {
        // Convert payload to an integer
        bool state = callback == MQTT_STATE_ON;
        // Set HVAC mode
        hvac.setMode(MODE_COOL);
        // Set HVAC state
        hvac.setState(state);
    }
#endif
#ifdef THERMOSTAT_MODE_FAN
    if (strcmp(_topic, MQTT_FAN_COMMAND_TOPIC.c_str()) == 0) // Cooling state change request
    {
        // Convert payload to an integer
        bool state = callback == MQTT_STATE_ON;
        // Set HVAC mode
        hvac.setMode(MODE_FAN);
        // Set HVAC state
        hvac.setState(state);
    }
#endif
}

void DEVICE::run()
{
    if (wifi.run())
    {
        if (mqtt->run())
        {
            hvac.run();
        }
    }
}
