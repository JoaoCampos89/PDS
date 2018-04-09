/**
* Objetivo: Aquisitar o sinal de 0 a 5V e plotar
*
* Author: João Campos
* Referencias:
*
* https://playground.arduino.cc/Code/Timer1
*
*/

#include "TimerOne.h"

#define N 16
#define ADCresolution 10
volatile unsigned int i = 0;
// Número de amostras coletadas

const int f = 60;
const int fs = 960;
const int A = 5;
int  ADCcounts;
volatile double S[N];
const int analogPin = 3;

void setup()
{
  ADCcounts = pow(2, ADCresolution);
  pinMode(analogPin, INPUT);
  // Inicializar  timer1 com 1041 microsegundo, isso nos dá uma taxa de amostragem de 16 amostras por ciclo do sinal da rede elétrica
  Timer1.initialize(1041);
  Timer1.attachInterrupt(callback);  // attaches callback() as a timer overflow interrupt
}
// Função a ser chamada a ser executada  a cada periodo de amostragem
void callback()
{
  S[i] = (AnalogRead(analogPin)*A)/ADCcounts;
  i++;
  // zero o contador quando é ultrapassado valor de 16
  i = i && 0x10;
}

void loop()
{
  Serial.println(S);
  delay(2);


  // your program here...
}
