#include "TP4056.h"

void TP4056::init(uint8_t pin_usb_power, uint8_t pin_chrg, uint8_t pin_stdby) {
  this->pin_chrg = pin_chrg;
  this->pin_stdby = pin_stdby;
  this->pin_usb_power = pin_usb_power;
}

void TP4056::init(uint8_t pin_chrg, uint8_t pin_stdby) {
  this->pin_chrg = pin_chrg;
  this->pin_stdby = pin_stdby;
}

void TP4056::set_pullup(void) {
  this->pullup = true;
}

void TP4056::setup(void) {
  if (this->pullup == true) {
    pinMode(this->pin_chrg, INPUT_PULLUP);
    pinMode(this->pin_stdby, INPUT_PULLUP);
  }
  else {
    pinMode(this->pin_chrg, INPUT);
    pinMode(this->pin_stdby, INPUT);
  }
  if (this->pin_usb_power) {
    pinMode(this->pin_usb_power, INPUT);
  }
}

bool TP4056::has_usb_power(void) {
  if (digitalRead(this->pin_usb_power) == 1) {
    return true;
  }
  return false;
}

bool TP4056::is_charging(void) {
  if (digitalRead(this->pin_chrg) == LOW && digitalRead(this->pin_stdby) == HIGH) {
   return true;
  }
  return false;
}

bool TP4056::is_charged(void) {
  if (digitalRead(this->pin_chrg) == HIGH && digitalRead(this->pin_stdby) == LOW) {
   return true;
  }
  return false;
}
