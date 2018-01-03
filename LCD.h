/* 
 * File:   LCD.h
 * Author: 506142
 *
 * Created on 21 November 2017, 12:38
 */

#ifndef LCD_H
#define	LCD_H

#ifdef	__cplusplus
extern "C" {
#endif
void LCDsetup();
void LCDdelay ();
void LCDdelay2 ();
void LCDdelay3 ();
void writeChar (char var);
void writeMessage (char message[]);
void resetCursor ();
void writeCmd(char cmd);
void displayOn ();
void clearDisplay ();
void turnon2linemode();
void writeMessageline2(char message[]);
void writeMessageline1(char message[]);



#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

