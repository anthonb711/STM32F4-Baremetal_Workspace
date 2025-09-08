

#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include "stm32f411xe.h"

#define SR_RXNE			(1U<<5)		// RX not empty, only try to read if data is present


char uart2_read					(void  	);
void uart2_tx_init				(void	);
void uart2_write				(int ch	);
void uart2_rx_interrupt_init	(void	);




#endif /* UART_H_ */
