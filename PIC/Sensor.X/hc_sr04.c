/*
 * File:   hc_sr04.c
 * Author: Walter
 *
 * Created on 21 de julio de 2022, 23:01
 */

#include "config.h"
#include "hc_sr04.h"

uint16_t distancia(void) {
    uint16_t timer;
    
    TMR1H = TMR1L = 0;              // Reset TIMER1 values
    
    // Send 10us pulse to TRIG pin
    TRIG = 1;
    __delay_us(10);
    TRIG = 0;
        
    while(!ECHO);                   // Wait for ECHO pin goes to HIGH
    T1CONbits.TMR1ON = 1;           // Enable TIMER1 module
    
    while(ECHO);                    // Wait for ECHO pin goes to LOW
    T1CONbits.TMR1ON = 0;           // Disable TIMER1 module
        
    timer = (TMR1H << 8) | TMR1L;   // Read TIMER1 values
    timer = timer / 58.8235;        // Calculate distance
    
    return timer;
}