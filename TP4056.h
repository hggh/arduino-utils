#include <Arduino.h>

#ifndef TP4056_h
#define TP4056_h

class TP4056 {
  public:
    void init(uint8_t pin_usb_power, uint8_t pin_chrg, uint8_t pin_stdby);
    bool has_usb_power(void);
    int state(void);
    uint8_t NO_POWER = 1;
    uint8_t CHARGING = 2;
    uint8_t CHARGED = 3;
  private:
    void setup(void);
    uint8_t pin_usb_power;
    uint8_t pin_chrg;
    uint8_t pin_stdby;
};
#endif
