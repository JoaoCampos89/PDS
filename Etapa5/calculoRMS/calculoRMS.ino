/**
* Objetivo: Aquisitar o sinal a uma taxa de amostragem constante
*
* Author: João Campos
* Referencias:
*
* https://playground.arduino.cc/Code/Timer1
*
*/
// Biblioteca que inicia o timer e variáveis de aquisição de sinal
#include "setupTimer.h"


int rms = 0 ;

void setup()
{

  initADC();
  initTimer();
}

/**
 * [loop description]
 * S Global
 */
void loop()
{

// cálculo do rms do sinal
  rms = 0;
  for (size_t i = 0; i < N; i++) {
    rms = rms + S[i]*S[i];
  }
  rms = rms/N;
  rms = sqrt(rms);

  Serial.println(rms);
  delay(10);

}
