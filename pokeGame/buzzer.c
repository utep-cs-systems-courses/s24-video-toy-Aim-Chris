#include <msp430.h>
#include <stdlib.h>
#include "libTimer.h"
#include "buzzer.h"


void buzzer_init(){
  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;
}

void buzzer_set_period(short cycles){
  CCR0 = cycles;
  CCR1 = cycles >> 1;
}
void zeldaL(){
  int song[] = {246,246,246,246,246,293,293,220,220,220,220,220,196,220,246,246,246,246,293,293,
		220,220,220,220,220,220,246,246,246,246,246,293,293,440,440,440,440,440,392
		,392,392,293,293,293,293,293,261,246,220,220,220,220,220,220};
  int i = 0;
  while(i<54){
    buzzer_set_period(song[i]);
    __delay_cycles(4500000);
    i++;
  }
  buzzer_set_period(0);
}
void pokeSong(){
  int song [] = {196,246,293,369,392,392,0,0,392,392,0,0,0,392,0,392,0,392,392,0,0,392,392,0,0,
		 349,0,349,0,349,0,349,0,349,369,392,392,392,392,392,493,493,587,587,587,587,
		 261,261,261,174,174};
  int i = 0;
  while(i<60){
    buzzer_set_period(song[i]);
    __delay_cycles(2200000);
    i++;
  }
  buzzer_set_period(0);
}

