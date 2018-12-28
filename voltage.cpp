#include <avr/power.h>
#include "voltage.h"

void Voltage::init(void) {
  ADCSRA_status = ADCSRA;
  disable();
}

void Voltage::enable(void) {
  power_adc_enable();
  ADCSRA = ADCSRA_status;
}

void Voltage::disable(void) {
  ADCSRA &= ~(1 << 7);
  power_adc_disable();
}

float Voltage::read(void) {
  enable();

  ADCSRA |= bit (ADPS0) |  bit (ADPS1) | bit (ADPS2);  // Prescaler of 128
  ADMUX = bit (REFS0) | bit (MUX3) | bit (MUX2) | bit (MUX1);

  delay(10);
  bitSet (ADCSRA, ADSC);
  while (bit_is_set(ADCSRA, ADSC)) {
  }
  float battery_voltage = InternalReferenceVoltage / float (ADC + 0.5) * 1024.0;

  disable();

  return battery_voltage;
}
