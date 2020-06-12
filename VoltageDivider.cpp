#include "VoltageDivider.h"

void VoltageDivider::init(uint8_t pin_enable, uint8_t pin_adc) {
  this->pin_enable = pin_enable;
  this->pin_adc = pin_adc;
  this->aref = 3.3;
  this->resolution = 4095.0;

  this->setup();
}

void VoltageDivider::setup(void) {
  pinMode(this->pin_enable, OUTPUT);
  digitalWrite(this->pin_enable, LOW);

  pinMode(this->pin_adc, INPUT);
}

float VoltageDivider::get_voltage(void) {
  this->enable_divider();
  float val = analogRead(this->pin_adc);
  float vin = ((val * this->aref) / this->resolution) / (this->value_r2 / ( this->value_r1 + this->value_r2));
  this->disable_divider();
  return vin;
}

void VoltageDivider::set_aref(float aref) {
  this->aref = aref;
}

void VoltageDivider::set_resolution(float resolution) {
  this->resolution = resolution;
}

void VoltageDivider::set_r1(float value_r1) {
  this->value_r1 = value_r1;
}

void VoltageDivider::set_r2(float value_r2) {
  this->value_r2 = value_r2;
}

void VoltageDivider::enable_divider(void) {
  digitalWrite(this->pin_enable, HIGH);
}

void VoltageDivider::disable_divider(void) {
  digitalWrite(this->pin_enable, LOW);
}
