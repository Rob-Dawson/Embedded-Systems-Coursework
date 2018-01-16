#include <pic.h>
#include "LCD.h"
#include "buttons.h"
#include "clock.h"
#include "temperature.h"
__CONFIG( FOSC_HS & WDTE_OFF & PWRTE_ON & BOREN_OFF & LVP_OFF );

    
void delaySeconds(int d){// 1 second
    
    
    for(int i=0;i<d;i++){
        for(int j=0;j<25000;j++);
    }//
}

// below are the ints for activating modes and certain LCD messages, they will made later methods behave differently depending on their value (0 or 1)
char alarmOnOrOff = 0;
char zoneActMode = 0;
char zoneCheck = 0;
char zone0On = 0;
char zone1On = 0;
char zone2On = 0;
char zone3On = 0;
char zone0Alerted = 0;
char zone1Alerted = 0;
char zone2Alerted = 0;
char zone3Alerted = 0;
char tempChange = 0;
char timeChange = 0;
char dateChange = 0;
char durationChange = 0;
char alertChange = 0;
char delayChange = 0;

// below are the ints for changing the times and temp, each one correlates to a unit of measure which will need to be converted
char TriggerTemp = 0; // 1 = 1 degree
char durationValue = 0; //1 = 1 min
char alertValue = 1; // 1 = 1 sec
char delayValue = 0;


