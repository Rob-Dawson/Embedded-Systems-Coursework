#include <pic.h>
#include "LCD.h"
#include "buttons.h"
__CONFIG( FOSC_HS & WDTE_OFF & PWRTE_ON & BOREN_OFF & LVP_OFF );

    
void delaySeconds(int d){// 1 second
    
    
    for(int i=0;i<d;i++){
        for(int j=0;j<25000;j++);
    }//
}

// below are the ints for activating modes and certain LCD messages, they will made later methods behave differently depending on their value (0 or 1)
int alarmOnOrOff = 0;
int zoneActMode = 0;
int zoneCheck = 0;
int zone0On = 0;
int zone1On = 0;
int zone2On = 0;
int zone3On = 0;
int zone0Alerted = 0;
int zone1Alerted = 0;
int zone2Alerted = 0;
int zone3Alerted = 0;
int tempChange = 0;
int durationChange = 0;
int alertChange = 0;

// below are the ints for changing the times and temp, each one correlates to a unit of measure which will need to be converted (unless that's too difficult)
int tempValue = 0; // 1 = 0.1 degrees
int durationValue = 0; //1 = 1 min
int alertValue = 1; // 1 = 1 sec


// most of the below code is the methods for different LCD messages, check currentTemp() though
void zone0OK () {
    clearDisplay ();
    resetCursor ();
    char message[] = "Zone 0 OK";
    writeMessage(message);
    LCDdelay2 ();
    LCDdelay2 ();
}
void zone1OK () {
    clearDisplay ();
    resetCursor ();
    char message[] = "Zone 1 OK";
    writeMessage(message);
    LCDdelay2 ();
    LCDdelay2 ();
}
void zone2OK () {
    clearDisplay ();
    resetCursor ();
    char message[] = "Zone 2 OK";
    writeMessage(message);
    LCDdelay2 ();
    LCDdelay2 ();
}
void zone3OK () {
    clearDisplay ();
    resetCursor ();
    char message[] = "Zone 3 OK";
    writeMessage(message);
    LCDdelay2 ();
    LCDdelay2 ();
}
void zone0Alert (){
    clearDisplay ();
    resetCursor ();
    char message[] = "Zone 0 Alert";
    writeMessage(message);
    LCDdelay2 ();
    LCDdelay2 ();
}
void zone1Alert (){
    clearDisplay ();
    resetCursor ();
    char message[] = "Zone 1 Alert";
    writeMessage(message);
    LCDdelay2 ();
    LCDdelay2 ();
}
void zone2Alert (){
    clearDisplay ();
    resetCursor ();
    char message[] = "Zone 2 Alert";
    writeMessage(message);
    LCDdelay2 ();
    LCDdelay2 ();
}
void zone3Alert (){
    clearDisplay ();
    resetCursor ();
    char message[] = "Zone 3 Alert";
    writeMessage(message);
    LCDdelay2 ();
    LCDdelay2 ();
}
void currentTemp () {
    clearDisplay ();
    resetCursor ();
    char message1[] = "Zone 0";
    char message2[] = "Temperature:";
    writeMessageline1(message1);
    writeMessageline2(message2);
    LCDdelay2 ();
    LCDdelay2 ();
    // add thermometer code get temperature to display on LCD
    
}
void alarmOn () {
    clearDisplay ();
    resetCursor ();
    char message[] = "Alarm On";
    writeMessage(message);
    LCDdelay2 ();
    LCDdelay2 ();
}
void alarmOff () {
    clearDisplay ();
    resetCursor ();
    char message[] = "Alarm Off";
    writeMessage(message);
    LCDdelay2 ();
    LCDdelay2 ();
}
void zone0Activate () {
    clearDisplay ();
    resetCursor ();
    char message[] = "Zone 0 On";
    writeMessage(message);
    LCDdelay2 ();
    LCDdelay2 ();
}
void zone1Activate () {
    clearDisplay ();
    resetCursor ();
    char message[] = "Zone 1 On";
    writeMessage(message);
    LCDdelay2 ();
    LCDdelay2 ();
}
void zone2Activate () {
    clearDisplay ();
    resetCursor ();
    char message[] = "Zone 2 On";
    writeMessage(message);
    LCDdelay2 ();
    LCDdelay2 ();
}
void zone3Activate () {
    clearDisplay ();
    resetCursor ();
    char message[] = "Zone 3 On";
    writeMessage(message);
    LCDdelay2 ();
    LCDdelay2 ();
}
void zone0Deactivate () {
    clearDisplay ();
    resetCursor ();
    char message[] = " Zone 0 Off";
    writeMessage(message);
    LCDdelay2 ();
    LCDdelay2 ();
}
void zone1Deactivate () {
    clearDisplay ();
    resetCursor ();
    char message[] = "Zone 1 Off";
    writeMessage(message);
    LCDdelay2 ();
    LCDdelay2 ();
}
void zone2Deactivate () {
    clearDisplay ();
    resetCursor ();
    char message[] = "Zone 2 Off";
    writeMessage(message);
    LCDdelay2 ();
    LCDdelay2 ();
}
void zone3Deactivate () {
    clearDisplay ();
    resetCursor ();
    char message[] = "Zone 3 Off";
    writeMessage(message);
    LCDdelay2 ();
    LCDdelay2 ();
    
}

//void timeSet () {
//    clearDisplay ();
//    resetCursor ();
//    char message[] = "Setting Time...";
//    writeMessage(message);
//    LCDdelay2 ();
//    LCDdelay2 ();
//}

