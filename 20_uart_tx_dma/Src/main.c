#include <stdint.h>
#include <stdio.h>
#include "stm32f411xe.h"
#include "uart.h"


#define GPIOAEN			(1U<<0)
#define GPIOA_5			(1U<<5)
#define LED_PIN			GPIOA_5
#define	HISR_TCIF6		(1U<<21)
#define HIFCR_CTCIF6    (1U<<21)



static void dma1_stream6_callback	(void);

char message[31] = "Hello from Stm32 DMA";
int main(void)
{
	RCC->AHB1ENR |= GPIOAEN;	// enable the clock from the AHB1 bus to Port A. Write the enable bit to the Bus register0

	// set pin 5 direction. Pin 5 is bits 10 & 11 in the MODE register
	GPIOA->MODER |= (1U<<10);	// set bit 10 to 1
	GPIOA->MODER &=~(1U<<11);	// set bit 11 to 0


	uart2_tx_init();
	dma1_stream6_init((uint32_t)message, (uint32_t)USART2->DR, 31);

	while (1)
	{

	}
}




static void dma1_stream6_callback(void)
{
	GPIOA->ODR |= LED_PIN;
}

void DMA1_Stream6_IRQHandler()
{
	if(DMA1->HISR & HISR_TCIF6)
	{
		DMA1->HIFCR |= HIFCR_CTCIF6;

		dma1_stream6_callback();
	}

}




