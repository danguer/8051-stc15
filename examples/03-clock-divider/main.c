#include "../../lib/stc15.h"
#include "../../lib/utils.h"

#define FOSC 11059200L

void main(void)
{
    unsigned char clock_divider = 0x0; // default
    set_oscillator(FOSC);

    while(1)
    {
        // set clock divider register
        CLK_DIV &= 0xFF << 3; // clear CLKS2 CLKS1 CLKS0
        CLK_DIV |= clock_divider; //Set bits

        P1 = 0x00;
        delay(1000);
        P1 = 0xFF;
        delay(1000);

        clock_divider++;
        if (clock_divider == 0x8) {
            // reset value
            clock_divider = 0;
        }
    }
}
