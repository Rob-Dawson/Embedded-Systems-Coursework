#include <pic.h>
#include "LCD.h"
__CONFIG( FOSC_HS & WDTE_OFF & PWRTE_ON & BOREN_OFF & LVP_OFF );
void LCDsetup() {
    ADCON1 = 0x06;
    TRISA = 0x00;
    PORTA = 0x00;
    TRISD = 0x00;
    PORTD = 0x00;
    displayOn ();
    turnon2linemode();
}

void LCDdelay () {
    for (unsigned i=0; i<20; i++); 
}

void LCDdelay2 () {
    for (unsigned i=0; i<50000; i++);
}
void LCDdelay3 () {
        for (unsigned i=0; i<25000; i++);
}
/*
 this writes data to lcd
 */
void writeChar (char var) {
    PORTA = 0;
    PORTD = 0;
    RA1 = 1;
    RA2 = 0;
    LCDdelay ();
    RA3 = 1;
    LCDdelay ();
    PORTD = var;
    LCDdelay ();
    RA3 = 0;
    LCDdelay ();
    
}

void writeMessage (char message[]) {
    for (int i = 0; message[i] != '\0'; i++){
        writeChar (message[i]);
 //       LCDdelay3 ();
    }
}

void writeMessageline1(char message[]){
  // writeCmd(0x80); // 1000 0000
    writeMessage(message);
}

void writeMessageline2(char message[]){
    //writeCmd(0xa0);//   1010 0000
 //   for (int y = i; y < 40; y++) {
//    writeMessage(" ");
    //writeMessage("                                   "); //35 spaces
 //   }
    
  //  resetCursor();   
    writeCmd(0x80+40);//   plus 40 DECIMAL
    writeMessage(message);
   // writeChar('a');
}

void writeCmd(char cmd){
 //   PORTA = 0;    
 //   PORTD = 0;
    RA1 = 0;
    RA2 = 0;
    LCDdelay ();
    RA3 = 1;
    LCDdelay ();
    PORTD = cmd;
    LCDdelay ();
    RA3 = 0;
    LCDdelay ();
}



void resetCursor () {
    writeCmd(0x02);
}
void displayOn () {
    writeCmd(0x0F);
}

void clearDisplay () {
    writeCmd(0x01);
}

void turnon2linemode(){
    writeCmd(0x38); // 0011 1000
}






