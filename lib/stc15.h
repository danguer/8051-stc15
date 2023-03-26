/*
MIT License

Copyright (c) 2023 Daniel Guerrero

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/*
 * Reference Document
 * http://www.stcmcudata.com/datasheet/stc/STC-AD-PDF/STC15-English.pdf
*/

#ifndef _STC15_H_
#define _STC15_H_

#include <8051.h>

#ifdef REG8051_H
#undef REG8051_H
#endif

/*
 * Serial Port 4 (UART4) Control Register
 *   Bit Mapping: S4SM0 S4ST3 S4SM2 S4REN S4TB8 S4RB8 S4TI S4RI
 *   Reset Value: 0000,0000
 */
__sfr __at (0x84) S4CON;

/*
 * Serial port 4 Data Buffer register
 *   Reset Value: xxxx,xxxx
 */
__sfr __at (0x85) S4BUF;

/*
 * Auxiliary Register
 *   Bit Mapping: T0x12 T1x12 UART_M0x6 BRTR S2SMOD BRTx12 EXTRAM S1BRS
 *   Reset Value: 0000,0000
 */
__sfr __at (0x8E) AUXR;

/*
 * CLK_Output and External Interrupt enable register
 *   Bit Mapping: - EX4 EX3 EX2 - T2CLKO T1CLKO T0CLKO
 *   Reset Value: x000,x000
 */
__sfr __at (0x8F) INT_CLKO;

/* Ports configuration */
__sfr __at (0x91) P1M1;
__sfr __at (0x92) P1M0;
__sfr __at (0x93) P0M1;
__sfr __at (0x94) P0M0;
__sfr __at (0x95) P2M1;
__sfr __at (0x96) P2M0;

/*
 * Clock Division register
 *   Bit Mapping: MCKO_S1 MCKO_S0 ADRJ Tx_Rx MCLKO_2 CLKS2 CLKS1 CLKS0
 *   Reset Value: 0000,0000
 */
__sfr __at (0x97) CLK_DIV;

/*
 * The Control Register for the 2nd Serial Communication Port
 *   Bit Mapping: S2SM0 - S2SM2 S2REN S2TB8 S2RB8 S2TI S2RI
 *   Reset Value: 0x00,0000
 */
__sfr __at (0x9A) S2CON;

/* Data Buffer Register for the 2nd Serial Communication Port */
__sfr __at (0x9B) S2BUF;

/*
 * Dedicated Baud-Rate Timer
 *   Reset Value: 0x00,0000
 */
__sfr __at (0x9C) BRT;


/*
 * P1 Analog Special Function
 *   Bit Mapping: P17ASF P16ASF P15ASF P14ASF P13ASF P12ASF P11ASF P10ASF
 *   Reset Value: 0000,0000
 */
__sfr __at (0x9D) P1ASF;

/*
 * Bus-Speed Control
 *   Bit Mapping: - - - - - - EXRTS[1:0]
 *   Reset Value: xxxx,xx10
 */
__sfr __at (0xA1) BUS_SPEED;

/*
 * Auxiliary register1
 *   Bit Mapping: S1_S1 S1_S0 CCP_S1 CCP_S0 SPI_S1 SPI_S0 - DPS
 *   Reset Value: 0100,0000
 */
__sfr __at (0xA2) AUXR1;

/*
 * Slave Address
 *   Reset Value: 0000,0000
 */
__sfr __at (0xA9) SADDR;

/*
 * Slave Address
 *   Reset Value: 1111,1111
 */
__sfr __at (0xAA) WKTCL;

/*
 * Slave Address
 *   Bit Mapping: WKTEN - - - - - - -
 *   Reset Value: 0111,1111
 */
__sfr __at (0xAB) WKTCH;

/*
 * The Control Register for the 3nd Serial Communication Port
 *   Bit Mapping: S3SM0 S3ST3 S3SM2 S3REN S3TB8 S3RB8 S3TI S3RI
 *   Reset Value: 0x00,0000
 */
__sfr __at (0xAC) S3CON;

/* Data Buffer Register for the 3nd Serial Communication Port */
__sfr __at (0xAD) S3BUF;

/*
 * Interrupt Enable 2
 *   Bit Mapping: - ET4 ET3 ES4 ES3 ET2 ESPI ES2
 *   Reset Value: x000,0000
 */
__sfr __at (0xAF) IE2;

/* Ports configuration */
__sfr __at (0xB1) P3M1;
__sfr __at (0xB2) P3M0;
__sfr __at (0xB3) P4M1;
__sfr __at (0xB4) P4M0;

/*
 * 2rd Interrupt Priority Low register
 *   Bit Mapping: - - - - - - PSPI PS2
 *   Reset Value: xxxx,xx00
 */
__sfr __at (0xB5) IP2;

/*
 * Slave Address Mask
 *   Reset Value: 0000,0000
 */
__sfr __at (0xB9) SADEN;

