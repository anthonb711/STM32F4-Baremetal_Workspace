

#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include "stm32f411xe.h"


char uart2_read		(void  );
void uart2_tx_init	(void  );
void uart2_rxtx_init(void  );
void uart2_write	(int ch);




#endif /* UART_H_ */
