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

#define N 16

volatile unsigned int i = 0;
// Número de amostras coletadas

const int f = 60;
const int fs = 960;
volatile int S[N];
const int analogPin = A1;

void setup()
{
  pinMode(analogPin, INPUT);
  // Inicializar  timer1 com 1041 microsegundos, isso nos dá uma taxa de amostragem de 16 amostras por ciclo do sinal da rede elétrica
  Timer1.initialize(1041);
  Timer1.attachInterrupt(callback);  // attaches callback() as a timer overflow interrupt
}
// Função a ser chamada a ser executada  a cada periodo de amostragem
void callback()
{
  S[i] = AnalogRead(analogPin);
  i++;
  // zero o contador quando é ultrapassado valor de 16
  i = i & 0xf;
}

void loop()
{
  Serial.println(S[N-1]);
  delay(2);


  // your program here...
}
