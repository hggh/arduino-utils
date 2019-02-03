#include "Light.h"

void Light::begin(uint8_t light_pin) {
  this->pin = light_pin;
  pinMode(this->pin, OUTPUT);
  digitalWrite(this->pin, LOW);
}

void Light::begin(uint8_t light_pin, ShiftOutRegister *sh_register) {
  this->pin = light_pin;
  this->shiftout = true;
  this->sh_register = sh_register;
}

void Light::on(void) {
  if (this->shiftout == true) {
    this->sh_register->set_bit(this->pin, HIGH);
    this->sh_register->writeOut();
  }
  else {
    digitalWrite(this->pin, HIGH);
  }
}

void Light::off(void) {
  if (this->shiftout == true) {
    this->sh_register->set_bit(this->pin, LOW);
    this->sh_register->writeOut();
  }
  else {
    digitalWrite(this->pin, LOW);
  }
}
