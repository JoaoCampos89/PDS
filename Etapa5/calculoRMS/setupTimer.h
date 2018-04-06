#include <Arduino.h>
#include "TimerOne.h"
#define N 16
volatile unsigned int i = 0;

volatile int S[N];
int analogPin = 3;

// Função a ser chamada a ser executada  a cada periodo de amostragem
void callback()
{
  S[i] = analogRead(analogPin);
  i++;
  // zero o contador quando é ultrapassado valor de 16
  i = i && 0x10;
}

void initTimer(){
  pinMode(analogPin, INPUT);
  // Inicializar  timer1 com 1041 microsegundo, isso nos dá uma taxa de amostragem de 16 amostras por segundo na rede elétrica
  Timer1.initialize(1041);
  Timer1.attachInterrupt(callback);  // attaches callback() as a timer overflow interrupt
}