/*
 * Peripheral Function Switch register 2
 *   Bit Mapping: - - - - - S4_S S3_S S2_S
 *   Reset Value: xxxx,x000
 */
__sfr __at (0xBA) P_SW2;

/*
 * ADC Control
 *   Bit Mapping: ADC_POWER SPEED1 SPEED0 ADC_FLAG ADC_START CHS2 CHS1 CHIS0
 *   Reset Value: 0000,0000
 */
__sfr __at (0xBC) ADC_CONTR;

/*
 * ADC Result
 *   Reset Value: 0000,0000
 */
__sfr __at (0xBD) ADC_RES;

/*
 * ADC Result Low
 *   Reset Value: 0000,0000
 */
__sfr __at (0xBE) ADC_RESL;

/*
 * Port 4
 *   Bit Mapping: P4.7 P4.6 P4.5 P4.4 P4.3 P4.2 P4.1 P4.0
 *   Reset Value: 1111,1111
 */
__sfr __at (0xC0) P4;

/*
 * Watch-Dog-Timer Control Register
 *   Bit Mapping: WDT_FLAG - EN_WDT CLR_WDT IDLE_WDT PS2 PS1 PS0
 *   Reset Value: xx00,0000
 */
__sfr __at (0xC1) WDT_CONTR;

/*
 * ISP/IAP Flash Data Register
 *   Reset Value: 1111,1111
 */
__sfr __at (0xC2) IAP_DATA;

/*
 * ISP/IAP Flash Address High
 *   Reset Value: 0000,0000
 */
__sfr __at (0xC3) IAP_ADDRH;

/*
 * ISP/IAP Flash Address Low
 *   Reset Value: 0000,0000
 */
__sfr __at (0xC4) IAP_ADDRL;

/*
 * ISP/IAP Flash Command Register
 *   Bit Mapping: - - - - - - MS1 MS0
 *   Reset Value: xxxx,xx00
 */
__sfr __at (0xC5) IAP_CMD;

/*
 * ISP/IAP Flash Command Trigger
 *   Reset Value: xxxx,xxxx
 */
__sfr __at (0xC6) IAP_TRIG;

/*
 * ISP/IAP Control Register
 *   Bit Mapping: IAPEN SWBS SWRST CMD_FAIL - WT2 WT1 WT0
 *   Reset Value: 0000,x000
 */
__sfr __at (0xC7) IAP_CONTR;

/*
 * Port 5
 *   Bit Mapping: - - P5.5 P5.4 P5.3 P5.2 P5.1 P5.0
 *   Reset Value: xxxx,1111
 */
__sfr __at (0xC8) P5;

/* Ports configuration */
__sfr __at (0xC9) P5M1;
__sfr __at (0xCA) P5M0;
__sfr __at (0xCB) P6M1;
__sfr __at (0xCC) P6M0;

/*
 * SPI Status register
 *   Bit Mapping: SPIF WCOL - - - - - -
 *   Reset Value: 00xx,xxxx
 */
__sfr __at (0xCD) SPSTAT;

/*
 * SPI Control register
 *   Bit Mapping: SSIG SPEN DORD MSTR CPOL CPHA SPR1 SPR0
 *   Reset Value: 0000,0100
 */
__sfr __at (0xCE) SPCTL;

/*
 * SPI Data register
 *   Reset Value: 0000,0000
 */
__sfr __at (0xCF) SPDAT;

/*
 * T4 and T3 mode register
 *   Bit Mapping: T4R T4_C/T T4x12 T4CLKO T3R T3_C/T T3x12 T3CLKO
 *   Reset Value: 0000,0000
 */
__sfr __at (0xD1) T4T3M;

/*
 * Timer 4 high 8-bit register
 *   Reset Value: 0000,0000
 */
__sfr __at (0xD2) T4H;

/*
 * Timer 4 low 8-bit register
 *   Reset Value: 0000,0000
 */
__sfr __at (0xD3) T4L;

/*
 * Timer 3 high 8-bit register
 *   Reset Value: 0000,0000
 */
__sfr __at (0xD4) T3H;

/*
 * Timer 3 low 8-bit register
 *   Reset Value: 0000,0000
 */
__sfr __at (0xD5) T3L;

/*
 * Timer 2 high 8-bit register
 *   Reset Value: 0000,0000
 */
__sfr __at (0xD6) T2H;

/*
 * Timer 2 low 8-bit register
 *   Reset Value: 0000,0000
 */
__sfr __at (0xD7) T2L;

/*
 * PCA Control Register
 *   Bit Mapping: CF CR - - CCF3 CCF2 CCF1 CCF0
 *   Reset Value: 00xx,0000
 */
__sfr __at (0xD8) CCON;

/*
 * PCA Mode Register
 *   Bit Mapping: CIDL - - - CPS2 CPS1 CPS0 ECF
 *   Reset Value: 00xx,0000
 */
