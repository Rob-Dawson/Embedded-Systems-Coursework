/* 
 * File:   buttons.h
 * Author: 506142
 *
 * Created on 21 November 2017, 15:27
 */

#ifndef Clock_H
#define	Clock_H

#ifdef	__cplusplus
extern "C" {
#endif
    unsigned char time_rx @ 0x30;        //define receive reg.
    static volatile bit time_rx7 @ (unsigned)&time_rx*8+7;   //receive reg highest.

    const char table[]={0x50,0x59,0x23,0x8,0x3,0x06,0x06,0x00};
    char table1[7];      
    char value = 0;
    void Cinit();
    void delayClock();
    void writeTime(unsigned char timeClock);
    unsigned char readTime();
    void setTime();
    void getTime();
    void clockInit();
    void display();
    
#ifdef	__cplusplus
}
#endif

#endif	/* Clcok_H */

