/*
 * File:   Temperature.c
 * Author: robda
 *
 * Created on 05 January 2018, 16:20
 */

#include "temperature.h"
#include "LCD.h"
#include "Clock.h"
#include <pic.h>
__CONFIG( FOSC_HS & WDTE_OFF & PWRTE_ON & BOREN_OFF & LVP_OFF ); 
#define DQ RA0
#define RS RA1
#define RW RA2
#define E  RA3

void tempDelay(char x, char y)
{
    do{
        char z = y;
        do{
            ;
        }while(--z);
    }while(--x);
}

void delay()
{
    for (int i = 0; i< 500; ++i);
}
void reset()
{
    char presance = 0;
    while(!presance)
    {
        TRISA0 = 0;
        DQ = 0;
        tempDelay(2,70);
        TRISA = 1;
        tempDelay(2,8);
        if(DQ == 1)
        {
            presance = 0;
        }
        else
        {
            presance = 1;
        }
        tempDelay(2,60);
    }
}

void writeByte(char value)
{
    char temp;
    for(char i = 0; i < 8; ++i)
    {
        temp = value & 0x01;
        TRISA0 = 0;
        DQ = 0;
        NOP();
        NOP();
        NOP();
        NOP();
        NOP();
        
        if(temp == 1)
        {
            DQ = 1;
        }
        tempDelay(2,7);
        TRISA0 = 1;
        NOP();
        NOP();
        value = value>>1;
    }
}

char readByte()
{
    char i;
    char value = 0;     
    static bit j;
    for(i = 0; i < 8; i++)
    {
        value >> = 1; 
        TRISA0 = 0;
        DQ = 0;

        NOP();
        NOP();
        NOP();
        NOP();
        NOP();
        NOP();

        TRISA0 = 1;
        NOP();                                                       
        NOP();                                                       
        NOP();                                                       
        NOP();                                                       
        NOP();           
        j=DQ;                                                        
        if(j)
        {
            value|=0x80;   
        }//1000 0000      00000000      011000000                                         
        tempDelay(2,7);           
    }
    return(value);
}


//void init()
//{
//    TRISA = 0x00;
//    TRISC = 0x00;
//    TRISD = 0x00;
//    PORTA = 0x00;
//    PORTC = 0x00;
//    PORTD = 0x00;
//    ADCON1 = 0x07;
//    writeCmd(0x0F);
//    writeCmd(0x38);
//    writeCmd(0x01);
//}
void buzzer()
{
    RC2 = 1;
    delay();
    delay();
    delay();
    RC2 = 0;
}

char triggerTemp()
{
//    if (//enter button for units)
//    {
//        triggerValue = triggerValue + 1;
//    }
//    else if (//enter button for units)
//    {
//        triggerValue = triggerValue - 1;
//    }
//    else (//enter button to store the values)
//    {
//        return triggerValue;
//    }
    
}
char triggerDelay()
{
//    else if (//enter button for units)
//    {
//        triggerDelayTime = triggerDelayTime + 1;
//    }
//    else (//enter button to store the values)
//    {
//        return triggerDelayTime;
//    }
}
void getTemperature()
{
    reset();
    writeByte(0xCC); //Skip Rom
    writeByte(0x44); //Conversion
    tempDelay(2,70);
    reset();
    writeByte(0xCC); //Skip Rom
    writeByte(0xBE); //Read Scratchpad

    //Read the Low and High byte temperature values 
    tempLow = readByte();
    tempHigh = readByte();

    //Take the highest 4 bits of low Byte and lowest of high byte
    //and then combine them into one byte
    tempValue = (tempLow >> 4)| (tempHigh << 4);
    //Take the lowers 4 bits of the low byte to extract the decimal
    char decimal = tempLow << 4;

    if(tempValue > 100)
    {
        tempValue = tempValue / 100;
    }

    //Converting from BCD into Integer Values
    char tens = tempValue/10;
    char units = tempValue%10;

    //Converting from BCD into Decimal
    if(decimal & 0x80) // 0.5
    {
        decimalNumber = decimalNumber + 5000;
    }
    char tensDecimal = decimalNumber/1000;
    NOP();
    
    writeChar('\'' + tens  - 30 + '\'');
    writeChar('\'' + units - 30 + '\'');
    writeChar('.');
    writeChar('\'' + tensDecimal - 30 + '\'');
    delay();
    delay();
    if(tempValue >= triggerValue)
    {
        char currentTime = getTime();
        while(tempValue >= triggerValue)
        {
            if (currentTime + triggerDelayTime >= getTime())
            {
                buzzer();
            }
        }
    }
}