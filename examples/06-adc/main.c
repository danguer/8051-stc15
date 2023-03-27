#include "../../lib/stc15.h"
#include "../../lib/utils.h"
#include "../../lib/serial.h"
#include <stdio.h>

#define FOSC 11059200L

void main()
{
    unsigned int adc_value;
    char status_str[15];
    set_oscillator(FOSC);
    uart_init(9600);

    // set P1.1 as ADC
    P1ASF = P11ASF;

    while(1) {
        // power the adc, start the capturing for channel P1_1
        ADC_CONTR = ADC_POWER | ADC_START | CHS_P1_1;

        // wait until flag is ready
        while (!(ADC_CONTR & ADC_FLAG));

        // calculate the value
        adc_value = (ADC_RES << 2) | (ADC_RESL & 0x3);

        // reset the flag
        ADC_CONTR &= ~ADC_FLAG;

        sprintf(
            status_str,
            "ADC: %d\n",
            adc_value
        );
        uart_send(status_str);
        delay(500);
    }
}
