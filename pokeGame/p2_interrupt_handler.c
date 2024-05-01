#include <msp430.h>
#include "switches.h"

void
__interrupt_vec(PORT2_VECTOR) Port_2(){
  if(P2IFG & SWITCHES){ //did button cause interrupt
    P2IFG &= ~SWITCHES; // clear pending sw 
    switch_interrupt_handler(); // single handler for all switches
  }
}
