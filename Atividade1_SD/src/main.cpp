#include <avr/io.h>

#define OBS_FREN 0b00110000
#define OBS_DIRE 0b00001100
#define OBS_ESQU 0b00011000   
#define OBS_TRAS 0b00100100

int main(){
  //Computa os obstáculos
  DDRB &= 0b00000000 ; //Entradas: 2,3,4,5
  
  //Manda sinais para os controles do carro
  DDRC |= 0b01111000; 

  PORTB |= 0b00111100;
  PORTC &= 0b00000000;
  while(1){
    //0b0 0000 000 ->parar (obst.: frente e dir e esq e tras = 0b00000000)
    //0b0 0001 000 -> andar pra frente (obst: nenhum ou tras ou dir ou esq = 0b00111100) 
    //0b0 0100 000 -> andar pra direita (obst: frente)
    //0b0 0010 000 -> andar pra trás (obst: frente e dir e esq = 0b00011100)
    //0b0 1000 000 -> andar pra esquerda (obst.: (frente e dir) ou atras)
    if(PINB == (OBS_FREN & OBS_DIRE & OBS_ESQU & OBS_TRAS)){ //PARAR
      PORTC = 0b00000000;
    }else if(PINB == (OBS_FREN & OBS_DIRE & OBS_ESQU)){ //ANDAR PARA TRAS
      PORTC = 0b00010000;
    }else if(PINB == ((OBS_FREN & OBS_DIRE) | OBS_TRAS)){ //ANDAR PARA A ESQUERDA
      PORTC = 0b01000000;
    }else if(PINB == OBS_FREN){ //ANDAR PARA A DIREITA
      PORTC = 0b00100000;
    }else{
      PORTC = 0b00001000;  //ANDAR PARA FRENTE
    }
  }
}