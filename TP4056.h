#include <Arduino.h>

#ifndef TP4056_h
#define TP4056_h

class TP4056 {
  public:
    void init(uint8_t pin_usb_power, uint8_t pin_chrg, uint8_t pin_stdby);
    void init(uint8_t pin_chrg, uint8_t pin_stdby);
    void set_pullup(void);
    void setup(void);
    bool has_usb_power(void);
    bool is_charging(void);
    bool is_charged(void);
  private:
    bool pullup = false;
    uint8_t pin_usb_power = 0;
    uint8_t pin_chrg;
    uint8_t pin_stdby;
};
#endif
