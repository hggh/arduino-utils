# arduino-utils
Arduino / Atmel utils


## usage of Voltage.h

```cpp
#include <Voltage.h>
Voltage voltage;
 
void setup() {
  voltage.init();
}
 
void loop() {
  float vcc = voltage.read();
}
```
