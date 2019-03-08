#include <Arduino.h>
#include "ShiftOutRegister.h"

#ifndef Shutter_h
#define Shutter_h

#define OPERATION_NOPOWER 0
#define OPERATION_UP 1
#define OPERATION_DOWN 2

class Shutter {
  public:
    void begin (uint8_t power, uint8_t updown, uint8_t seconds);
    void begin (uint8_t power, uint8_t updown, uint8_t seconds, ShiftOutRegister *sh_register);
    void power_down(void);
    void complete_power_down(void);
    void timer(void);
    void activate_timer(void);
    void up(void);
    void down(void);
    void halt(void);
  private:
    ShiftOutRegister *sh_register;
    boolean shiftout = false;
    uint8_t pin_power;
    uint8_t pin_updown;
    uint8_t running_seconds;
    uint8_t timer_active = 0;
    uint8_t timer_run = 0;
    volatile short operation = OPERATION_NOPOWER;
};
#endif
