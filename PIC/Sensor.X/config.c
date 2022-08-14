/*
 * File:   config.c
 * Author: Walter
 *
 * Created on 21 de julio de 2022, 23:04
 */

#include "config.h"

void config(void) {
    CMCONbits.CM = 0b111;           // Turn comparator off and enable pins for digital I/O functions
    
    ONOFF_PIN   = 0;
    LED_PIN     = 0;
    TRIG_PIN    = 0;
    ECHO_PIN    = 1;
    
    // TIMER1 Configuration
    T1CONbits.T1CKPS = 0b00;        // Prescaler = 1:1
    T1CONbits.TMR1CS = 0;           // Select internal clock (FOSC/4)
    
    ONOFF       = 1;
    
    GIE         = 1;
    PEIE        = 1;
}