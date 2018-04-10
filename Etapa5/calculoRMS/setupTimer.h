#include <Arduino.h>
#include "TimerOne.h"
#include "setupADC.h"




void initTimer(){

  // Inicializar  timer1 com 1041 microsegundos, isso nos dá uma taxa de amostragem de 16 amostras por segundo na rede elétrica
  Timer1.initialize(1041);
  Timer1.attachInterrupt(callback);  // attaches callback() as a timer overflow interrupt
}
