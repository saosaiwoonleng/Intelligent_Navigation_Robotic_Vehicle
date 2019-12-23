/* 
 * File:   7 Segment.c
 * Author: Rio
 *
 * Created on January 14, 2018, 7:06 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <pic18f4550.h>
#include <p18f4550.h>
#include <xc.h>

#pragma config FOSC = INTOSCIO_EC
#pragma config WDT = OFF
#pragma config PWRT = ON
#pragma config PBADEN = ON
#pragma config MCLRE = OFF
#define _XTAL_FREQ 2000000
unsigned char const SEGMENT_MAP[10]={0x7E,0x30,0x6D,0x79,0x33,0x5B,0x1F,0x70,0x7F,0xFB};

void main(void) {
    TRISD=0*00;
    int digit=0;
    while(1)
        for (digit=0;digit<10;digit++){
            LATD = SEGMENT_MAP[digit];
            __delay_ms(10);
            __delay_ms(10);
            __delay_ms(10);
            __delay_ms(10);
        
          
          
        }
    for (digit=9;digit>0;digit++){
        LATD = SEGMENT_MAP[digit];
        __delay_ms(10);
        __delay_ms(10);
        __delay_ms(10);
        __delay_ms(10);
        
    }
    return;
}