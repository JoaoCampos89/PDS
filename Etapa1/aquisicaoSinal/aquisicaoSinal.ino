/**
* Objetivo: Aquisitar o sinal a uma taxa de amostragem constante
*
* Author: João Campos
* Referencias:
*
* https://playground.arduino.cc/Code/Timer1
*
*/

#include "TimerOne.h"

#define N 256

volatile unsigned int i = 0;
// Número de amostras coletadas

const int f = 60;
const int fs = 960;
volatile int S[N];
const int analogPin = A1;

void setup()
{
  Serial.begin(115200);
  pinMode(analogPin, INPUT);
  //analogWrite(A1,0);
  // Inicializar  timer1 com 1041 microsegundos, isso nos dá uma taxa de amostragem de 16 amostras por ciclo do sinal da rede elétrica
  Timer1.initialize(1041);
  Timer1.attachInterrupt(callback);  // attaches callback() as a timer overflow interrupt
}
// Função a ser chamada a ser executada  a cada periodo de amostragem
void callback()
{
  S[i] = analogRead(analogPin);
  i++;
  // zera o contador quando é ultrapassado valor de 16
  i = i & 0xff;
}

void loop()
{
  for(int k=0; k<N;k++){
     Serial.println(S[k]);
   }
  delay(1000);


  // your program here...
}
