#include <xc.h> 
#ifndef CONFIG
#define CONFIG

// PIC16F628A Configuration Bit Settings
// 'C' source line config statements
// CONFIG

#pragma config FOSC     = INTOSCCLK     // Oscillator Selection bits (INTOSC oscillator: CLKOUT function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE     = OFF           // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE    = OFF           // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE    = OFF           // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
#pragma config BOREN    = OFF           // Brown-out Detect Enable bit (BOD disabled)
#pragma config LVP      = OFF           // Low-Voltage Programming Enable bit (RB4/PGM pin has digital I/O function, HV on MCLR must be used for programming)
#pragma config CPD      = OFF           // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP       = OFF           // Flash Program Memory Code Protection bit (Code protection off)

#define _XTAL_FREQ 4000000
#include <math.h>

#define LED_PIN         TRISAbits.TRISA0
#define LED             PORTAbits.RA0
#define ONOFF_PIN       TRISAbits.TRISA1    // Encendido - Apagado
#define ONOFF           PORTAbits.RA1
#define TRIG_PIN        TRISAbits.TRISA2    // TRIG pin
#define TRIG            PORTAbits.RA2
#define ECHO_PIN        TRISAbits.TRISA3    // ECHO pin
#define ECHO            PORTAbits.RA3
#define RECIBIR_PIN     TRISBbits.TRISB3    // Estando en 0, configura como receptor.
#define RECIBIR         PORTBbits.RB3       // Cambio estado entre recepcion/transmision.

#define MIN_DISTANCIA   10                  // Distancia minima para activar el sensor
#define SLAVE_ADDRESS   2                   // Identificador del esclavo, cambiar para cada PIC
                                            // Variable temporal hasta asignar por pines
__bit enviar = 0;
__bit nuevoDato = 0;
unsigned char dato;
unsigned char datos[15];
unsigned int cantDatos;

void config(void);

#endif    /* CONFIG */