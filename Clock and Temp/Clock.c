/*
 * File:   main.c
 * Author: robda
 *
 * Created on 24 December 2017, 16:53
 */

#define RS RA1
#define RW  RA2
#define E RA3
#define SCLK RB0
#define rst RB5
#define IO RB4

#include <pic.h>
#include "Clock.h"
#include "LCD.h"
__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_ON & BOREN_OFF & LVP_OFF);

void delayClock()
{
    for(int i = 0x64; i--;);
}

void writeTime(unsigned char timeClock)
{
    for(int i = 0; i < 8; ++i)
    {
        IO = 0; //IO must be low 
        SCLK = 0; 
        if(timeClock & 0x01)
        {
            IO = 1; //If any of the bits are one, IO = 1
        }
        timeClock = timeClock>> 1; //Bit Shift Right 
        SCLK = 1;
    }
    SCLK = 0;
}

unsigned char readTime()
{
                               //set the loop counter.  
    TRISB4=1;                         //continue to write 8bit 
    for(int j = 0; j < 8; j++)                  
    {
        SCLK=0;                       //pull low clk                   
        time_rx=time_rx>>1;           //judge the send bit is 0 or 1.  
        time_rx7=IO;                //put the received bit into the reg's highest.
        SCLK=1;                       //pull high clk                 
    }                                                              
    TRISB4=0;                        //finished 1 byte,pull low clk  
    SCLK=0;                          
    return(time_rx);    
}

void setTime()
{
    rst = 1;
    writeTime(0xbe); // Clock Burst write
    for(int i = 0; i < 8; ++i)
    {
        writeTime(table[i]);
    }
    rst = 0;
}



void getTime()
{
    rst = 1;
    writeTime(0xbf); // Clock Burst Read
    for(int i = 0; i < 7; ++i)
    {
        table1[i]=readTime();   
    }
    rst = 0;
}

char workingHours()
{
    
}

void clockInit()
{
    SCLK = 0;
    rst = 0;    
    rst = 1; //Enable Data Transfer
    writeTime(0x8E); //Control Register
    writeTime(0); //Enable write;
    rst = 0; //Terminate Data Transfer
}


void Cinit()
{
    //Configure the pins
    TRISA = 0x00;
    PORTA = 0xFF;

    TRISD = 0x00;
    PORTD = 0xFF;
    TRISB = 0x02;  
    ADCON1 = 0x06;
    writeCmd(0x0f);
    writeCmd(0x01);
    writeCmd(0x38);
}

void display()
{
    int i;
    
    if(RB1==0)                     //judge rb1.
    {
        table1[0]=table1[3];     
        table1[1]=table1[4];
        table1[2]=table1[6];
    }
    
    value = table1[0];
    if (value > 100)
    {
        value = value / 100;
    }

    char value = table1[0];
    char tens = (value >> 4)&0x07;
    char units = (value & 0x0f);
    
    char value1 = table1[1];
    char minutesTens = (value1 >> 4)&0x07;
    char minutesUnits = (value1 & 0x0f);
    
    char value2 = table1[2];
    char hoursTens = (value2 >> 4)&0x07;
    char hoursUnits = (value2 & 0x0f);
    
    NOP();
    writeChar('\'' + tens - 30 + '\'');
    writeChar('\'' + units - 30 + '\'');
    writeChar(':');
    writeChar('\'' + minutesTens - 30 + '\'');
    writeChar('\'' + minutesUnits - 30 + '\'');
    writeChar(':');
    writeChar('\'' + hoursTens - 30 + '\'');
    writeChar('\'' + hoursUnits - 30 + '\'');
    writeCmd(0x01);
}

