#include "Shutter.h"

void Shutter::begin(uint8_t power, uint8_t updown, uint8_t seconds) {
  this->pin_power = power;
  this->pin_updown = updown;
  this->running_seconds = seconds;

  pinMode(this->pin_power, OUTPUT);
  pinMode(this->pin_updown, OUTPUT);

  digitalWrite(this->pin_power, LOW);
  digitalWrite(this->pin_updown, LOW);
}

void Shutter::timer(void) {
  if (this->timer_active != 1) {
    return;
  }
  if (this->timer_run > this->running_seconds + 2) {
    noInterrupts();
    this->complete_power_down();
    this->timer_active = 0;
    interrupts();
  }

  if (timer_run > running_seconds) {
    noInterrupts();
    this->power_down();
    interrupts();
  }

  this->timer_run++;
}

void Shutter::activate_timer(void) {
  this->timer_active = 1;
  this->timer_run = 0;
}

void Shutter::complete_power_down(void) {
  digitalWrite(this->pin_power, LOW);
  digitalWrite(this->pin_updown, LOW);

  this->operation = OPERATION_NOPOWER;
}

void Shutter::power_down(void) {
  digitalWrite(this->pin_power, LOW);
}

void Shutter::up(void) {
  noInterrupts();
  if (operation == OPERATION_DOWN) {
    this->power_down();
    delay(900);
    this->complete_power_down();
  }
  this->operation = OPERATION_UP;
  digitalWrite(this->pin_power, HIGH);
  this->activate_timer();
  interrupts();
}

void Shutter::down(void) {
  noInterrupts();
  if (this->operation == OPERATION_UP) {
    power_down();
    delay(900);
    this->complete_power_down();
  }
  this->operation = OPERATION_DOWN;
  digitalWrite(this->pin_updown, HIGH);
  delay(5);
  digitalWrite(this->pin_power, HIGH);
  this->activate_timer();
  interrupts();
}

void Shutter::halt(void) {
  noInterrupts();
  this->power_down();
  delay(200);
  this->complete_power_down();
  interrupts();
}
