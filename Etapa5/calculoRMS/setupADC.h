#include <Arduino.h>

#define N 16
#define ADCresolution 10
volatile unsigned int i = 0;
// Número de amostras coletadas

const int f = 60;
const int fs = 960;
const double A = 5;
double offset = 2.5;
double ganhoTC = 1;
double  ADCcounts;
volatile double S[N];
const int analogPin = A1;

void initADC(){
    pinMode(analogPin, INPUT);
    ADCcounts = pow(2, ADCresolution);
    analogWrite(analogPin,0);


}

// Função a ser chamada a ser executada  a cada periodo de amostragem
void callback()
{
  S[i] = ganhoTC*(((analogRead(analogPin)*A)/ADCcounts)-offset);
  i++;
  // zero o contador quando é ultrapassado valor de 16
  i = i & 0xf;
}
