#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "led.h"
#include "switches.h"
#include "stateMachines.h"

int main() {
    configureClocks();
    buzzer_init();
    led_init();
    switch_init();
  

    or_sr(0x18);          // CPU off, GIE on
}
