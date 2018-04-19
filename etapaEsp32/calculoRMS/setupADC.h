#include <Arduino.h>

#define N 256
#define ADCresolution 12
volatile unsigned int i = 0;
// Número de amostras coletadas

const int f = 60;
const int fs = 960;
const double A = 3.3;
double offset = 2.5;
double ganhoTC = 1;
double  ADCcounts;
volatile double S[N];
const int analogPin = A1;

void initADC(){
    pinMode(analogPin, INPUT);
    ADCcounts = pow(2, ADCresolution);
}

hw_timer_t * timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;




// Função a ser chamada a ser executada  a cada periodo de amostragem
void IRAM_ATTR onTimer() {
{
  portENTER_CRITICAL_ISR(&timerMux);

  S[i] = ganhoTC*(((analogRead(analogPin)*A)/ADCcounts)-offset);
  i++;
  // zero o contador quando é ultrapassado valor de 16
  i = i & 0xff;
 portEXIT_CRITICAL_ISR(&timerMux);


}
