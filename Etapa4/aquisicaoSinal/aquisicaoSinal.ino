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

#define N 256
#define ADCresolution 10
volatile unsigned int i = 0;
// Número de amostras coletadas

const int f = 60;
const int fs = 960;
const double A = 5;
double offset = 1;
double ganhoTC = 1;
double  ADCcounts;
volatile double S[N];
const int analogPin = A1;


void setup()
{
  Serial.begin(115200);
  ADCcounts = pow(2, ADCresolution);
  pinMode(analogPin, INPUT);
  //analogWrite(analogPin, 0);
  // Inicializar  timer1 com 1041 microsegundos, isso nos dá uma taxa de amostragem de 16 amostras por ciclo do sinal da rede elétrica
  //
  Timer1.initialize(500);
  Timer1.attachInterrupt(callback);  // attaches callback() as a timer overflow interrupt
}
// Função a ser chamada a ser executada  a cada periodo de amostragem
void callback()
{
  S[i] = ganhoTC*(((analogRead(analogPin)*A)/1023)-offset);
  i++;
  // zero o contador quando é ultrapassado valor de 16
  i = i & 0xff;
}

void loop()
{
  for(int k=0; k<N;k++){
     Serial.println(S[k]);
   }
 
  delay(1000);


  // your program here...
}
