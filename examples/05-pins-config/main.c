#include "../../lib/stc15.h"
#include "../../lib/utils.h"
#include "../../lib/serial.h"
#include <stdio.h>

#define FOSC 11059200L

void main()
{
    char status_str[50];
	set_oscillator(FOSC);
	uart_init(9600);

    // pins PXM1,PXM0 config are:
    // 0,0 quasi birectional (traditional) and default
    // 0,1 push-pull output(strong pull-up output)
    // 1,0 input only (high impedance)
    // 1,1 open drain

    // so test this with ports
    // P1.1 = 0,0
    // P1.2 = 0,1
    // P1.3 = 1,0
    // P1.4 = 1,1
    // usually the output you will see is:
    // P1.1=1, P1.2=1, P1.3=0, P1.4=0
    // P1.3 is floating
    // P1.4 by default is GND but is easier to float
    P1M1 = 0x18;
    P1M0 = 0x14;

    while(1) {
        sprintf(
            status_str,
            "P1.1=%d, P1.2=%d, P1.3=%d, P1.4=%d\n",
            P1_1,
            P1_2,
            P1_3,
            P1_4
        );
        uart_send(status_str);
		delay(500);
    }
}
