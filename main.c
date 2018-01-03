#include <pic.h>
#include "LCD.h"
#include "buttons.h"
__CONFIG( FOSC_HS & WDTE_OFF & PWRTE_ON & BOREN_OFF & LVP_OFF );

    
//void delaySeconds(int d){// 1 second
//    
//    
//    for(int i=0;i<d;i++){
//        for(int j=0;j<25000;j++);
//    }//
//}
//
//void zone0OK () {
//    clearDisplay ();
//    resetCursor ();
//    char message[] = "Zone 0 OK";
//    writeMessage(message);
//    LCDdelay2 ();
//    LCDdelay2 ();
//}
//void zone1OK () {
//    clearDisplay ();
//    resetCursor ();
//    char message[] = "Zone 1 OK";
//    writeMessage(message);
//    LCDdelay2 ();
//    LCDdelay2 ();
//}
//void zone2OK () {
//    clearDisplay ();
//    resetCursor ();
//    char message[] = "Zone 2 OK";
//    writeMessage(message);
//    LCDdelay2 ();
//    LCDdelay2 ();
//}
//void zone3OK () {
//    clearDisplay ();
//    resetCursor ();
//    char message[] = "Zone 3 OK";
//    writeMessage(message);
//    LCDdelay2 ();
//    LCDdelay2 ();
//}
//void zone0Alert (){
//    clearDisplay ();
//    resetCursor ();
//    char message[] = "Zone 0 Alert";
//    writeMessage(message);
//    LCDdelay2 ();
//    LCDdelay2 ();
//}
//void zone1Alert (){
//    clearDisplay ();
//    resetCursor ();
//    char message[] = "Zone 1 Alert";
//    writeMessage(message);
//    LCDdelay2 ();
//    LCDdelay2 ();
//}
//void zone2Alert (){
//    clearDisplay ();
//    resetCursor ();
//    char message[] = "Zone 2 Alert";
//    writeMessage(message);
//    LCDdelay2 ();
//    LCDdelay2 ();
//}
//void zone3Alert (){
//    clearDisplay ();
//    resetCursor ();
//    char message[] = "Zone 3 Alert";
//    writeMessage(message);
//    LCDdelay2 ();
//    LCDdelay2 ();
//}
//void currentTemp () {
//    clearDisplay ();
//    resetCursor ();
//    char message1[] = "Zone 0";
//    char message2[] = "Temperature:";
//    writeMessageline1(message1);
//    writeMessageline2(message2);
//    LCDdelay2 ();
//    LCDdelay2 ();
//}
//void alarmOn () {
//    clearDisplay ();
//    resetCursor ();
//    char message[] = "Alarm On";
//    writeMessage(message);
//    LCDdelay2 ();
//    LCDdelay2 ();
//}
//void alarmOff () {
//    clearDisplay ();
//    resetCursor ();
//    char message[] = "Alarm Off";
//    writeMessage(message);
//    LCDdelay2 ();
//    LCDdelay2 ();
//}
//void zone0Activate () {
//    clearDisplay ();
//    resetCursor ();
//    char message[] = "Zone 0 On";
//    writeMessage(message);
//    LCDdelay2 ();
//    LCDdelay2 ();
//}
//void zone1Activate () {
//    clearDisplay ();
//    resetCursor ();
//    char message[] = "Zone 1 On";
//    writeMessage(message);
//    LCDdelay2 ();
//    LCDdelay2 ();
//}
//void zone2Activate () {
//    clearDisplay ();
//    resetCursor ();
//    char message[] = "Zone 2 On";
//    writeMessage(message);
//    LCDdelay2 ();
//    LCDdelay2 ();
//}
//void zone3Activate () {
//    clearDisplay ();
//    resetCursor ();
//    char message[] = "Zone 3 On";
//    writeMessage(message);
//    LCDdelay2 ();
//    LCDdelay2 ();
//}
//void zone0Deactivate () {
//    clearDisplay ();
//    resetCursor ();
//    char message[] = " Zone 0 Off";
//    writeMessage(message);
//    LCDdelay2 ();
//    LCDdelay2 ();
//}
//void zone1Deactivate () {
//    clearDisplay ();
//    resetCursor ();
//    char message[] = "Zone 1 Off";
//    writeMessage(message);
//    LCDdelay2 ();
//    LCDdelay2 ();
//}
//void zone2Deactivate () {
//    clearDisplay ();
//    resetCursor ();
//    char message[] = "Zone 2 Off";
//    writeMessage(message);
//    LCDdelay2 ();
//    LCDdelay2 ();
//}
//void zone3Deactivate () {
//    clearDisplay ();
//    resetCursor ();
//    char message[] = "Zone 3 Off";
//    writeMessage(message);
//    LCDdelay2 ();
//    LCDdelay2 ();
//    
//}
//
//void timeSet () {
//    clearDisplay ();
//    resetCursor ();
//    char message[] = "Setting Time...";
//    writeMessage(message);
//    LCDdelay2 ();
//    LCDdelay2 ();
//}

