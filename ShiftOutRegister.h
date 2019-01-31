#include <Arduino.h>

class ShiftOutRegister {
  public:
    void init(short i_dataPin, short i_shiftPin, short i_storePin, short i_enablePin, short i_output_count);
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
