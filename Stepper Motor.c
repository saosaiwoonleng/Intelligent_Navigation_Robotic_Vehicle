/*
 * File:   Stepper Motor.c
 * Author: Rio
 *
 * Created on January 17, 2018, 10:22 PM
 */


#include <xc.h>
#include <p18f4550.h>

#pragma config FOSC = INTOSCIO_EC
#pragma config WDT = OFF
#pragma config PWRT = ON
#pragma config PBADEN = ON
#pragma config MCLRE = OFF

#define _XTAL_FREQ 2000000

void main(void)
{
    TRISAbits.TRISA0=0;   
    TRISAbits.TRISA1=0;   
    TRISAbits.TRISA2=0;
    TRISAbits.TRISA3=0;

    while(1)
    {
        LATAbits.LATA0=1; 
        LATAbits.LATA1=0;
        LATAbits.LATA2=0;
        LATAbits.LATA3=0;
__delay_ms(50);

        LATAbits.LATA0=0; 
        LATAbits.LATA1=1; 
        LATAbits.LATA2=0;
        LATAbits.LATA3=0;

__delay_ms(50);

        LATAbits.LATA0=0; 
        LATAbits.LATA1=0; 
        LATAbits.LATA2=1; 
        LATAbits.LATA3=0;

__delay_ms(50);
        LATAbits.LATA0=0;
        LATAbits.LATA1=0;
        LATAbits.LATA2=0;
        LATAbits.LATA3=1; 
__delay_ms(50);
// delayzz();
    }
}
