/**
 * DO NOT MODIFY THIS FILE
*/
#ifndef RELAY_H_
#define RELAY_H_
#include <Arduino.h>
class RELAY
{
public:
  void setup(uint8_t);
  void setActiveState(bool);
  bool on();
  bool off();
  bool isActive();
  unsigned long getStartTime();
  unsigned long getStopTime();

private:
  bool active_state;
  bool active;
  unsigned long start;
  unsigned long stop;
  uint8_t pin;
};
#endif // RELAY_H_