#ifndef ISR
#define	ISR

#include <xc.h> 
#ifdef	__cplusplus
extern "C" {
#endif 
    
void __interrupt() ISR_HANDLER(void);
    
#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

