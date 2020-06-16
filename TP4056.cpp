#include "TP4056.h"

void TP4056::init(uint8_t pin_usb_power, uint8_t pin_chrg, uint8_t pin_stdby) {
  this->pin_usb_power = pin_usb_power;
  this->pin_chrg = pin_chrg;
  this->pin_stdby = pin_stdby;

  this->setup();
}

void TP4056::setup(void) {
  pinMode(this->pin_usb_power, INPUT);
  pinMode(this->pin_chrg, INPUT);
  pinMode(this->pin_stdby, INPUT);
}

bool TP4056::has_usb_power(void) {
  if (digitalRead(this->pin_usb_power) == 1) {
    return true;
  }
  return false;
}

int TP4056::state(void) {
  if (this->has_usb_power()) {
    if (digitalRead(this->pin_chrg) == 0 && digitalRead(this->pin_stdby) == 1) {
      return this->CHARGING;
    }
    if (digitalRead(this->pin_chrg) == 1 && digitalRead(this->pin_stdby) == 0) {
      return this->CHARGED;
    }
  }
  return this->NO_POWER;
}