// most of the below code is the methods for different LCD messages, check currentTemp() though
void zone0OK () {
    clearDisplay ();
    resetCursor ();
    char message[] = "Zone 0 OK";
    writeMessage(message);
    LCDdelay3 ();
}
void zone1OK () {
    clearDisplay ();
    resetCursor ();
    char message[] = "Zone 1 OK";
    writeMessage(message);
    LCDdelay3 ();
}
void zone2OK () {
    clearDisplay ();
    resetCursor ();
    char message[] = "Zone 2 OK";
    writeMessage(message);
    LCDdelay3 ();
}
void zone3OK () {
    clearDisplay ();
    resetCursor ();
    char message[] = "Zone 3 OK";
    writeMessage(message);
    LCDdelay3 ();
}
void zone0Alert (){
    clearDisplay ();
    resetCursor ();
    char message[] = "Zone 0 Alert";
    writeMessage(message);
    LCDdelay3 ();
}
void zone1Alert (){
    clearDisplay ();
    resetCursor ();
    char message[] = "Zone 1 Alert";
    writeMessage(message);
    LCDdelay3 ();
}
void zone2Alert (){
    clearDisplay ();
    resetCursor ();
    char message[] = "Zone 2 Alert";
    writeMessage(message);
    LCDdelay3 ();
}
void zone3Alert (){
    clearDisplay ();
    resetCursor ();
    char message[] = "Zone 3 Alert";
    writeMessage(message);
    LCDdelay3 ();
}
void currentTemp () {
    clearDisplay ();
    resetCursor ();
    char message1[] = "Zone 0";
    char message2[] = "Temperature:";
    writeMessageline1(message1);
    writeMessageline2(message2);
    LCDdelay3 ();
    // add thermometer code get temperature to display on LCD
    
}
void alarmOn () {
    clearDisplay ();
    resetCursor ();
    char message[] = "Alarm On";
    writeMessage(message);
    LCDdelay3 ();
}
void alarmOff () {
    clearDisplay ();
    resetCursor ();
    char message[] = "Alarm Off";
    writeMessage(message);
    LCDdelay3 ();
}
void zone0Activate () {
    clearDisplay ();
    resetCursor ();
    char message[] = "Zone 0 On";
    writeMessage(message);
    LCDdelay3 ();
}
void zone1Activate () {
    clearDisplay ();
    resetCursor ();
    char message[] = "Zone 1 On";
    writeMessage(message);
    LCDdelay3 ();
}
void zone2Activate () {
    clearDisplay ();
    resetCursor ();
    char message[] = "Zone 2 On";
    writeMessage(message);
    LCDdelay3 ();
}
void zone3Activate () {
    clearDisplay ();
    resetCursor ();
    char message[] = "Zone 3 On";
    writeMessage(message);
    LCDdelay3 ();
}
void zone0Deactivate () {
    clearDisplay ();
    resetCursor ();
    char message[] = "Zone 0 Off";
    writeMessage(message);
    LCDdelay3 ();
}
void zone1Deactivate () {
    clearDisplay ();
    resetCursor ();
    char message[] = "Zone 1 Off";
    writeMessage(message);
    LCDdelay3 ();
}
void zone2Deactivate () {
    clearDisplay ();
    resetCursor ();
    char message[] = "Zone 2 Off";
    writeMessage(message);
    LCDdelay3 ();
}
void zone3Deactivate () {
    clearDisplay ();
    resetCursor ();
    char message[] = "Zone 3 Off";
    writeMessage(message);
    LCDdelay3 ();
    
}
void zoneActivate () {
    clearDisplay ();
    resetCursor ();
    char message[] = "Zone";
    writeMessage(message);
    LCDdelay3 ();
    
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
//void checkMessage () { // used below in activateButtonCheck
//    clearDisplay ();
//    resetCursor ();
//    char messagerow[] = "Checking Buttons";
//    writeMessageline1(messagerow);
//}

//void activateButtonCheck () {
//    
//    if (row == 1 && col == 2) {
//
//        //checkMessage ();
//    LCDdelay2 ();
//
//        ButtonGrid ();
//    }
//    else {
//        instructions ();
////    }
//}


void alarmOnOff () { //turning the alarm on and off; the alarmOnOff int will be used to make sure the function can only be done if the alarm is on
   
    if (row == 4 && col == 4){
            alarmOnOrOff = 1;
            alarmOn ();
            LCDdelay2();
            modeSelect();
        
    }
    if (row == 3 && col == 4) {
            alarmOnOrOff = 0;
            alarmOff ();
        
    }
    
}

void showTemp () { // button that calls the method for showing the temperature
    if (row == 2 && col == 4) {
//        char messagetemp[] = "Temp:x";
//    LCDsetup ();
//    clearDisplay ();
//    while(1){
       
    getTemperature();
//    resetCursor();   
//    
//    messagetemp[5] = tempValue+48;
//    writeMessageline1(messagetemp);
//    LCDdelay2();
    
    
   // }
    }
}

//void setCurrentTime () { // setting the current time
//        if (row == 4 && col == 1) {
//        //add Clock set code
//    }
//}


void showTime () { // displaying current time
    if (row == 4 && col == 2) {
        if (zoneActMode == 0 && tempChange == 0 && delayChange == 0 && timeChange == 0 && dateChange == 0 && zoneCheck == 0) {
        clockInit();
        Cinit();
        setTime();
        while (1) {
        getTime();
        display();
        }
        }
    }
}
void showDate () { // displaying current time
    if (row == 3 && col == 2) {
        if (zoneActMode == 0 && tempChange == 0 && delayChange == 0 && timeChange == 0 && dateChange == 0 && zoneCheck == 0) {
        clockInit();
        Cinit();
        setTime();
        while (1) {
        getTime();
        displayDate();
        }
    }
}
}

void checkZoneMessage () { // used in checkzones method
    clearDisplay ();
    resetCursor();
    char messagerow[] = "Check";
    writeMessageline1(messagerow);
    LCDdelay3 ();
}
void changeTriggerMessage () {
    clearDisplay ();
    resetCursor();
    char messagerow[] = "Change Temp";
    writeMessageline1(messagerow);
    LCDdelay3 ();
}
//void changeTimeMessage () {
//    clearDisplay ();
//    resetCursor();
//    char messagerow[] = "Change Time";
//    writeMessageline1(messagerow);
//    LCDdelay3 ();
//}
//void changeDateMessage () {
//    clearDisplay ();
//    resetCursor();
//    char messagerow[] = "Change Date";
//    writeMessageline1(messagerow);
//    LCDdelay3 ();
//}


void checkZones () { // sets it to zone check mode; the following buttons will show the status of the zones
    if (row == 1 && col == 1) {
        if (zoneActMode == 0 && tempChange == 0 && tempChange == 0 && delayChange == 0 && timeChange == 0 && dateChange == 0) {
            checkZoneMessage ();
            zoneCheck = 1;
            
            //LCDdelay2();
            
        //writeMessageline1(zoneCheck);
        }
    }
}
            
    void checkZones2 () {        
            //if (zoneCheck == 1) {
                if (row == 1 && col == 2) {
                    if(zone0Alerted == 0) {
                        //writeChar("1");
                       zone0OK();
                    }
                    if (zone0Alerted == 1) {
                        zone0Alert();
                    }
                }
                if (row == 2 && col == 2) {

                    if(zone1Alerted == 0) {
                       zone1OK();
                    }
                    if (zone1Alerted == 1) {
                        zone1Alert();
                    }
                }
                if (row == 3 && col == 2) {

                    if(zone2Alerted == 0) {
                       zone2OK();
                    }
                    if (zone2Alerted == 1) {
                        zone2Alert();
                    }
                }
                if (row == 4 && col == 2) {

                    if(zone3Alerted == 0) {
                       zone3OK();
                    }
                    if (zone3Alerted == 1) {
                        zone3Alert();
                    }
                }
            }
       // }
    //}
//}

void activateZonesMode () { // sets it to activate/deactivate mode; the following buttons will activate or deactivate the zones
    if (row == 2 && col == 1) {
        if (zoneCheck == 0 && tempChange == 0 && tempChange == 0 && delayChange == 0 && timeChange == 0 && dateChange == 0) {
            zoneActivate();
            zoneActMode = 1;
        }
    }   
}
void activateZones () { // sort this bit out
                if (zoneActMode == 1) {
                        if (row == 1 && col == 2) {
                            if (zone0On == 0) {
                                zone0Activate();
                                zone0On = 1;
                            }
                }       
                if (row == 2 && col == 2) {
                    if (zone1On == 0) {
                        zone1On = 1;
                            zone1Activate();
                            
                        }
                        }
                if (row == 3 && col == 2) {
                        if (zone2On == 0) {
                            zone2Activate();
                            zone2On = 1;
                        }
                }
                if (row == 4 && col == 2) {
                        if (zone3On == 0) {
                            zone3Activate();
                            zone3On = 1;
                        }
                }  
            }
}
        
void deactivateZones () { // sort this bit out
                if (zoneActMode == 1) {
                    if (row == 1 && col == 3) {
                    if (zone0On == 1) {
                        zone0Deactivate();
                        zone0On = 0;
                    }
                }    
                if (row == 2 && col == 3) {
                    if (zone1On == 1) {
                        zone1Deactivate();
                        zone1On = 0;
                            
                        }
                        }
                if (row == 3 && col == 3) {
                        if (zone2On == 1) {
                            zone2Deactivate();
                            zone2On = 0;
                        }
                }
                if (row == 4 && col == 3) {
                        if (zone3On == 1) {
                            zone3Deactivate();
                            zone3On = 0;
                        }
                }  
            }
}

void changeTempMode () { // sets it to changing trigger temperature mode; the following buttons will change the trigger temperature int value (see the ints at the top)
    if (row == 1 && col == 2) {
        // add code/ 2 buttons + robs
        if (zoneActMode == 0 && zoneCheck == 0 && tempChange == 0 && delayChange == 0 && timeChange == 0 && dateChange == 0) {
            changeTriggerMessage ();
            tempChange = 1;
        }
    }
}
void changeTemp () {
    char tens = TriggerTemp/10;
char units = TriggerTemp%10;
            if (tempChange == 1) {
                if (row == 1 && col == 3) {
                      TriggerTemp ++; 
   LCDsetup ();
    clearDisplay ();
    resetCursor();       
    writeChar('\'' + tens - 30 + '\'');
    writeChar('\''+units-30+'\'');
    LCDdelay2();
    LCDdelay2();
    }
            }
    
                    
                if (row == 2 && col == 3) {
                      TriggerTemp --;
                         LCDsetup ();
    clearDisplay ();
    resetCursor();       
    writeChar('\'' + tens - 30 + '\'');
    writeChar('\''+units-30+'\'');
    LCDdelay2();
    LCDdelay2();
                }
            }
 void changeTimeMode () { // sets it to changing trigger temperature mode; the following buttons will change the trigger temperature int value (see the ints at the top)
    if (row == 3 && col == 3) {
        // add code/ 2 buttons + robs
        if (zoneActMode == 0 && zoneCheck == 0 && durationChange == 0 && alertChange == 0  && tempChange == 0 && delayChange == 0 && dateChange == 0) {
            timeChange = 1;
        }
    }
}
void changeTime () {
    char sectens = table1[0]/10;
char secunits = table1[0]%10;
    char mintens = table1[1]/10;
char minunits = table1[1]%10;
    char hourtens = table1[2]/10;
char hourunits = table1[2]%10;
            if (timeChange == 1) {
                if (row == 1 && col == 3) {
                      table1[0] ++; 
   LCDsetup ();
    clearDisplay ();
    resetCursor();       
    writeChar('\'' + sectens - 30 + '\'');
    writeChar('\''+secunits-30+'\'');
    LCDdelay2();
    LCDdelay2();
    }
            
    
                    
                if (row == 2 && col == 3) {
                      table1[0] --;
                         LCDsetup ();
    clearDisplay ();
    resetCursor();       
    writeChar('\'' + sectens - 30 + '\'');
    writeChar('\''+secunits-30+'\'');
    LCDdelay2();
    LCDdelay2();
                }
                
                
                                if (row == 1 && col == 2) {
                      table1[1] ++; 
   LCDsetup ();
    clearDisplay ();
    resetCursor();       
    writeChar('\'' + mintens - 30 + '\'');
    writeChar('\''+minunits-30+'\'');
    LCDdelay2();
    LCDdelay2();
    }
            
    
                    
                if (row == 2 && col == 2) {
                      table1[1] --;
                         LCDsetup ();
    clearDisplay ();
    resetCursor();       
    writeChar('\'' + mintens - 30 + '\'');
    writeChar('\''+minunits-30+'\'');
    LCDdelay2();
    LCDdelay2();
                }
                
                
                                if (row == 1 && col == 1) {
                      table1[2] ++; 
   LCDsetup ();
    clearDisplay ();
    resetCursor();       
    writeChar('\'' + hourtens - 30 + '\'');
    writeChar('\''+hourunits-30+'\'');
    LCDdelay2();
    LCDdelay2();
    }
            
    
                    
                if (row == 2 && col == 1) {
                      table1[2] --;
                         LCDsetup ();
    clearDisplay ();
    resetCursor();       
    writeChar('\'' + hourtens - 30 + '\'');
    writeChar('\''+hourunits-30+'\'');
    LCDdelay2();
    LCDdelay2();
                }
            }
}
    
void changeDateMode () { // sets it to changing trigger temperature mode; the following buttons will change the trigger temperature int value (see the ints at the top)
    if (row == 4 && col == 3) {
        // add code/ 2 buttons + robs
        if (zoneActMode == 0 && zoneCheck == 0 && durationChange == 0 && alertChange == 0 && tempChange == 0 && timeChange == 0 && delayChange == 0) {
            dateChange = 1;
        }
    }
}
void changeDate () {
    char daytens = table1[3]/10;
char dayunits = table1[3]%10;
    char montens = table1[4]/10;
char monunits = table1[4]%10;
    char yeartens = table1[6]/10;
char yearunits = table1[6]%10;
            if (dateChange == 1) {
                if (row == 1 && col == 3) {
                      table1[3] ++; 
   LCDsetup ();
    clearDisplay ();
    resetCursor();       
    writeChar('\'' + daytens - 30 + '\'');
    writeChar('\''+dayunits-30+'\'');
    LCDdelay2();
    LCDdelay2();
    }
            
    
                    
                if (row == 2 && col == 3) {
                      table1[3] --;
                         LCDsetup ();
    clearDisplay ();
    resetCursor();       
    writeChar('\'' + daytens - 30 + '\'');
    writeChar('\''+dayunits-30+'\'');
    LCDdelay2();
    LCDdelay2();
                }
                
                
                                if (row == 1 && col == 2) {
                      table1[4] ++; 
   LCDsetup ();
    clearDisplay ();
    resetCursor();       
    writeChar('\'' + montens - 30 + '\'');
    writeChar('\''+monunits-30+'\'');
    LCDdelay2();
    LCDdelay2();
    }
            
    
                    
                if (row == 2 && col == 2) {
                      table1[4] --;
                         LCDsetup ();
    clearDisplay ();
    resetCursor();       
    writeChar('\'' + montens - 30 + '\'');
    writeChar('\''+monunits-30+'\'');
    LCDdelay2();
    LCDdelay2();
                }
                
                
                                if (row == 1 && col == 1) {
                      table1[6] ++; 
   LCDsetup ();
    clearDisplay ();
    resetCursor();       
    writeChar('\'' + yeartens - 30 + '\'');
    writeChar('\''+yearunits-30+'\'');
    LCDdelay2();
    LCDdelay2();
    }
            
    
                    
                if (row == 2 && col == 1) {
                      table1[6] --;
                         LCDsetup ();
    clearDisplay ();
    resetCursor();       
    writeChar('\'' + yeartens - 30 + '\'');
    writeChar('\''+yearunits-30+'\'');
    LCDdelay2();
    LCDdelay2();
                }
            }
}


//void changeDurationTimeMode () { // sets it to changing duration time mode; the following buttons will change the duration time int value (see the ints at the top)
//    if (row == 2 && col == 2) {
//        // add code/ 2 buttons + robs
//        if (zoneActMode == 0 && zoneCheck == 0 && tempChange == 0 && alertChange == 0) {
//            durationChange = 1;
//        }
//    }
//}
//void changeDurationTime () {
//            if (durationChange == 1) {
//                if (row == 2 && col == 3) {
//                    if (durationValue <30) {
//                      durationValue ++; 
//                    }
//                    if (durationValue == 30) {
//                      durationValue = 0;
//                    }
//                }
//            }
//        }


//void changeAlertTimeMode () { // sets it to changing alert time mode; the following buttons will change the alert time int value (see the ints at the top)
//    if (row == 3 && col == 2) {
//        // add code/ 2 buttons + robs
//        if (zoneActMode == 0 && zoneCheck == 0 && tempChange == 0 && durationChange == 0) {
//            alertChange = 1;
//        }
//    }
//}
/*void changeAlertTime () {
    
            if (alertChange == 1) {
                if (row == 3 && col == 3) {
                    if (alertValue <60) {
                      alertValue ++; 
                    }
                    if (alertValue == 60) {
                      alertValue = 0;
                    }
                }
            }
        }*/
void changeDelayMode () { // sets it to changing trigger temperature mode; the following buttons will change the trigger temperature int value (see the ints at the top)
    if (row == 3 && col == 1) {
        // add code/ 2 buttons + robs
        if (zoneActMode == 0 && zoneCheck == 0 && tempChange == 0 && delayChange == 0 && timeChange == 0 && dateChange == 0) {
            delayChange = 1;
        }
    }
}
void changeDelay () {
    char tens = delayValue/10;
char units = delayValue%10;
            if (tempChange == 1) {
                if (row == 1 && col == 2) {
                      delayValue ++; 
   LCDsetup ();
    clearDisplay ();
    resetCursor();       
    writeChar('\'' + tens - 30 + '\'');
    writeChar('\''+units-30+'\'');
    LCDdelay2();
    LCDdelay2();
    }
            }
    
                    
                if (row == 2 && col == 2) {
                      delayValue --;
                         LCDsetup ();
    clearDisplay ();
    resetCursor();       
    writeChar('\'' + tens - 30 + '\'');
    writeChar('\''+units-30+'\'');
    LCDdelay2();
    LCDdelay2();
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

void buzzer2() {
    RB7 = 1;
    delay();
    delay();
    delay();
    RB7 =0;
}
void init() {
    TRISB = 0;
}

void main () {
    LCDsetup ();
    while(1){
    checkButtons ();
    //activateButtonCheck ();
    alarmOnOff ();
    //if (alarmOnOrOff == 1) {
     //checkButtons ();
        checkZones ();
        //activateZones ();
        if (zoneCheck == 1)
        {
            checkZones2();
        }
        activateZonesMode();
        
        if (zoneActMode == 1)
        {
            activateZones();
            deactivateZones();
        }
        changeTempMode ();
        if (tempChange == 1){
            changeTemp();
        }
                changeTimeMode ();
        if (timeChange == 1){
            changeTime();
        }
        changeDateMode ();
        if (dateChange == 1){
            changeDate();
        } 
                                
        changeDelayMode();
        if (delayChange == 1) {
            changeDelay();
        }
        showTemp();
        showTime();
        showDate();
       
        Return ();
        init();
        if (tempValue >= TriggerTemp) {
            if (zone0On == 1) {
                zone0Alerted = 1;
                    delaySeconds(delayValue);
                buzzer2();
            }
        }
    }
}