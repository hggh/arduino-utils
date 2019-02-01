#include <Arduino.h>

class ShiftOutRegister {
  public:
    void init(short dataPin, short shiftPin, short storePin, short enablePin, short output_count);
    void set_bit(short number, short val);
    void writeOut(void);
  private:
    void startup(void);
    void shift(short val);
    short dataPin;
    short shiftPin;
    short storePin;
    short enablePin;
    short output_count;
    int *data;
  
};
