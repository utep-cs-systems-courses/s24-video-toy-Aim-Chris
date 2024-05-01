#include <msp430.h>
#include "switches.h"
#include "buzzer.h"

char
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES);

  return p2val;
}

void switch_init()
{
  P2REN |= SWITCHES; //enables resistors
  P2IE |= SWITCHES; //enable interrupts
  P2OUT |= SWITCHES; //pull-ups switches
  P2DIR &= ~SWITCHES; //set switches bits
}

//handler for buttons
void switch_interrupt_handler(){
  char p2val = switch_update_interrupt_sense();

  char b1 = (p2val & SW1) ? 0 : 1;
  char b2 = (p2val & SW2) ? 0 : 1;
  char b3 = (p2val & SW3) ? 0 : 1;
  char b4 = (p2val & SW4) ? 0 : 1;

  if(b1){
    zeldaL();
  }
  if(b2){
    zeldaL();
  }
  if(b3){
    pokeSong();
  }
}
