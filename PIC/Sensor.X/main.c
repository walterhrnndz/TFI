/*
 * File:   main.c
 * Author: Walter
 *
 * Created on 20 de julio de 2022, 23:47
 */
#include <stdio.h>
#include "config.h"
#include "hc_sr04.h"
#include "uart.h"
#include "isr.h"

#define MIN_DISTANCIA   10
#define SLAVE_ADDRESS   10

#define CAMBIO_PIN      TRISBbits.TRISB3 // Cambio recepcion/transmision.
#define CAMBIO          PORTBbits.RB3 // Estando en 0, configura como receptor.

void main(void) {
    uint16_t dist;
    config();
    iniciarUART();
    
    CAMBIO = 0;
    CAMBIO_PIN = 0;
    
    char mensaje[80];
    
    while(1) {
        dist = distancia();
        (dist < MIN_DISTANCIA) ? (LED = 1) : (LED = 0);
        
        if(enviar == 0) {
            //sprintf(mensaje, "Distancia: %d \r\n", dist);
            //enviarCadena(mensaje);
            ONOFF = 0;
        }
        if(enviar == 1) {
            ONOFF = 1;
        }
        //enviar = 0;
        __delay_ms(250);
    }
}