#include "LedControl.h"
#include <binary.h>

//Size of led matrix 
#define SIZE 8
//Speed of animation
#define SPEED 60

LedControl lc=LedControl(12,10,11,1); 

int numberLeds[SIZE];
int con[SIZE];

void setup() {

  for(int i = 0; i < SIZE; i++){
    numberLeds[i] = i;
    con[i] = (SIZE * 16)>>i;
  }
  lc.shutdown(0,false);
  lc.setIntensity(0,1);

}

void loop() {

delay(SPEED);
lc.clearDisplay(0);

for(int  i = SIZE - 1; i > 0 ; i--){
  numberLeds[i] = controlLightLed(numberLeds[i-1],numberLeds[i],con[i],i+1);
}

numberLeds[0] = lightLed(numberLeds[0],con[0]);

if(numberLeds[SIZE-1] > SIZE){
    for(int i = 0; i < SIZE; i++){
    numberLeds[i] = i;
  }
}

}

int controlLightLed(int auxm,int auxM,int con,int num){
  if(auxm >= num){
  auxM = lightLed(auxM,con);
  }
  return auxM;
}

int lightLed(int aux,int con){
  lc.setRow(0,aux,con);
  lc.setColumn(0,aux,con);
  aux++;
  return aux;
}
