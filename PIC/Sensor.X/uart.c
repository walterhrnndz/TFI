#include <xc.h> 
#include "uart.h"

void iniciarUART(void) {
    TRISB2  = 0;
    TRISB1  = 1;
    
    SPBRG   = ((_XTAL_FREQ / 16) / BAUDRATE) - 1;
    BRGH    = 1;
    SYNC    = 0;
    SPEN    = 1;
    CREN    = 1;
    SREN    = 0;
    TXIE    = 0;
    RCIE    = 1;
    TX9     = 0;
    RX9     = 0;
    TXEN    = 0;
    TXEN    = 1;
}

void enviarByte(unsigned char Byte) {
    while(!TXIF);
    TXREG = Byte;
}

void enviarCadena(const unsigned char* cadena) {
    while(*cadena) enviarByte(*cadena++);
}

unsigned char recibirByte(void) {
    if(OERR) {
        CREN = 0;
        CREN = 1;
    }
    
    while(!RCIF);
    
    return RCREG;
}