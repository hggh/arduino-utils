#include <Arduino.h>
#include "ShiftOutRegister.h"

#ifndef Light_h
#define Light_h

class Light {
  public:
    void begin(uint8_t light_pin);
    void begin(uint8_t light_pin, ShiftOutRegister *sh_register);
    void on(void);
    void off(void);
  private:
    boolean shiftout = false;
    uint8_t pin;
    ShiftOutRegister *sh_register;
};
#endif
