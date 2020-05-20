#if defined(__AVR_ATmega328P__) || defined(__AVR_ATtiny85__)
#include <avr/power.h>
#include "Voltage.h"

void Voltage::init(void) {
  ADCSRA_status = ADCSRA;
  disable();
}

void Voltage::enable(void) {
#if defined(__AVR_ATmega328P__)
  power_adc_enable();
#endif
  ADCSRA = ADCSRA_status;
}

void Voltage::disable(void) {
  ADCSRA &= ~(1 << 7);
#if defined(__AVR_ATmega328P__)
  power_adc_disable();
#endif
}

float Voltage::read(void) {
  enable();

#if defined(__AVR_ATmega328P__)
  ADCSRA |= bit (ADPS0) |  bit (ADPS1) | bit (ADPS2);  // Prescaler of 128
  ADMUX = bit (REFS0) | bit (MUX3) | bit (MUX2) | bit (MUX1);
#elif defined(__AVR_ATtiny85__)
  ADMUX = _BV(MUX3) | _BV(MUX2);
  delay(2);
  ADCSRA |= _BV(ADSC);
#endif

  delay(10);
  bitSet (ADCSRA, ADSC);
  while (bit_is_set(ADCSRA, ADSC)) {
  }
  float battery_voltage = InternalReferenceVoltage / float (ADC + 0.5) * 1024.0;

  disable();

  return battery_voltage;
}
#endif
