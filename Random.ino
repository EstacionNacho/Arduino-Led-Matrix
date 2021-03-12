#include "LedControl.h"

#define SIZE 8
#define SPEED 90
#define NUMBERLEDS 32

LedControl lc=LedControl(2,4,3,1); //Pins: DIN,CLK,CS,

int randI[NUMBERLEDS];
int randJ[NUMBERLEDS];

void setup() {

  lc.shutdown(0,false);
  lc.setIntensity(0,1);

  for(int i = 0; i < SIZE; i++){
    for(int j = 0; j < 8; j++){
      lc.setLed(0,i,j,true);
      //delay(SPEED);
    }
  }

}

void loop() {

for(int i = 0; i < NUMBERLEDS; i++){
  randI[i] = random(0,SIZE);
  randJ[i] = random(0,SIZE);
  lc.setLed(0,randI[i],randJ[i],false);
}

delay(SPEED);
for(int i = 0; i < NUMBERLEDS; i++){
  lc.setLed(0,randI[i],randJ[i],true);
}

}
