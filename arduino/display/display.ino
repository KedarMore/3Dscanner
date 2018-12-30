#include "TM1637.h"
#define CLK 2//pins definitions for TM1637 and can be changed to other ports       
#define DIO 3
TM1637 tm1637(CLK, DIO);

void setup() {
  // put your setup code here, to run once:
  tm1637.init();
  tm1637.set(1);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
}

void loop() {
  // put your main code here, to run repeatedly:
  tm1637.display(0, 1);
  tm1637.display(1, 5);
  tm1637.display(2, 3);
  tm1637.display(3, 6);
}
