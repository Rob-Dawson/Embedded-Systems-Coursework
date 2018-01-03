#include <pic.h>
#include "LCD.h"
#include "buttons.h"
__CONFIG( FOSC_HS & WDTE_OFF & PWRTE_ON & BOREN_OFF & LVP_OFF );


void buttonsetup () {
    ADCON1 = 0x06;
    TRISA = 0x00;
    PORTA = 0x00;
    TRISC = 0x0f;
    PORTC = 0xf0;
    TRISD = 0x00;
    PORTD = 0x00;
}
//char col;
//char row;

/*
 * no input is required
 * return: index of the key pressed
 */

//char checkButton(){
//     buttonsetup ();
//     
//}

char checkButtons () {
    
    char rval = 0;
    buttonsetup ();
    //for (;;) {
        RC4 = 0; 
        if (RC0 == 0) {
            col = 4;
            row = 1;
        }
        if (RC1 == 0) {
            col = 3;
            row = 1;
        }
        if (RC2 == 0) {
            col = 2;
            row = 1;
        }        
        if (RC3 == 0) {
            col = 1;
            row = 1;
        }
        RC4 = 1;
        
        
        RC5 = 0;
                if (RC0 == 0) {
            col = 4;
            row = 2;
        }
        else if (RC1 == 0) {
            col = 3;
            row = 2;
        }
        else if (RC2 == 0) {
            col = 2;
            row = 2;
        }        
        else if (RC3 == 0) {
            col = 1;
            row = 2;
        }
        RC5 =1;
                RC6 = 0;
                if (RC0 == 0) {
            col = 4;
            row = 3;
        }
        else if (RC1 == 0) {
            col = 3;
            row = 3;
        }
        else if (RC2 == 0) {
            col = 2;
            row = 3;
        }        
        else if (RC3 == 0) {
            col = 1;
            row = 3;
        }
        RC6 =1;
        
                RC7 = 0;
                if (RC0 == 0) {
            col = 4;
            row = 4;
        }
        else if (RC1 == 0) {
            col = 3;
            row = 4;
        }
        else if (RC2 == 0) {
            col = 2;
            row = 4;
        }        
        else if (RC3 == 0) {
            col = 1;
            row = 4;
        }
        RC7 =1;
        
        if(col==0&&row==0){
        }else{
            rval = 1;
        }
        
        
        return rval;
        
    }


void buttondelay () {
    for (unsigned i=0; i<500; i++); 
}

//void AlarmOnOffButtons () {
//    buttonsetup ();
//    for(;;)
//    {
//        RC4 = 0;
//        if (RC0 == 0) {
//            alarmOn ();
//        }
//        
//        if (RC1 == 0) {
//            alarmOff ();
//        }
//
//        RC4 = 1;
//    }
//    buttondelay ();
//
//}

