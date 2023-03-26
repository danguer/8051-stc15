#include "../../lib/stc15.h"

#define FOSC 11059200L

void delay_1second(void)
{
    // this calculation is made empirically
    // the better will be use the ASM code and
    // calculate the average number of operations
    // and number of cycles
    unsigned long i = FOSC / 20;
    while (i > 0) {
        i--;
    }
}

void main(void)
{
    while(1)
    {
        // dev board led is connected to VCC so
        // if set P1 to 0 (GND) will close the circuit and LED on
        P1 = 0x00; // LED on
        delay_1second();
        P1 = 0xFF; // LED off
        delay_1second();
    }
}