void ButtonGrid () { // The button test method for checking which one is pressed
        
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

void modeSelect () { // used later on in alarmOnOff
    resetCursor ();
    char messagerow[] = "Select a";
    char messagecol[] = "Function...";
    writeMessageline1(messagerow);
    writeMessageline2(messagecol);
}
void checkMessage () { // used below in activateButtonCheck
             clearDisplay ();
         resetCursor ();
            char messagerow[] = "Checking Buttons";
    writeMessageline1(messagerow);
}

void activateButtonCheck () {
    
    if (row == 1 && col == 2) {

        checkMessage ();
    LCDdelay2 ();

        ButtonGrid ();
    }
//    else {
//        instructions ();
//    }
}


void alarmOnOff () { //turning the alarm on and off; the alarmOnOff int will be used to make sure the function can only be done if the alarm is on
   
    if (row == 4 && col == 4){
            alarmOnOrOff = 1;
            alarmOn ();
            LCDdelay2();
            modeSelect();
        
    }
    if (row == 4 && col == 3) {
            alarmOnOrOff = 0;
            alarmOff ();
        
    }
    
}

void showTemp () { // button that calls the method for showing the temperature
    if (row == 3 && col == 4) {
        currentTemp();
    }
}

void setCurrentTime () { // setting the current time
        if (row == 2 && col == 3) {
        //add Clock set code
    }
}


void showTime () { // displaying current time
    if (row == 2 && col == 4) {
        //add clock code and display on LCD
    }
}

void checkZoneMessage () { // used in checkzones method
    clearDisplay ();
    resetCursor();
            char messagerow[] = "Check a Zone";
        writeMessageline1(messagerow);
}


void checkZones () { // sets it to zone check mode; the following buttons will show the status of the zones
    if (row == 1 && col == 1) {
        checkZoneMessage ();
        zoneCheck = 1;
        if (zoneCheck == 1) {
            if (row == 1 && col == 2) {
                if(zone0Alerted == 0) {
                   zone0OK();
                }
                if (zone0Alerted== 1) {
                    zone0Alert();
                }
            }
            if (row == 2 && col == 2) {

                if(zone1Alerted == 0) {
                   zone1OK();
                }
                if (zone1Alerted== 1) {
                    zone1Alert();
                }
            }
            if (row == 3 && col == 2) {

                if(zone2Alerted == 0) {
                   zone2OK();
                }
                if (zone2Alerted== 1) {
                    zone2Alert();
                }
            }
            if (row == 4 && col == 2) {

                if(zone3Alerted == 0) {
                   zone3OK();
                }
                if (zone3Alerted== 1) {
                    zone3Alert();
                }
            }
        }
    }
}

void activateZones () { // sets it to activate/deactivate mode; the following buttons will activate or deactivate the zones
    if (row == 2 && col == 1) {
        zoneActMode = 1;
            if (zoneActMode == 1) {
                    if (row == 1 && col == 2) {
                    if (zone0On == 0) {
                        zone0Activate();
                        zone0On = 1;
                    }
                    if (zone0On == 1) {
                        zone0Deactivate();
                        zone0On = 0;
                    }

            }
            if (row == 2 && col == 2) {
                    if (zone1On == 0) {
                        zone1Activate();
                        zone1On = 1;
                    }
                    if (zone1On == 1) {
                        zone1Deactivate();
                        zone1On = 0;
                    }
            }
            if (row == 3 && col == 2) {
                    if (zone2On == 0) {
                        zone2Activate();
                        zone2On = 1;
                    }
                    if (zone2On == 1) {
                        zone2Deactivate();
                        zone2On = 0;
                    }
            }
            if (row == 4 && col == 2) {
                    if (zone3On == 0) {
                        zone3Activate();
                        zone3On = 1;
                    }
                    if (zone3On == 1) {
                        zone3Deactivate();
                        zone3On = 0;
                   }
            }
        }
    }
}

void changeTemp () { // sets it to changing trigger temperature mode; the following buttons will change the trigger temperature int value (see the ints at the top)
    if (row == 1 && col == 2) {
        // add code/ 2 buttons + robs
        tempChange = 1;
        if (tempChange == 1) {
            if (row == 1 && col == 3) {
                  tempValue ++; 
                }
            if (row == 2 && col == 3) {
                  tempValue --;
            }
        }
    }
}

void changeDurationTime () { // sets it to changing duration time mode; the following buttons will change the duration time int value (see the ints at the top)
    if (row == 2 && col == 2) {
        // add code/ 2 buttons + robs
        durationChange = 1;
        if (durationChange == 1) {
            if (row == 2 && col == 3) {
                if (durationValue <30) {
                  durationValue ++; 
                }
                if (durationValue = 30) {
                  durationValue = 0;
                }
            }
        }
    }
}

void changeAlertTime () { // sets it to changing alert time mode; the following buttons will change the alert time int value (see the ints at the top)
    if (row == 3 && col == 2) {
        // add code/ 2 buttons + robs
        alertChange = 1;
        if (alertChange == 1) {
            if (row == 3 && col == 3) {
                if (alertValue <60) {
                  alertValue ++; 
                }
                if (alertValue = 60) {
                  alertValue = 0;
                }
            }
        }
    }
}

void AutoSystem () { // the function for the alarm being on between 8:00 and 19:30
    if (row == 4 && col == 2) {
        //clock code needed
    }
}

void Return () {  // returns from any button mode allowing another one to be picked
    clearDisplay ();
    resetCursor ();
    if (row == 1 && col == 4) {
        zoneActMode = 0;
        zoneCheck = 0;
        tempChange = 0;
        durationChange = 0;
        alertChange = 0;
    }
}



void main () {
    LCDsetup ();
    checkButtons ();
    //activateButtonCheck ();
    alarmOnOff ();
    if (alarmOnOrOff == 1) {
        checkZones ();
        activateZones ();
        //showTemp();
    }

}