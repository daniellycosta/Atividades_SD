#include <avr/io.h>
#include <inttypes.h> 

int main() {
  uint16_t valorAD=0;
  //Configurando ADC
  ADMUX |= 0b00000011; //usando AC03 e AREF
  ADCSRA |= 0b10000111; //habilitando ADC com fator de divisão 128

  //Configurando entradas(0) e saídas(1)
  DDRB |= 0b00000010;
  PORTB |= 0b00000000; //Configirando entrada como Hi-Z

  //configurando PWM

  while(1){

  }
  
}