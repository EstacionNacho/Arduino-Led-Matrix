#include "LedControl.h"
#include <binary.h>

#define SIZE 8
#define SPEED 50

LedControl lc=LedControl(2,4,3,1); //Pins: DIN,CLK,CS,

int aux;
int num;
int c ;

void setup() {

  lc.shutdown(0,false);
  lc.setIntensity(0,1);

Serial.begin(9600);

aux = 0;
num = 255;
c = 0;
}

void loop() {

Serial.print(num);

lc.setRow(0,aux,num);
lc.setRow(0,(SIZE - 1) - aux,num);
lc.setColumn(0,aux,num);
lc.setColumn(0,(SIZE - 1) - aux,num);

delay(SPEED);
lc.clearDisplay(0);
delay(SPEED);

num = num /2;
Serial.println();
Serial.print(num);
num = num - pow(2,aux) - c;
c = pow(2,aux);

Serial.println();
Serial.print(num);
Serial.println();
Serial.print(aux);
Serial.println();
Serial.print(c);
Serial.println();
Serial.println("xxxxxxxx");
aux++;
if(aux == 4){
  aux = 0;
  num = 255;
  c = 0;
}

}
