#include <stdint.h>
#include <stdio.h>
#include "stm32f411xe.h"
#include "uart.h"


#define GPIOAEN			(1U<<0)
#define GPIOA_5			(1U<<5)
#define LED_PIN			GPIOA_5



static void uart2_callback			(void);
static void dma1_stream6_callback	(void);

char key;

int main(void)
{
	RCC->AHB1ENR |= GPIOAEN;	// enable the clock from the AHB1 bus to Port A. Write the enable bit to the Bus register0

	// set pin 5 direction. Pin 5 is bits 10 & 11 in the MODE register
	GPIOA->MODER |= (1U<<10);	// set bit 10 to 1
	GPIOA->MODER &=~(1U<<11);	// set bit 11 to 0

	uart2_rx_interrupt_init();

	while (1)
	{

	}
}


static void uart2_callback(void)
{
	key = USART2->DR;
	printf("RX INTERRUPTED....\n\r");

	if (key ==  '1')
	{
		GPIOA->ODR |=  LED_PIN;
	}
	else{
		GPIOA->ODR &=~ LED_PIN;
	}
}

void USART2_IRQHandler(void)
{
	/* check of the interrupt flag is set*/
	if(USART2->SR & SR_RXNE)
	{
		uart2_callback();
	}
}


static void dma1_stream6_callback(void)
{

}

void DMA1_Stream6_IRQHandler()
{
	dma1_stream6_callback();

}




