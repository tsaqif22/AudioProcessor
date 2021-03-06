// From https://github.com/ahuxtable/TDA7439

#include <Arduino.h>
#include <TinyWireM.h>
#include <USI_TWI_Master.h>
#include "TDA7439.h"

TDA7439::TDA7439(){
	TinyWireM.begin();
}

void TDA7439::setInput(int input){
  switch (input) {
    case 1: input = TDA7439_input_1;break;
  	case 2: input = TDA7439_input_2;break;
  	case 3: input = TDA7439_input_3;break;
  	case 4: input = TDA7439_input_4;break;
  }
  writeWire(TDA7439_input_sel,input);	
  } 

void TDA7439::inputGain(int gain){
  writeWire(TDA7439_input_gain,gain);
}

void TDA7439::setVolume(int volume){
  if (volume == 0){
    volume = TDA7439_mute;
	}else{
	  volume = 48 - volume;
  }
  writeWire(TDA7439_volume,volume);
}

void TDA7439::setSnd(int val, int range){
  switch (range) {
    case 1:range = TDA7439_bass;break;
  	case 2:range = TDA7439_middle;break;
  	case 3:range = TDA7439_trebble;break;
  }
  
  switch (val){
    case -7:val = 0;break;
  	case -6:val = 1;break;
  	case -5:val = 2;break;
  	case -4:val = 3;break;
  	case -3:val = 4;break;
  	case -2:val = 5;break;
  	case -1:val = 6;break;
  	case 0 :val = 7;break;
  	case 1 :val = 14;break;
  	case 2 :val = 13;break;
  	case 3 :val = 12;break;
  	case 4 :val = 11;break;
  	case 5 :val = 10;break;
  	case 6 :val = 9;break;
  	case 7 :val = 8;break;
  }
	  
writeWire(range,val);
}

void TDA7439::mute(){
  writeWire(TDA7439_volume,TDA7439_mute);
}

void TDA7439::spkAtt(int att){
  // Mainly used to override the default attenuation of mute at power up
  // can be used for balance with some simple code changes here.
  switch (att){
    case 0:att = 0;break;
    case 1:att = 1;break;
    case 2:att = 2;break;
    case 3:att = 3;break;
    case 4:att = 4;break;
    case 5:att = 5;break;
    case 6:att = 6;break;
    case 7 :att = 7;break;
    case 8 :att = 8;break;
    case 9 :att = 16;break;
    case 10 :att = 24;break;
    case 11 :att = 32;break;
    case 12 :att = 40;break;
    case 13 :att = 48;break;
    case 14 :att = 56;break;
    case 15 :att = 64;break;
    case 16 :att = 72;break;
  }

  writeWire(TDA7439_ratt,att);
  writeWire(TDA7439_latt,att);
}

void TDA7439::writeWire(char a, char b){
  TinyWireM.beginTransmission(TDA7439_address);
  TinyWireM.write (a);
  TinyWireM.write (b);
  TinyWireM.endTransmission();
}
