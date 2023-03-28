#include "stc15.h"

#ifndef _STC15_UTILS_H_
#define _STC15_UTILS_H_

void set_oscillator(unsigned long oscillator);
unsigned long get_oscillator();
void delay(unsigned int milliseconds);
unsigned int analog_read(unsigned char port);
unsigned int analog_read_speed(unsigned char port, unsigned char speed);

#endif
