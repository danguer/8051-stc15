#include "../../lib/stc15.h"
#include "../../lib/utils.h"
#include <stdio.h>

#define FOSC 11059200L

// in the STC15W408AS dev board, the button is connected to P3.2/INT0
// so clicking it will make the led blink

void INT0_ISR (void) __interrupt 0
{
   // nothing here, but needed
   // since after this is called
   // will continue with main code
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

    while(1) {
        P1 = 0xFF; // led off

        // set IDL = 1 or idle mode
        PCON |= 0x01;

        // wait at least 4us before trying to idle again
        // this is not needed because the led on and delay routine
        // but is a good reminder
        __asm
        nop
        nop
        nop
        nop
        __endasm;

        // interrupt will return to this
        P1 = 0x00; // led on
        delay(500);
    }
}
