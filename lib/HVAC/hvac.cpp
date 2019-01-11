/**
 * DO NOT MODIFY THIS FILE
*/
#include "hvac.h"
void HVAC::setup()
{
#ifdef THERMOSTAT_MODE_HEAT
    // Setup the Heat relay
    heat.setup(PIN_HEAT);
    heat.setActiveState(RELAY_ACTIVE);
#endif
#ifdef THERMOSTAT_MODE_COOL
    // Setup the Cool relay
    cool.setup(PIN_COOL);
    cool.setActiveState(RELAY_ACTIVE);
#endif
#ifdef THERMOSTAT_MODE_FAN
    // Setup the Fan relay
    fan.setup(PIN_FAN);
    fan.setActiveState(RELAY_ACTIVE);
#endif
}
void HVAC::reset()
{
#ifdef THERMOSTAT_MODE_COOL
    cool.off();
#endif
#ifdef THERMOSTAT_MODE_HEAT
    heat.off();
#endif
#ifdef THERMOSTAT_MODE_FAN
    fan.off();
#endif
}
bool HVAC::isReady()
{
    switch (mode)
    {
    case MODE_HEAT:
        return (!cool.isActive() && !fan.isActive());
    case MODE_COOL:
        return (!heat.isActive() && !fan.isActive());
    case MODE_FAN:
        return (!heat.isActive() && !cool.isActive());
    default:
        return false;
    }
}
void HVAC::setState(bool _state)
{
    state = _state;
}
void HVAC::setMode(uint8_t _mode)
{
    mode = _mode;
}
void HVAC::run()
{
    switch (mode)
    {
#ifdef THERMOSTAT_MODE_HEAT
    case MODE_HEAT:
        if (state && isReady())
        {
            if (heat.on())
            {
                if (mqtt->client.publish(MQTT_HEATING_STATE_TOPIC.c_str(), MQTT_STATE_ON, MQTT_RETAIN)) // Send confirmation back to sender
                {
                    // Success
                    DEBUG_PRINT(F("[OK] Published to: "), false);
                }
                else
                {
                    // Error
                    DEBUG_PRINT(F("[ERROR] Publishing to: "), false);
                }
                DEBUG_PRINT(MQTT_HEATING_STATE_TOPIC, true);
            }
        }
        else
        {
            if (heat.off())
            {
                if (mqtt->client.publish(MQTT_HEATING_STATE_TOPIC.c_str(), MQTT_STATE_OFF, MQTT_RETAIN)) // Send confirmation back to sender
                {
                    // Success
                    DEBUG_PRINT(F("[OK] Published to: "), false);
                }
                else
                {
                    // Error
                    DEBUG_PRINT(F("[ERROR] Publishing to: "), false);
                }
                DEBUG_PRINT(MQTT_HEATING_STATE_TOPIC, true);
            }
        }
        break;
#endif
#ifdef THERMOSTAT_MODE_COOL
    case MODE_COOL:
        if (state && isReady())
        {
            if (cool.on())
            {
                if (mqtt->client.publish(MQTT_COOLING_STATE_TOPIC.c_str(), MQTT_STATE_ON, MQTT_RETAIN)) // Send confirmation back to sender
                {
                    // Success
                    DEBUG_PRINT(F("[OK] Published to: "), false);
                }
                else
                {
                    // Error
                    DEBUG_PRINT(F("[ERROR] Publishing to: "), false);
                }
                DEBUG_PRINT(MQTT_COOLING_STATE_TOPIC, true);
            }
        }
        else
        {
            if (cool.off())
            {
                if (mqtt->client.publish(MQTT_COOLING_STATE_TOPIC.c_str(), MQTT_STATE_OFF, MQTT_RETAIN)) // Send confirmation back to sender
                {
                    // Success
                    DEBUG_PRINT(F("[OK] Published to: "), false);
                }
                else
                {
                    // Error
                    DEBUG_PRINT(F("[ERROR] Publishing to: "), false);
                }
                DEBUG_PRINT(MQTT_COOLING_STATE_TOPIC, true);
            }
        }
        break;
#endif
#ifdef THERMOSTAT_MODE_FAN
    case MODE_FAN:
        if (state && isReady())
        {
            if (fan.on())
            {
                if (mqtt->client.publish(MQTT_FAN_STATE_TOPIC.c_str(), MQTT_STATE_ON, MQTT_RETAIN)) // Send confirmation back to sender
                {
                    // Success
                    DEBUG_PRINT(F("[OK] Published to: "), false);
                }
                else
                {
                    // Error
                    DEBUG_PRINT(F("[ERROR] Publishing to: "), false);
                }
                DEBUG_PRINT(MQTT_FAN_STATE_TOPIC, true);
            }
        }
        else
        {
            if (fan.off())
            {
                if (mqtt->client.publish(MQTT_FAN_STATE_TOPIC.c_str(), MQTT_STATE_OFF, MQTT_RETAIN)) // Send confirmation back to sender
                {
                    // Success
                    DEBUG_PRINT(F("[OK] Published to: "), false);
                }
                else
                {
                    // Error
                    DEBUG_PRINT(F("[ERROR] Publishing to: "), false);
                }
                DEBUG_PRINT(MQTT_FAN_STATE_TOPIC, true);
            }
        }
        break;
#endif
    case MODE_OFF:
        reset();
        break;
    }
}