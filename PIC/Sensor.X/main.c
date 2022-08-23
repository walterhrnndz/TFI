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

/*
 * Agregar variables de control para identificar si se recibio el mensaje completo
 * Manejar las diferentes acciones segun corresponda:
 * - Encender apagar leds
 * - Enviar informacion de estado (ocupado/desocupado)
 * - Enviar informacion de distancia medida
 * - Cambiar distancia minima de deteccion
 * - Ignorar mensaje si es para otro esclavo
 * - Aceptar mensaje si es para SLAVE_ADDRESS de este dispositivo o 0x00
 * - Manejar SLAVE_ADDRESS segun lectura de los pines
 * - Configurar pines para asignar direccion al dispositivo
 */

__bit datoCompleto = 0;
__bit addressPropio = 0;

void blink(int num) {
    for (int i = 0; i < num; i++) {
        ONOFF = 1;
        __delay_ms(250);
        ONOFF = 0;
    }
}

void main(void) {
    uint16_t dist;      // Variable de distancia del objeto
    config();           // Configuracion del PIC
    iniciarUART();      // Inicia los registros para la comunicacion UART
    
    RECIBIR = 0;         // Inicializa como receptor al transciver
    RECIBIR_PIN = 0;     // Inicializa como salida el pin
    
    // Loop infinito
    while(1) {
        dist = distancia();
        (dist < MIN_DISTANCIA) ? (LED = 1) : (LED = 0); // Verificacion de la distancia para cambio de estado
        
        if(nuevoDato == 1) {
            if(dato == 'I') {
                cantDatos = 0;
                datoCompleto = 0;
                blink(3);
            }

            if(dato == 'F') {
                datoCompleto = 1;
            }

            datos[cantDatos] = dato;
            cantDatos++;
            nuevoDato = 0;
        }

        if(datoCompleto == 1) {
            if (datos[2] == SLAVE_ADDRESS) addressPropio = 1;
            else addressPropio = 0;

            if (addressPropio == 1 || datos[2] == 0) {
                // ESTRUCTURA DEL STRING DATOS: INICIO_TRAMA, ADDRESS1, ADDRESS2, FUNCION, DATO1, DATO2, FIN_TRAMA
                if(datos[5] == 'E') ONOFF = 1;
                else ONOFF = 0;
            }
            datoCompleto = 0;
        }
        
        __delay_ms(50);
    }
}