__sfr __at (0xD9) CMOD;

/*
 * PCA Module 0 Mode Register
 *   Bit Mapping: - ECOM0 CAPP0 CAPN0 MAT0 TOG0 PWM0 ECCF0
 *   Reset Value: x000,0000
 */
__sfr __at (0xDA) CCAPM0;

/*
 * PCA Module 1 Mode Register
 *   Bit Mapping: - ECOM1 CAPP1 CAPN1 MAT1 TOG1 PWM1 ECCF1
 *   Reset Value: x000,0000
 */
__sfr __at (0xDB) CCAPM1;

/*
 * PCA Module 2 Mode Register
 *   Bit Mapping: - ECOM2 CAPP2 CAPN2 MAT2 TOG2 PWM2 ECCF2
 *   Reset Value: x000,0000
 */
__sfr __at (0xDB) CCAPM2;

/* Ports configuration */
__sfr __at (0xE1) P7M1;
__sfr __at (0xE2) P7M0;

/*
 * Port 6
 */
__sfr __at (0xE8) P6;

/*
 * PCA Base Timer Low
 *   Reset Value: 0000,0000
 */
__sfr __at (0xE9) CL;

/*
 * PCA module 0 capture register low
 *   Reset Value: 0000,0000
 */
__sfr __at (0xEA) CCAP0L;

/*
 * PCA module 1 capture register low
 *   Reset Value: 0000,0000
 */
__sfr __at (0xEB) CCAP1L;

/*
 * PCA module 2 capture register low
 *   Reset Value: 0000,0000
 */
__sfr __at (0xEC) CCAP2L;

/*
 * PCA PWM Mode Auxiliary Register 0
 *   Bit Mapping: EBS0_1 EBS0_0 - - - - EPC0H EPC0L
 *   Reset Value: xxxx,xx00
 */
__sfr __at (0xF2) PCA_PWM0;

/*
 * PCA PWM Mode Auxiliary Register 1
 *   Bit Mapping: EBS1_1 EBS1_0 - - - - EPC1H EPC1L
 *   Reset Value: xxxx,xx00
 */
__sfr __at (0xF3) PCA_PWM1;

/*
 * PCA PWM Mode Auxiliary Register 2
 *   Bit Mapping: EBS2_1 EBS2_0 - - - - EPC2H EPC2L
 *   Reset Value: xxxx,xx00
 */
__sfr __at (0xF4) PCA_PWM2;

/*
 * Port 6
 */
__sfr __at (0xF8) P7;

/*
 * PCA Base Timer High
 *   Reset Value: 0000,0000
 */
__sfr __at (0xF9) CH;

/*
 * PCA Module-0 Capture Register High
 *   Reset Value: 0000,0000
 */
__sfr __at (0xFA) CCAP0H;

/*
 * PCA Module-1 Capture Register High
 *   Reset Value: 0000,0000
 */
__sfr __at (0xFB) CCAP1H;

/*
 * PCA Module-2 Capture Register High
 *   Reset Value: 0000,0000
 */
__sfr __at (0xFC) CCAP2H;

/*  BIT Register  */
/* P4 */
__sbit __at (0xC0) P4_0;
__sbit __at (0xC1) P4_1;
__sbit __at (0xC2) P4_2;
__sbit __at (0xC3) P4_3;
__sbit __at (0xC4) P4_4;
__sbit __at (0xC5) P4_5;
__sbit __at (0xC6) P4_6;
__sbit __at (0xC7) P4_7;

/* P5 */
__sbit __at (0xC8) P5_0;
__sbit __at (0xC9) P5_1;
__sbit __at (0xCA) P5_2;
__sbit __at (0xCB) P5_3;
__sbit __at (0xCC) P5_4;
__sbit __at (0xCD) P5_5;
__sbit __at (0xCE) P5_6;
__sbit __at (0xCF) P5_7;

/* P6 */
__sbit __at (0xE8) P6_0;
__sbit __at (0xE9) P6_1;
__sbit __at (0xEA) P6_2;
__sbit __at (0xEB) P6_3;
__sbit __at (0xEC) P6_4;
__sbit __at (0xED) P6_5;
__sbit __at (0xEE) P6_6;
__sbit __at (0xEF) P6_7;

/* P7 */
__sbit __at (0xF8) P7_0;
__sbit __at (0xF9) P7_1;
__sbit __at (0xFA) P7_2;
__sbit __at (0xFB) P7_3;
__sbit __at (0xFC) P7_4;
__sbit __at (0xFD) P7_5;
__sbit __at (0xFE) P7_6;
__sbit __at (0xFF) P7_7;

/* CCON */
__sbit __at (0xD8) CF;
__sbit __at (0xD9) CR;
__sbit __at (0xDC) CCF3;
__sbit __at (0xDD) CCF2;
__sbit __at (0xDE) CCF1;
__sbit __at (0xDF) CCF0;

#endif
