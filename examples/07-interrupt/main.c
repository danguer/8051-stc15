#include "../../lib/stc15.h"
#include "../../lib/utils.h"
#include <stdio.h>

#define FOSC 11059200L

// in the STC15W408AS dev board, the button is connected to P3.2/INT0
// so clicking it will make the led blink

void INT0_ISR (void) __interrupt 0
{
    P1 = 0x00; // led on
    delay(500);
    P1 = 0xFF; // led off
}

void main()
{
    set_oscillator(FOSC);

    // enable all interrupts, enable INT0
    EA = EX0 = 1;

    // enable highest priority
    PX0 = 1;

    // only enable by falling edge
    IT0 = 1;

    while(1);
}
