/*
 * File:   Stepper Motor Mod.c
 * Author: Rio
 *
 * Created on January 17, 2018, 10:55 PM
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
#define _XTAL_FREQ 8000000

unsigned char STEP1=0x99;
unsigned char STEP2=0X55;
unsigned char STEP3=0x66;
unsigned char STEP4=0xAA;

void main(void) {
    LATA=0x00;
    TRISA=0x00;
    while(1){
        LATA=STEP1;__delay_ms(1);
        LATA=STEP2;__delay_ms(1);
        LATA=STEP3;__delay_ms(1);
        LATA=STEP4;__delay_ms(1);
    }
    return;
}
