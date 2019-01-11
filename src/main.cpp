#include <Arduino.h>
#include <device.h>
#include <validation.h>
#include <mqtt.h>
#include <extern.h>
// Setup global variables
MQTT *mqtt = new MQTT();
DEVICE device;

void setup()
{
    // put your setup code here, to run once:
    device.setup();
}
void loop()
{
    // put your main code here, to run repeatedly:
    device.run();
}