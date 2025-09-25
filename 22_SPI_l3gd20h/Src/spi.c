#include "spi.h"

#define GPIOAEN				(1U<<0)
#define	SPI1EN				(1U<<12)
#define SPI_CR1_CPHA		(1U<<0)
#define SPI_CR1_CPOL		(1U<<1)
#define SPI_CR1_SPE			(1U<<6)
#define SPI_CR1_RXONLY		(1U<<10)
#define SPI_CR1_LSBFIRST	(1U<<7)
#define SPI_CR1_LSBFIRST	(1U<<2)
#define SPI_CR1_DFF			(1U<<11)
#define SPI_CR1_SSI			(1U<<8)
#define SPI_CR1_SSM			(1U<<9)
#define SPI_SR_TXE			(1U<<1)
#define SPI_SR_RXNE			(1U<<0)
#define SPI_SR_BSY			(1U<<7)



// Alternate function mapping for SPI1 = AF05
// SPI1_NSS		-> PA4
// SPI1_SCK		-> PA5
// SPI1_MISO	-> PA6
// SPI1_MOSI	-> PA7
// SPI1_SS		-> PA9

void spi_gpio_init(void)
{
	/* enable clock access to GPOIA */
	RCC->AHB1ENR |= GPIOAEN;

	/* set (PA5-PA7) modes to alt function */
	/* PA5 */
	GPIOA->MODER &=~(1U<<10);
	GPIOA->MODER |= (1U<<11);
	/* PA6 */
	GPIOA->MODER &=~(1U<<12);
	GPIOA->MODER |= (1U<<13);
	/* PA7 */
	GPIOA->MODER &=~(1U<<14);
	GPIOA->MODER |= (1U<<15);

	/* set PA9 mode to output for SS */
	GPIOA->MODER |= (1U<<18);
	GPIOA->MODER &=~(1U<<19);


	/* set PA5-PA7 alt function types to AF05 */
	/* PA5 */
	GPIOA->AFR[0]|= (1U<<20);
	GPIOA->AFR[0]&=~(1U<<21);
	GPIOA->AFR[0]|= (1U<<22);
	GPIOA->AFR[0]&=~(1U<<23);
	/* PA6 */
	GPIOA->AFR[0]|= (1U<<24);
	GPIOA->AFR[0]&=~(1U<<25);
	GPIOA->AFR[0]|= (1U<<26);
	GPIOA->AFR[0]&=~(1U<<27);
	/* PA7 */
	GPIOA->AFR[0]|= (1U<<28);
	GPIOA->AFR[0]&=~(1U<<29);
	GPIOA->AFR[0]|= (1U<<30);
	GPIOA->AFR[0]&=~(1U<<31);
}

void spi1_config(void)
{
	/* enable clock access to SPI1 */
	RCC->APB2ENR |= SPI1EN;
	/* set baud rate to fPCLK/4 = 4Mhz*/
	SPI1->CR1 |= (1U<<3);
	SPI1->CR1 &=~(1U<<4);
	SPI1->CR1 &=~(1U<<5);

	/* set SCL mode */
	SPI1->CR1 |= SPI_CR1_CPHA;	// scl is idle when HIGH
	SPI1->CR1 |= SPI_CR1_CPOL;	// 2nd clock trans is the first data capture edge

	/* enable full duplex */
	SPI1->CR1 &=~SPI_CR1_RXONLY;

	/* set MSB first */
	SPI1->CR1 &=~SPI_CR1_LSBFIRST;

	/* set master mode */
	SPI1->CR1 |= SPI_CR1_MSTR;

	/* set data frame format - 8bit */
	SPI1->CR1 &=~SPI_CR1_DFF;

	/* set NSS to work in software mode */
	SPI1->CR1 |= SPI_CR1_SSM;
	SPI1->CR1 |= SPI_CR1_SSI;

	/* enable the SPI module */
	SPI1->CR1 |= SPI_CR1_SPE;
}


void spi1_transmit(uint8_t *data, uint32_t size)
{
	uint32_t i = 0;
	uint8_t tmp;

	while(i<size)
	{
		/* wait until TXE empty = 1 */
		while(!(SPI1->SR & SPI_SR_TXE)){}

		/* write data to data register */
		SPI1->DR = data[i];
		i++;
	}

	/* wait for TXE is be empty */
	while(!(SPI1->SR & (SPI_SR_TXE))){}

	/* wait for the busy flag to reset */
	while(SPI1->SR & (SPI_SR_BSY)){}

	/* clear overflow flag */
	tmp = SPI1->DR;
	tmp = SPI1->SR;

}

void spi1_receive(uint8_t *data, uint32_t size)
{
	uint32_t i = 0;
	uint8_t tmp;

	while(size)
	{
		/* send dummy data */
		SPI1->DR = 0;

		/* wait until RXNE is set */
		while(!(SPI1->SR & (SPI_SR_RXNE))){}

		/* write data to data register */
		*data++ = (SPI1->DR);
		i--;
	}
}


void cs_enable(void)
{
	/* set PA9 LOW to enable */
	GPIOA->ODR &=~(1U<<9);
}

void cs_disable(void)
{
	/* set PA9 HIGH to disable */
	GPIOA->ODR |= (1U<<9);
}












