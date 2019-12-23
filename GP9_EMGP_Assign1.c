/*
 * File:   INTE.c
 * Author: Sao Sai Woon Leng
 *
 * Created on January 2, 2018, 3:55 PM
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
#define OS PORTCbits.RC4
#define sensor PORTCbits.RC0
#define sensor1 PORTCbits.RC1
#define sensor2 PORTCbits.RC2
unsigned char STEP1 = 0x03; //stepper motor steps 
unsigned char STEP2 = 0x06;
unsigned char STEP3 = 0x0C;
unsigned char STEP4 = 0x09;
unsigned char const SEGMENT_MAP[10]={0x7E,0x30,0x6D,0x79,0x33,0x5B,0x5F,0x70,0x7F,0xFB};


 unsigned char cnt=0;
unsigned char A = 0xFF;
unsigned char Z = 0x00;


void motor_forward_front()  
{
    LATA=0x00;
    TRISA=0x00;//configure port A as output for left stepper motor
    LATB=0x00;// initialize port B output 00
    TRISB=0x00;
LATA = STEP4;
__delay_ms(1);
LATA = STEP3;
__delay_ms(1);
LATA = STEP2;
__delay_ms(1);
LATA = STEP1;
__delay_ms(1);

LATB = STEP1;
__delay_ms(1);
LATB = STEP2;
__delay_ms(1);
LATB = STEP3;
__delay_ms(1);
LATB = STEP4;
__delay_ms(1);
}
void motor_reverse_back()  //move backward
{
    LATA=0x00;
    TRISA=0x00;//configure port A as output for left stepper motor
    LATB=0x00;// initialize port B output 00
    TRISB=0x00;

LATA = STEP1;
__delay_ms(1);
LATA = STEP2;
__delay_ms(1);
LATA = STEP3;
__delay_ms(1); 
LATA = STEP4;
__delay_ms(1);

LATB = STEP4;
__delay_ms(1);
LATB = STEP3;
__delay_ms(1);
LATB = STEP2;
__delay_ms(1);
LATB = STEP1;
__delay_ms(1);
}

void motor_turn_left()  //turn left
{
LATB=0x00;// initialize port B output 00
    TRISB=0x00;
LATB = STEP1;
__delay_ms(1);
LATB = STEP2;
__delay_ms(1);
LATB = STEP3;
__delay_ms(1);
LATB = STEP4;
__delay_ms(1);
}

void motor_turn_right() //turn right 
{
LATA=0x00;
    TRISA=0x00;
LATA = STEP4;
__delay_ms(1);
LATA = STEP3;
__delay_ms(1);
LATA = STEP2;
__delay_ms(1);
LATA = STEP1;
__delay_ms(1);

}
/*void Seg_Buz()    //function for 7segment counting and buzzer
{
    TRISD =0x00;//7 seg
    TRISC = 0xFF;//buzz
    unsigned char SEGMENT[10]={0x7E,0x30,0x6D,0x79,0x33,0x5B,0x1F,0x70,0x7F,0xFB};
}*/
void main(void)
{
    LATA=0x00;// initialize port A output 00
    TRISA=0x00;//configure port A as output for left stepper motor
    LATB=0x00;// initialize port B output 00
    TRISB=0x00;//configure port B as output for right stepper motor
    TRISC=0xff;//configure port E as proximity sensor
    //TRISD=0x00;//configure port D as output for 7 segments
   // LATD=0x00;//initialize port D as 7 segments 
   //TRISC=0x01;//configure port C as output for buzzer and optical sensor
    //unsigned char cnt=0;
    //unsigned char segment[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
  // cnt = 0;
    while(1)
    {
        /*if(OS==1)//optical sensor//detect black
        {
            LATC=A;//A all 00000000s for buzzer on
            LATD= segment[cnt];
            cnt++;
            if(cnt==0)
                cnt=0;
            __delay_ms(50);
        }
        if(OS==0)//detect white
        {
            LATC=Z;//Z all 1111111s for buzzer off
        } */
        if(sensor==1 && sensor1==1 && sensor2==1)//1 means no detection @ front , left ,right proximity sensor 
        {
            /*unsigned char x,y;
            for(y=0;y<200;y++)
            {
                for(x=0;x<150;x++)
                    __delay_ms(1);*/
                motor_forward_front();
            //}
        }
        else if(sensor1==0 && sensor==0 && sensor2==0)//all proximity sensor detect
                {
                   /* unsigned char x,y;
                    for(y=0;y<200;y++)
                    {
                        for(x=0;x<150;x++)
                            __delay_ms(1);*/
                        motor_reverse_back();
                    //}
                }
        else if(sensor1==0 && sensor==0 && sensor2==1)//left and front proximity sensor detect
                {
                   /* unsigned char x,y;
                    for(y=0;y<200;y++)
                    {
                        for(x=0;x<150;x++)
                            __delay_ms(1);*/
                        motor_turn_right();
                        //motor_forward_front();
                    //}
                }
        else if(sensor1==0 && sensor==1 && sensor2==0)// right and front proximity sensor detect
                {
                    /*unsigned char x,y;
                    for(y=0;y<200;y++)
                    {
                        for(x=0;x<150;x++)
                            __delay_ms(1);*/
                        motor_turn_left();
                       // motor_forward_front();
                    }
                
    }