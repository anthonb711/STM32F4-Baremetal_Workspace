/*  i2c uses the APB1 buss at max 50Mhz
 *  Locate SDA and SCL lines for I2C1
 *  SCL -- PB8 AltFunction AF05
 *  SDA -- PB9 AltFunction AF05
 */

#include "stm32f411xe.h"
#include "i2c.h"

#define I2C1EN 			(1U<<21)
#define GPIOBEN			(1U<<1)
#define	OTYPER_OT8		(1U<<8)
#define OTYPER_OT9		(1U<<9)
#define CR2_FREQ		(1U<<4)	// 16Mhz




void main(void){

}


void I2C1_init(void)
{

	/* enable clock access to GPIOB*/
	RCC->AHB1ENR |= GPIOBEN;

	/* set PB8 & PB9 mode to alt func */
	GPIOB->MODER &=~(1U<<16);
	GPIOB->MODER |= (1U<<17);

	GPIOB->MODER &=~(1U<<18);
	GPIOB->MODER |= (1U<<19);

	/* PB8 SCL - alt function I2C1 */
	GPIOB->AFR[1] |= (1U<<0);
	GPIOB->AFR[1] &=~(1U<<1);
	GPIOB->AFR[1] |= (1U<<2);
	GPIOB->AFR[1] &=~(1U<<3);

	/* PB9 SDA - alt function I2C1*/
	GPIOB->AFR[1] |= (1U<<4);
	GPIOB->AFR[1] &=~(1U<<5);
	GPIOB->AFR[1] |= (1U<<6);
	GPIOB->AFR[1] &=~(1U<<7);

	/* set PB8 & PB9 output type to open drain */
	GPIOB->OTYPER |= OTYPER_OT8;
	GPIOB->OTYPER |= OTYPER_OT9;

	/* enable the pullup for PB8 & PB9*/
	GPIOB->PUPDR |= (1U<<16);
	GPIOB->PUPDR &=~(1U<<17);

	GPIOB->PUPDR |= (1U<<18);
	GPIOB->PUPDR &=~(1U<<19);

	/* enable clock access to I2C1*/
	RCC->APB1ENR |= I2C1EN;


	/* enter reset mode */
	I2C1->CR1 |= (1U<<15);

	/* come out of reste*/
	I2C1->CR1 &=~(1U<<15);

	/* configure defualt clock*/
	I2C1->CR2 |= CR2_FREQ;

	/* set I2C clock mode in the CCR */
}