void ButtonGrid () {
        
    char messagerow[] = "row:0";
    char messagecol[] = "col:0";
    LCDsetup ();

     
    clearDisplay ();
    
    while(1){
       
    if( checkButtons()){
        
 //   
    resetCursor();   

    
    
    
    messagerow[4] = row+48;
    messagecol[4] = col+48;
    writeMessageline1(messagerow);
    writeMessageline2(messagecol);
  /*  
    if (col == 4 && row == 2) {
        currentTemp ();
    }
        if (col == 1 && row == 4) {
        zone3Deactivate ();
    }
      */ 
  //  delaySeconds(2);
         
    }
    }
}

//void modeSelect () {
//    resetCursor ();
//    char messagerow[] = "Select a";
//    char messagecol[] = "Function...";
//    writeMessageline1(messagerow);
//    writeMessageline2(messagecol);
//}
//void checkMessage () {
//             clearDisplay ();
//         resetCursor ();
//            char messagerow[] = "Checking Buttons";
//    writeMessageline1(messagerow);
//}

void ActivateButtonCheck () {
    
    if (row == 1 && col == 2) {

        //checkMessage ();
    //LCDdelay2 ();

        ButtonGrid ();
    }
//    else {
//        instructions ();
//    }
}

//int alarmOnOff;
//
//void AlarmOnOff () {
//   
//    if (row == 4 && col == 4){
//            alarmOnOff = 1;
//            alarmOn ();
//            currentTemp ();
//            LCDdelay2();
//            modeSelect();
//        
//    }
//    if (row == 4 && col == 3) {
//            alarmOnOff = 0;
//            alarmOff ();
//        
//    }
//    
//}
//
//void showTemp () {
//    if (row == 3 && col == 4) {
//        currentTemp();
//    }
//}
//
//void setCurrentTime () {
//        if (row == 2 && col == 3) {
//        //add rob's code
//    }
//}
//
//
//void showTime () {
//    if (row == 2 && col == 4) {
//        //add rob's code
//    }
//}
//
//void checkZoneMessage () {
//    clearDisplay ();
//    resetCursor();
//            char messagerow[] = "Check a Zone";
//        writeMessageline1(messagerow);
//}
//
//
//void checkZones () {
//    if (row == 1 && col == 1) {
//        checkZoneMessage ();
//    
//        if (row == 1 && col == 2) {
//            // add bools for each zone that will be true if triggered
//            zone0OK();
//            zone0Alert();
//        }
//        if (row == 2 && col == 2) {
//            
//            zone1OK();
//            zone1Alert();
//        }
//        if (row == 3 && col == 2) {
//            
//            zone2OK();
//            zone2Alert();
//        }
//        if (row == 4 && col == 2) {
//            
//            zone3OK();
//            zone3Alert();
//        }
//    
//    }
//}
//
//void activateZones () {
//    if (row == 2 && col == 1) {
//        // add either loop or 4/8 more buttons
//                if (row == 1 && col == 2) {
//            // add bools for each zone that will be true if active
//            zone0Activate();
//            zone0Deactivate();
//        }
//        if (row == 2 && col == 2) {
//            
//            zone1Activate();
//            zone1Deactivate();
//        }
//        if (row == 3 && col == 2) {
//            
//            zone2Activate();
//            zone2Deactivate();
//        }
//        if (row == 4 && col == 2) {
//            
//            zone3Activate();
//            zone3Deactivate();;
//        }
//    }
//}
//
//void changeTemp () {
//    if (row == 1 && col == 2) {
//        // add code/ 2 buttons + robs
//    }
//}
//
//void changeDurationTime () {
//    if (row == 3 && col == 2) {
//        // add code/ 2 buttons + robs
//    }
//}
//
//void changeAlertTime () {
//    if (row == 3 && col == 2) {
//        // add code/ 2 buttons + robs
//    }
//}
//
//void AutoSystem () {
//    if (row == 4 && col == 2) {
//        
//    }
//}
//
//void Return () {
//    clearDisplay ();
//    resetCursor ();
//    if (row == 1 && col == 4) {
//        
//    }
//}
//
//void setTime () {
//    if (row == 1 && col == 1) {
//        timeSet();
//    }
//}



void main () {
    LCDsetup ();
    checkButtons ();
    ActivateButtonCheck ();
//    AlarmOnOff ();
//    checkZones ();
//    activateZones ();
//    showTemp();
    //setTime ();

}