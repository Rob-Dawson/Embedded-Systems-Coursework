/* 
 * File:   buttons.h
 * Author: 506142
 *
 * Created on 21 November 2017, 15:27
 */

#ifndef temperature_H
#define	temperature_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    void Delay_us(int us);
    void delay();
    void reset();
    void getTemperature();
    char triggerTemp();
    char triggerDelay();
    void writeByte(char c);
    char readByte();
    void buzzer();
   // void init();
char tempLow = 0;
char tempHigh = 0;
char tempValue = 0;
char triggerValue = 20;
char triggerDelayTime = 0;
char decimalNumber = 0;


#ifdef	__cplusplus
}
#endif

#endif	/* temperature_H */