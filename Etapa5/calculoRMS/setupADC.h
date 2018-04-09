#include <Arduino.h>

#define N 16
#define ADCresolution 10
volatile unsigned int i = 0;
// Número de amostras coletadas

const int f = 60;
const int fs = 960;
const int A = 5;
float offset = 2.5;
float ganhoTC = 10;
int  ADCcounts;
volatile double S[N];
const int analogPin = 3;

void initADC(){
    pinMode(analogPin, INPUT);
    ADCcounts = pow(2, ADCresolution);


}

// Função a ser chamada a ser executada  a cada periodo de amostragem
void callback()
{
  S[i] = ganhoTC*(((AnalogRead(analogPin)*A)/ADCcounts)-offset);
  i++;
  // zero o contador quando é ultrapassado valor de 16
  i = i && 0x10;
}
