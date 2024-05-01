#ifndef switches_included
#define switches_included

#define SW1 BIT0 // button 1
#define SW2 BIT1 // button 2
#define SW3 BIT2 // button 3
#define SW4 BIT3 // button 4

#define SWITCHES (SW1|SW2|SW3|SW4)

void switch_init();
void switch_interrupt_handler();
char switch_update_interrupt_sense();

#endif
