#include "stc15.h"

#ifndef _STC15_SERIAL_H_
#define _STC15_SERIAL_H_

void uart_init(unsigned long baudrate);
void uart_send_byte(char tx_data);
void uart_send(char *str);

#endif
