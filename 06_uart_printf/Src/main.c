#include <stdint.h>
#include <stdio.h>
#include "stm32f411xe.h"
// APB1 BASE: 0x4000 0000
// APB1 RCC_APB1ENR offset: 0x40


// UNDER PORT AF07 - Type of alternate function for USART2 - Found in the datasheet searching for Alternate Functions
//USART2_TX: PA2
//USART2_RX: PA3

#define GPIOAEN			(1U<<0)
#define USART2EN		(1U<<17)

#define SYS_FREQ		16000000	// 16MHz
#define APB1_CLK		SYS_FREQ

#define	UART_BAUDRATE	115200

#define CR1_TE			(1U<<3)		// transmit with defaults. 1 stop bit, parity is even
#define CR1_UE			(1U<<13)    // UART enable

#define SR_TXE		(1U<<7)		// TXE read only, transmit data register empty when LOW


void 			uart2_write			(int ch															);
void 			uart2_tx_init		(void															);
static void 	uart_set_bd	(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t Baudrate	);
static uint16_t compute_uart_bd		(uint32_t PeriphClk, uint32_t Baudrate							);


/***********
 * In C printf() calls fputc() to print to console. STM32F4 does not have a console.
 * So something else must be done with the out printf() calls fputc().
 * __io_putchar() is a hook function that STM uses to redirect the printf() to some other use place.
 * In this case to the UART TX through the uart2_write().
***********/
int __io_putchar(int ch)
{
  uart2_write(ch);

  return ch;
}



int main(void)
{
	uart2_tx_init();

	while (1)
	{
		printf("Hello, from STM32F4........\n\r");
	}
}


void uart2_tx_init(void)
{
	/*************** Configure the GPIO pin ***************/
	/* enable clock access to GPIOA */
	RCC->AHB1ENR |= GPIOAEN;

	/* set PA2 mode to alt function mode */
	GPIOA->MODER &=~(1U<<4);
	GPIOA->MODER |= (1U<<5);

	/* set PA2 alt function type to UART_TX (AF07) (0111)(bits 8-11) */
	/* AFR has an arry of size 2, [0]for AFRL [1] for AFRH */
	GPIOA->AFR[0] |= (1U<<8);
	GPIOA->AFR[0] |= (1U<<9);
	GPIOA->AFR[0] |= (1U<<10);
	GPIOA->AFR[0] &=~(1U<<11);

	/*************** Configure the uart module ***************/
	/* enable clock access to uart2 */
	RCC->APB1ENR |= USART2EN;

	/* configure bauderate */
	uart_set_bd(USART2,SYS_FREQ, UART_BAUDRATE);

	/* configure the transfer direction */
	USART2->CR1 = CR1_TE; // Clean the UART overwrite instead of friendly programming with the |=
	/* enable the uart module */
	USART2->CR1 |= CR1_UE; // We have already configure the TE and defaults need to keep it with friendly programming |=
}

void uart2_write(int ch)
{
	/* make sure transmit data register is empty */
	while(!(USART2->SR & SR_TXE));

	/* write to transmit data register */
	USART2->DR = (ch & 0xFF);

}

static void uart_set_bd(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t Baudrate)
{
	USARTx->BRR = compute_uart_bd(PeriphClk, Baudrate); //BRR = BaudRateRegister

}

static uint16_t compute_uart_bd(uint32_t PeriphClk, uint32_t Baudrate)
{
	return (PeriphClk + (Baudrate/2U)) / Baudrate;
}
