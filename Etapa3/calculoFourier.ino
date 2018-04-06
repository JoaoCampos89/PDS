/**
* Objetivo: Aquisitar o sinal a uma taxa de amostragem constante
*
* Author: João Campos
* Referencias:
*
* https://playground.arduino.cc/Code/Timer1
*
*/
#include "setupTimer.h"


int rms = 0 ;
const float coef_real[N];
const float coef_imag[N];




void setup()
{
  initTimer();
}


void loop()
{

// cálculo do rms do sinal
  rms = 0;
  for (size_t i = 0; i < N; i++) {
    rms = rms + S(i)*S(i);
  }
  rms = rms/N;
  rms = sqrt(rms);

  Serial.printLn(rms)
  delay(10);

}
