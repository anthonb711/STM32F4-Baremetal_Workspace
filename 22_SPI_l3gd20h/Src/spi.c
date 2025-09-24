#include "spi.h"

#define GPIOAEN	(1U<<0)
#define	SPI1EN	(1U<<12)
#define SPI_SS	(1U<<18) // GPIO output is [19:18] 01

void spi_gpio_init()
{
// Alternate function mapping for SPI1 = AF05
// SPI1 = APB2
// SPI1_NSS		-> PA4
// SPI1_SCK		-> PA5
// SPI1_MISO	-> PA6
// SPI1_MOSI	-> PA7
// SPI1_SS		-> PA9


//	/* enable clock access to SPI1 */
//	RCC->APB2ENR |= SPI1EN;
	/* enable clock access to GPOIA */
	RCC->AHB1ENR |= GPIOAEN;

	/* set (PA5-PA7) modes to alt function */
	GPIOA->MODER &=~(1U<<8);
	GPIOA->MODER |= (1U<<9);

	GPIOA->MODER &=~(1U<<10);
	GPIOA->MODER |= (1U<<11);

	GPIOA->MODER &=~(1U<<12);
	GPIOA->MODER |= (1U<<13);

	GPIOA->MODER &=~(1U<<14);
	GPIOA->MODER |= (1U<<15);

	/* set PA9 to output for SS */
	GPIOA->MODER |= SPI_SS;


	/* set PA4-PA7 alt function types to AF05 */
	GPIOA->AFR[0]|= (1U<<16);
	GPIOA->AFR[0]&=~(1U<<17);
	GPIOA->AFR[0]|= (1U<<18);
	GPIOA->AFR[0]&=~(1U<<19);

	GPIOA->AFR[0]|= (1U<<20);
	GPIOA->AFR[0]&=~(1U<<21);
	GPIOA->AFR[0]|= (1U<<22);
	GPIOA->AFR[0]&=~(1U<<23);


	GPIOA->AFR[0]|= (1U<<24);
	GPIOA->AFR[0]&=~(1U<<25);
	GPIOA->AFR[0]|= (1U<<26);
	GPIOA->AFR[0]&=~(1U<<27);


	GPIOA->AFR[0]|= (1U<<28);
	GPIOA->AFR[0]&=~(1U<<29);
	GPIOA->AFR[0]|= (1U<<30);
	GPIOA->AFR[0]&=~(1U<<31);

}

