#ifndef UART
#define	UART

#include <xc.h> 
#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */
    
#include "config.h"
#define BAUDRATE 9600

void iniciarUART(void);
void enviarByte(unsigned char);
unsigned char recibirByte(void);
void enviarCadena(const unsigned char*);
    
#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

