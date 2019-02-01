#include <Arduino.h>

class ShiftOutRegister {
  public:
    void init(uint8_t dataPin, uint8_t shiftPin, uint8_t storePin, uint8_t enablePin, uint8_t output_count);
    void set_bit(uint8_t number, uint8_t val);
    void writeOut(void);
  private:
    void startup(void);
    void shift(uint8_t val);
    uint8_t dataPin;
    uint8_t shiftPin;
    uint8_t storePin;
    uint8_t enablePin;
    uint8_t output_count;
    uint8_t *data;
};
