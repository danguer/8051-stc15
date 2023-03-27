#include "../../lib/stc15.h"
#include "../../lib/utils.h"

#define FOSC 11059200L

void uart_init(unsigned long baudrate)
{
    SCON = 0x50;    // 8-bit variable UART
    AUXR = 0x14;    // set Timer2 1T Mode, and start Timer2
    AUXR |= 0x01;    // select Timer 2 as Uart 1 baud generator
    T2L = (65536 - (FOSC/4/baudrate));   // set auto-reload vaule
    T2H = (65536 - (FOSC/4/baudrate))>>8;
    ES = 1;
    EA = 1;
}

void uart_send_byte(char tx_data)
{
    SBUF = tx_data;        /* Load char in SBUF register */
    while (TI==0);        /* Wait until stop bit transmit */
    TI = 0;            /* Clear TI flag */
}

void uart_send(char *str)
{
    for(int i=0; str[i]!=0; i++)
    {
        uart_send_byte(str[i]);    /* Call transmit data function */
    }
}

void main()
{
    set_oscillator(FOSC);

    uart_init(9600);
    while(1) {
        uart_send("test\n");
        delay(1000);
    }
}
