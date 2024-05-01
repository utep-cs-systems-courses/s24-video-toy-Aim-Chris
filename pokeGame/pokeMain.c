#include <msp430.h>
#include <libTimer.h>
#include <stdio.h>
#include "buzzer.h"
#include "switches.h"
#include "lcddraw.h"
#include "lcdutils.h"


void main(){
  configureClocks();
  buzzer_init();
  switch_init();
  enableWDTInterrupts();

  or_sr(0x8);
}
