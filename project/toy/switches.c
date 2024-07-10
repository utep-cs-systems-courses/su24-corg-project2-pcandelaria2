#include <msp430.h>
#include "switches.h"
#include "stateMachines.h"
#include "buzzer.h"
#include "led.h"

char s1,s2,s3,s4;
char switch_state;

static char switch_update_interrupt_sense(){
  char p2val = P2IN;
  P2IES |= (p2val & SWITCHES);
  P2IES &= (p2val | ~SWITCHES);
  return p2val;
}
void switch_init(){
  P2REN |= SWITCHES;
  P2IE = SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;
  switch_update_interrupt_sense();

  led_update();
}

void switch_interrupt_handler(){
  char p2val = switch_update_interrupt_sense();

  s1 = (p2val & SW1) ? 0 : SW1;
  s2 = (p2val & SW2) ? 0 : SW2;
  s3 = (p2val & SW3) ? 0 : SW3;
  s4 = (p2val & SW4) ? 0 : SW4;

  //add stuff for switches to do ie make one switch play music and another to do led and another to do both
  if(s1){
    song();
  }
  if(s2){
    state_advance();
  }
  if(s3){
    song();
    state_advance();
  }
  if(s4){
    buzzer_set_period(2000);
  }
}
