#include <Arduino.h>
#include "setupADC.h"



void initTimer(){

  // Inicializar  timer1 com 1041 microsegundos, isso nos dá uma taxa de amostragem de 16 amostras por segundo na rede elétrica
    timer = timerBegin(0, 80, true);
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, 1041, true);
    timerAlarmEnable(timer);


}
