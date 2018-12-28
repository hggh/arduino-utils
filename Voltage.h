#include <Arduino.h>

class Voltage {
  public:
    void init(void);
    float read(void);
  private:
    byte ADCSRA_status;
    float InternalReferenceVoltage = 1.1;
    void enable(void);
    void disable(void);
};
