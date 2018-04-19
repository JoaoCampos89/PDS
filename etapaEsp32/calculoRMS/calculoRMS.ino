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


double rms = 0 ;

void setup()
{
  Serial.begin(115200);
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
  for (size_t k = 0; k < N; k++) {
    rms = rms + S[k]*S[k];
  }
  rms = rms/N;
  rms = sqrt(rms);
  Serial.println(rms,4);
  delay(2000);
 
 


}
