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

__CONFIG(FOSC_HS & WDTE_OFF & PWRTE_ON & BOREN_OFF & LVP_OFF);
unsigned char time_rx @ 0x30;        //define receive reg.
static volatile bit time_rx7 @ (unsigned)&time_rx*8+7;   //receive reg highest.

const char table[]={0x50,0x59,0x23,0x8,0x3,0x06,0x06,0x00}; //These are the preset clock values, the time showing is 50:59:23 followed by the date

char table1[7];      
char value = 0;
void delay()
{
    for(int i = 0x64; i--;);
}

void writeCmd(char c)
{
    RS = 0;
    RW = 0;
    E = 0;
    
    delay();
    
    E = 1;
    
    PORTD = c;
    
    delay();
    E = 0;
}

void writeData(char c)
{
    RS = 1;
    RW = 0;
    E = 0;
    
    delay();
    
    E = 1;
    
    PORTD = c;
    
    delay();
    E = 0;
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
        timeClock = timeClock >> 1; //Bit Shift Right 
        SCLK = 1;
    }
    SCLK = 0;
}

unsigned char readTime()
{                           
    TRISB4 = 1;                         //continue to write 8bit 
    for(int j = 0; j < 8; ++j)                  
    {
        SCLK = 0;                                     
        time_rx=time_rx >> 1;         
        time_rx7 = IO;                //put the received bit into the reg's highest.
        SCLK = 1;                                     
    }                                                           
    TRISB4 = 0;                         
    SCLK = 0;                          
    return (time_rx);    
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



void clockInit()
{
    SCLK = 0;
    rst = 0;    
    rst = 1; //Enable Data Transfer
    writeTime(0x8E); //Control Register
    //writeTime(0); //Enable write;
    rst = 0; //Terminate Data Transfer
}


void init()
{
    //Configure the pins
    TRISA = 0x00;
    PORTA = 0xFF;

    TRISD = 0x00;
    PORTD = 0xFF;
    TRISB=0X02;  
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
    writeData('\'' + tens - 30 + '\'');
    writeData('\'' + units - 30 + '\'');
    writeData(':');
    writeData('\'' + minutesTens - 30 + '\'');
    writeData('\'' + minutesUnits - 30 + '\'');
    writeData(':');
    writeData('\'' + hoursTens - 30 + '\'');
    writeData('\'' + hoursUnits - 30 + '\'');
}

void main()
{
    init();
    clockInit();
    setTime();
    while(1)
    {
        writeCmd(0x01); //Clear LCD 
        getTime();
        display();
    }
}
