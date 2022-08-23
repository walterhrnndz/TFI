#include "isr.h"
#include "uart.h"
#include "config.h"

void __interrupt() ISR_HANDLER(void) {
    if(RCIF){ 
        if(OERR) {
            CREN = 0;
            CREN = 1;
        }
        dato = RCREG;
        nuevoDato = 1;
    }
}