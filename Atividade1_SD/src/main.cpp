#include <avr/io.h>

//Códigos dos obstáculos
#define OBS_FREN_CODE 0b00110000
#define OBS_DIRE_CODE 0b00001100
#define OBS_ESQU_CODE 0b00011000   
#define OBS_TRAS_CODE 0b00100100

//Códigos de comando
#define PAR 0b00000000
#define TRAS 0b00010000
#define ESQU 0b01000000
#define DIRE 0b00100000
#define FREN 0b00001000

int main(){
  //Computa os obstáculos
  DDRB &= 0b00000000 ; //Entradas: 2,3,4,5
  
  //Manda sinais para os controles do carro
  DDRC |= 0b01111000; 

  PORTB |= 0b00111100;
  PORTC &= 0b00000000;

  //auxiliares
  bool OBS_FREN = false;
  bool OBS_DIRE = false;
  bool OBS_ESQU = false;   
  bool OBS_TRAS = false;

  while(1){
    OBS_FREN = false;
    OBS_DIRE = false;
    OBS_ESQU = false;   
    OBS_TRAS = false;
    
    for(int i=0; i<4; i++){
      switch (PINB)
      {
        case OBS_FREN_CODE:
          OBS_FREN = true;
        case OBS_DIRE_CODE:
          OBS_DIRE = true;
        case OBS_ESQU_CODE:
          OBS_ESQU = true;
        case OBS_TRAS_CODE:
          OBS_TRAS = true;
        default:
          break;
      }
    }

    if(OBS_FREN & OBS_DIRE & OBS_ESQU & OBS_TRAS){ 
      PORTC = PAR;
    }else if(OBS_FREN & OBS_DIRE & OBS_ESQU){ 
      PORTC = TRAS;
    }else if((OBS_FREN & OBS_DIRE) | OBS_TRAS){ 
      PORTC = ESQU;
    }else if(OBS_FREN){
      PORTC = DIRE;
    }else{
      PORTC = FREN;
    }
  }
}