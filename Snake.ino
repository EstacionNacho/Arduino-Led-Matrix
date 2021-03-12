#include "LedControl.h"

#define SIZE 8
#define SPEED 5

LedControl lc=LedControl(2,4,3,1); //Pins: DIN,CLK,CS,

int aux;

void setup() {

  lc.shutdown(0,false);
  lc.setIntensity(0,1);
Serial.begin(9600);
aux = 0;

}

void loop() {

for(int i = aux; i < SIZE - aux; i++){
  lc.setLed(0,aux,i,true);
  delay(SPEED);
  Serial.print("(");
  Serial.print(aux);
  Serial.print(",");
  Serial.print(i);
  Serial.println(")");
}

for(int i = aux; i < SIZE - aux; i++){
  lc.setLed(0,i,(SIZE - 1) - aux ,true);
  delay(SPEED);
  Serial.print("(");
  Serial.print(i);
  Serial.print(",");
  Serial.print((SIZE - 1) - aux);
  Serial.println(")");
}

for(int i = aux; i < SIZE - aux; i++){
  lc.setLed(0,(SIZE - 1) - aux ,(SIZE - 1) - i,true);
  delay(SPEED);
  Serial.print("(");
  Serial.print((SIZE - 1) - aux);
  Serial.print(",");
  Serial.print((SIZE - 1) - i);
  Serial.println(")");
}

for(int i = aux; i < SIZE - aux; i++){
  lc.setLed(0,(SIZE - 1) - i, aux ,true);
  delay(SPEED);
  Serial.print("(");
  Serial.print((SIZE - 1) - i);
  Serial.print(",");
  Serial.print(aux);
  Serial.println(")");
}

aux++;
if(aux == 4){
 lc.clearDisplay(0);
 aux = 0;
 Serial.println("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
}

}
