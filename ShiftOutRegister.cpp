#include "ShiftOutRegister.h"

void ShiftOutRegister::init(uint8_t dataPin, uint8_t shiftPin, uint8_t storePin, uint8_t enablePin, uint8_t output_count) {
  this->dataPin = dataPin;
  this->shiftPin = shiftPin;
  this->storePin = storePin;
  this->enablePin = enablePin;
  this->output_count = output_count;

  pinMode(this->dataPin, OUTPUT);
  pinMode(this->shiftPin, OUTPUT);
  pinMode(this->storePin, OUTPUT);
  pinMode(this->enablePin, OUTPUT);

  digitalWrite(this->enablePin, HIGH);

  // init dynamic array with all output disabled then set OE to HIGH
  this->data = new uint8_t[this->output_count]();
  for (short i = 0; i < this->output_count; i++) {
    this->set_bit(i, 0);
  }
  this->startup();
}

void ShiftOutRegister::shift(uint8_t val) {
  digitalWrite(this->shiftPin, LOW);

  digitalWrite(this->dataPin, val);

  digitalWrite(this->shiftPin, HIGH);
}

void ShiftOutRegister::startup(void) {
  this->writeOut();
  digitalWrite(this->enablePin, LOW);
}

void ShiftOutRegister::set_bit(uint8_t number, uint8_t val) {
  if (number <= this->output_count) {
    this->data[number] = val;
  }
}

void ShiftOutRegister::writeOut(void) {
  digitalWrite(this->storePin, LOW);
  for (short i = this->output_count -1; i>=0; i--) {
    this->shift(this->data[i]);
  }
  digitalWrite(this->storePin, HIGH);
}
