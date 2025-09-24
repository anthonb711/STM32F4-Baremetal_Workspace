

#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include "stm32f411xe.h"

#define SR_RXNE			(1U<<5)		// RX not empty, only try to read if data is present
#define	SR_TXE			(1U<<7)

void dma1_stream6_init			(uint32_t src, uint32_t dst, uint32_t len	);
char uart2_read					(void  										);
void uart2_tx_init				(void										);
void uart2_rx_interrupt_init	(void										);
void uart2_write				(int ch										);

#endif /* UART_H_ */
