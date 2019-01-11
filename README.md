# Home Assistant Thermostat Controller
The goal of this project is to control your Heating, Cooling and Blower with one device. This device does not contain a display of any kind it is just a controller. There is a custom thermostat component included that is a modified version of the Generic Thermostat provided by Home Assistant. It allows for both heating and cooling functionality within then same thermostat. This eliminates the need of having multiple themrostats in Home Assistant. This project utilizes MQTT Discovery to automatically setup each switch inside of Home Assistant making the setup and configuration effortless.

**Note:** I will not go into detail on how to connect anything since theres only 5 wires involved and they're all self explainitary. I also will not help with connecting the relay to your HVAC system since not all HVACs are the same.

## Hardware Requirements
This project uses the following parts:
- NodeMCU v1.0 DevKit ($3)
- Up to 3 Relays (~$0.99 each) [3-channel relay](https://www.ebay.com/itm/3-Channel-Relay-Module-5mA-With-Optocoupler-Isolation-Compatible-Signal-3-3V-5V/172451908112) prefered ~$5
- A 5v power supply

## Features
- OTA Programming
- Reliable WiFi (reconnects on disconnect)
- Fan Mode
- Heat Mode
- Cool Mode

## Prerequisites
- [VSCode](https://code.visualstudio.com/) with [PlatformIO](https://docs.platformio.org/en/latest/ide/vscode.html#installation) extension installed
- You MUST have at least one temperature sensor already set up and working inside Home Assistant
- You MUST have [MQTT Discovery](https://www.home-assistant.io/docs/mqtt/discovery/) configured
- Basic understanding of how your HVAC system is wired

## Preperations
- Rename `lib/CORE/configuration.h.default` to `lib/CORE/configuration.h`
- Rename `platformio.ini.default` to `platformio.ini`
- Open `platformio.ini` and change `upload_port` to the COM port used by your ESP
- Open `lib/CORE/configuration.h` and change settings as needed
- Open `lib/CORE/pin_mapping.h`
- Change pins as needed
- Move `enhanced_generic_thermostat.py` to `HA_CONFIG_FOLDER/custom_component/climate/enhanced_generic_thermostat.py`

## Component Setup
Insert the YAML snippet into your HA configuration file. Make changes to suit your needs. Replace heater and cooler values with the devices listed in the serial console output. Replace the sensor value with the entity id of your temperature sensor.

```yaml
climate:
  - platform: enhanced_generic_thermostat
    name: Thermostat
    heater: REPLACE_THIS
    cooler: REPLACE_THIS
    target_sensor: REPLACE_THIS
    min_temp: 60
    max_temp: 85
    target_temp: 70
    away_temp: 70
    initial_operation_mode: "off"
    hot_tolerance: 0.5
    cold_tolerance: 0.5
    min_cycle_duration:
      minutes: 2
```

## Device Configuration
See `lib/CORE/configuration.h`

## Switch Removal
If you enabled all switches while testing but nolonger need them all, send an empty retained MQTT payload the switch you no longer need:
- `MQTT_DISCOVERY_PREFIX/switch/fan_xxxxxxxxxxxx/config`
- `MQTT_DISCOVERY_PREFIX/switch/cool_xxxxxxxxxxxx/config`
- `MQTT_DISCOVERY_PREFIX/switch/heat_xxxxxxxxxxxx/config`

Replace the `xxxxxxxxxxxx` with the ESP's lowercase mac address without the colons and replace `MQTT_DISCOVERY_PREFIX` with the MQTT Discovery Prefix you set inside `configuration.h`