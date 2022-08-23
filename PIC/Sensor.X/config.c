/*
 * File:   config.c
 * Author: Walter Hernández
 *
 * Created on 21 de julio de 2022, 23:04
 */

#include "config.h"

void config(void) {
    // Deshabilita los comparadores analogicos y habilita los pines
    // Como entradas y salidas digitales.
    CMCONbits.CM = 0b111;           
    
    // Inicializacion de los pines de entrada y salida
    ONOFF_PIN   = 0;
    LED_PIN     = 0;
    TRIG_PIN    = 0;
    ECHO_PIN    = 1;
    
    // Configuracion del TIMER1
    T1CONbits.T1CKPS = 0b00;        // Prescaler = 1:1
    T1CONbits.TMR1CS = 0;           // Selecciona el oscilador interno (FOSC/4)
    
    ONOFF       = 1;

    GIE         = 1;                // Habilitacion de las interrupciones globales
    PEIE        = 1;

    cantDatos = 0;
}