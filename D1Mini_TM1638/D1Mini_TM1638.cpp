/* Using library from  https://github.com/rjbatista/tm1638-library */
#include "D1Mini_TM1638.h"

// D7 and D5 used by Wemos Matrix shield, D4 and D3 are GPIO2 and 0
// define a module on data pin DIO:D6, clock pin CLK:D1 and strobe pin STB:D2
TM1638 module(D6, D1, D2);

void setup() {
  // display a hexadecimal number and set the middle 4 dots
  module.setDisplayToHexNumber(0x1234ABCD, 0x3C);
}

int counter=0;
void loop() {
  byte keys = module.getButtons();

  // light the corresponding red LEDs as the buttons are pressed
  module.setLEDs(keys & 0xFF);
  module.setDisplayToDecNumber(counter, 1<<(counter%8), 3);
  counter++;
  delay(keys*10);
}
