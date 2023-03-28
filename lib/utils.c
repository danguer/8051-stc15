#include "utils.h"
static unsigned long _oscillator = 0;

void set_oscillator(unsigned long oscillator)
{
    _oscillator = oscillator;
}

unsigned long get_oscillator()
{
    return _oscillator;
}

void run_timer_cycle(unsigned int cycle)
{
    // set timer0 mode 1 (16 bit mode)
    TMOD = 0x01;

    // set timer to cycle part
    TL0 = cycle & 0xFF;
    TH0 = cycle >> 8;

    // start the timer
    TR0 = 0x1;

    // wait until timer flag is raised
    while(!TF0);

    // stop timer and clear flag
    TR0 = 0x0;
    TF0 = 0x0;
}

void delay(unsigned int milliseconds)
{
    // in 8051 each instruction takes 12 cycles
    // so the oscillator (FOSC) divided by 12000
    // will give the number of cycles to run per millisecond
    // 12000 = 12 cycles * 1000us

    unsigned long total_cycles_counter = _oscillator/12000 * milliseconds;

    unsigned int total_cycles = total_cycles_counter >> 16;
    unsigned int remain_cycles = 0xFFFF - (total_cycles_counter & 0xFFFF);

    // run a full cycle
    for (int i=0; i<total_cycles; i++) {
        run_timer_cycle(0x0);
    }

    // check if run partial cycle
    if (remain_cycles > 0) {
        run_timer_cycle(remain_cycles);
    }
}

/* port must be 0-7 */
unsigned int analog_read(unsigned char port)
{
    return analog_read_speed(port, 0x00);
}

/* speed must be b00 - b11 */
unsigned int analog_read_speed(unsigned char port, unsigned char speed)
{
    unsigned int adc_value;

    /* value from 0-7 or b000 - b111 */
    unsigned char bits_port = port;
    P1ASF = 0x01 << port;

    // reset speed, bitmask = ~(b0110,0000) = b11001,1111
    ADC_CONTR &= ~(0x60);

    // set other values
    ADC_CONTR = ADC_POWER | ADC_START | bits_port | (speed << 5);

    // documentation says it needs four nops
    __asm
    nop
    nop
    nop
    nop
    __endasm;

    // wait until flag is ready
    while (!(ADC_CONTR & ADC_FLAG));

    // calculate the value
    adc_value = (ADC_RES << 2) | (ADC_RESL & 0x3);

    // reset the flag
    ADC_CONTR &= ~ADC_FLAG;

    return adc_value;
}
