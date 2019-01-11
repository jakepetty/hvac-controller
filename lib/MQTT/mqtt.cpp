/**
 * DO NOT MODIFY THIS FILE
*/
#include <mqtt.h>
MQTT::MQTT() : client(espClient)
{
}
void MQTT::setup()
{
    client.setServer(MQTT_HOST, MQTT_PORT);
}
#ifdef THERMOSTAT_MODE_HEAT
void MQTT::setupHeat()
{

    DynamicJsonBuffer buffer;
    JsonObject &data = buffer.createObject();
    // HEATING
    data["name"] = "heat_" + MQTT_DEVICE_NAME;
    data["command_topic"] = MQTT_HEATING_COMMAND_TOPIC;
    data["state_topic"] = MQTT_HEATING_STATE_TOPIC;
    data["availability_topic"] = MQTT_AVAILABILITY_TOPIC;
    data["state_on"] = MQTT_STATE_ON;
    data["state_off"] = MQTT_STATE_OFF;
    data["payload_on"] = MQTT_STATE_ON;
    data["payload_off"] = MQTT_STATE_OFF;
    data["retain"] = MQTT_RETAIN;
    data["qos"] = MQTT_QOS;

    String config;
    data.printTo(config);
    if (client.publish(MQTT_HEATING_CONFIG_TOPIC.c_str(), config.c_str(), MQTT_RETAIN)) // Publish Discoery Configuration
    {
        DEBUG_PRINT(F("[OK] heater: switch.heating"), false);
        DEBUG_PRINT(MQTT_DEVICE_NAME, false);
        DEBUG_PRINT(F(" has been setup"), true);
        DEBUG_PRINT(F("[OK] Published to: "), false);
    }
    else
    {
        DEBUG_PRINT(F("[ERROR] Unable to publish to: "), false);
    }
    DEBUG_PRINT(MQTT_HEATING_CONFIG_TOPIC, true);

    if (client.subscribe(MQTT_HEATING_COMMAND_TOPIC.c_str(), MQTT_QOS)) // Subscribe to Command Topic
    {
        DEBUG_PRINT(F("[OK] Subscribed to: "), false);
    }
    else
    {
        DEBUG_PRINT(F("[ERROR] Unable to subscribe to: "), false);
    }
    DEBUG_PRINT(MQTT_HEATING_COMMAND_TOPIC, true);
}
#endif
#ifdef THERMOSTAT_MODE_COOL
void MQTT::setupCool()
{
    DynamicJsonBuffer buffer;
    JsonObject &data = buffer.createObject();
    // COOLING
    data["name"] = "cool_" + MQTT_DEVICE_NAME;
    data["command_topic"] = MQTT_COOLING_COMMAND_TOPIC;
    data["state_topic"] = MQTT_COOLING_STATE_TOPIC;
    data["availability_topic"] = MQTT_AVAILABILITY_TOPIC;
    data["state_on"] = MQTT_STATE_ON;
    data["state_off"] = MQTT_STATE_OFF;
    data["payload_on"] = MQTT_STATE_ON;
    data["payload_off"] = MQTT_STATE_OFF;
    data["retain"] = MQTT_RETAIN;
    data["qos"] = MQTT_QOS;

    String config;
    data.printTo(config);
    if (client.publish(MQTT_COOLING_CONFIG_TOPIC.c_str(), config.c_str(), MQTT_RETAIN)) // Publish Discoery Configuration
    {
        DEBUG_PRINT(F("[OK] cooler: switch.cooling"), false);
        DEBUG_PRINT(MQTT_DEVICE_NAME, false);
        DEBUG_PRINT(F(" has been setup"), true);
        DEBUG_PRINT(F("[OK] Published to: "), false);
    }
    else
    {
        DEBUG_PRINT(F("[ERROR] Unable to publish to: "), false);
    }
    DEBUG_PRINT(MQTT_COOLING_CONFIG_TOPIC, true);

    if (client.subscribe(MQTT_COOLING_COMMAND_TOPIC.c_str(), MQTT_QOS)) // Subscribe to Command Topic
    {
        DEBUG_PRINT(F("[OK] Subscribed to: "), false);
    }
    else
    {
        DEBUG_PRINT(F("[ERROR] Unable to subscribe to: "), false);
    }
    DEBUG_PRINT(MQTT_COOLING_COMMAND_TOPIC, true);
}
#endif
#ifdef THERMOSTAT_MODE_FAN
void MQTT::setupFan()
{

    DynamicJsonBuffer buffer;
    JsonObject &data = buffer.createObject();
    // COOLING
    data["name"] = "fan_" + MQTT_DEVICE_NAME;
    data["command_topic"] = MQTT_FAN_COMMAND_TOPIC;
    data["state_topic"] = MQTT_FAN_STATE_TOPIC;
    data["availability_topic"] = MQTT_AVAILABILITY_TOPIC;
    data["state_on"] = MQTT_STATE_ON;
    data["state_off"] = MQTT_STATE_OFF;
    data["payload_on"] = MQTT_STATE_ON;
    data["payload_off"] = MQTT_STATE_OFF;
    data["retain"] = MQTT_RETAIN;
    data["qos"] = MQTT_QOS;

    String config;
    data.printTo(config);
    if (client.publish(MQTT_FAN_CONFIG_TOPIC.c_str(), config.c_str(), MQTT_RETAIN)) // Publish Discoery Configuration
    {
        DEBUG_PRINT(F("[OK] cooler: switch.fan"), false);
        DEBUG_PRINT(MQTT_DEVICE_NAME, false);
        DEBUG_PRINT(F(" has been setup"), true);
        DEBUG_PRINT(F("[OK] Published to: "), false);
    }
    else
    {
        DEBUG_PRINT(F("[ERROR] Unable to publish to: "), false);
    }
    DEBUG_PRINT(MQTT_FAN_CONFIG_TOPIC, true);

    if (client.subscribe(MQTT_FAN_COMMAND_TOPIC.c_str(), MQTT_QOS)) // Subscribe to Command Topic
    {
        DEBUG_PRINT(F("[OK] Subscribed to: "), false);
    }
    else
    {
        DEBUG_PRINT(F("[ERROR] Unable to subscribe to: "), false);
    }
    DEBUG_PRINT(MQTT_FAN_COMMAND_TOPIC, true);
}
#endif
bool MQTT::run()
{
    bool connected = client.connected();
    if (!connected)
    {
        if (client.connect(MQTT_DEVICE_NAME.c_str(), MQTT_USER, MQTT_PASS, MQTT_AVAILABILITY_TOPIC.c_str(), MQTT_QOS, MQTT_RETAIN, MQTT_WILL_OFFLINE, MQTT_CLEAN_SESSION))
        {
            DEBUG_PRINT(F("[OK] Connected to MQTT Server"), true);
            if (!client.publish(MQTT_AVAILABILITY_TOPIC.c_str(), MQTT_WILL_ONLINE, MQTT_RETAIN))
            {
                DEBUG_PRINT(F("[ERROR] Unable to publish to: "), false);
                DEBUG_PRINT(MQTT_AVAILABILITY_TOPIC, true);
            }
// Setup MQTT Discovery Configurations
#ifdef THERMOSTAT_MODE_HEAT
            setupHeat();
#endif
#ifdef THERMOSTAT_MODE_COOL
            setupCool();
#endif
#ifdef THERMOSTAT_MODE_FAN
            setupFan();
#endif
        }
        else
        {
            DEBUG_PRINT(F("[ERROR] Unable to connect to MQTT Server"), true);
        }
    }
    client.loop();
    return connected;
}