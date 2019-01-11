/**
 * DO NOT MODIFY THIS FILE
*/
#include "relay.h"
void RELAY::setup(uint8_t _pin)
{
    pin = _pin;
    pinMode(_pin, OUTPUT);
}
void RELAY::setActiveState(bool _state)
{
    active_state = _state;
    digitalWrite(pin, !_state);
}
bool RELAY::on()
{
    if (!isActive())
    {
        active = true;
        digitalWrite(pin, active_state);
        start = millis();
        return true;
    }
    return false;
}
bool RELAY::off()
{
    if (isActive())
    {
        active = false;
        digitalWrite(pin, !active_state);
        stop = millis();
        return true;
    }
    return false;
}
bool RELAY::isActive()
{
    return active;
}
unsigned long RELAY::getStartTime()
{
    return start;
}
unsigned long RELAY::getStopTime()
{
    return stop;
}