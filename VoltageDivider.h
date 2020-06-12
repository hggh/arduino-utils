#include <Arduino.h>

#ifndef VoltageDivider_h
#define VoltageDivider_h

class VoltageDivider {
  public:
    void init(uint8_t pin_enable, uint8_t pin_adc);
    float get_voltage(void);
    void set_aref(float aref);
    void set_resolution(float resolution);
    void set_r1(float value_r1);
    void set_r2(float value_r2);
  private:
    void setup(void);
    void enable_divider(void);
    void disable_divider(void);
    float aref;
    float resolution;
    float value_r1;
    float value_r2;
    uint8_t pin_enable;
    uint8_t pin_adc;
};
#endif
