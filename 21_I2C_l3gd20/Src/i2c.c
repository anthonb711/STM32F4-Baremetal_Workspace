/*  i2c uses the APB1 buss at max 50Mhz
 *  Locate SDA and SCL lines for I2C1
 *  SCL -- PB8 AltFunction AF05
 *  SDA -- PB9 AltFunction AF05
 */

#include "stm32f411xe.h"
#include "i2c.h"

#define I2C1EN 	(1U<<21)
#define GPIOB	(1U<<1)



void main(void){

}


void I2C1_init(void)
{
	/* enable clock access to I2C1*/
	RCC->APB1ENR |= I2C1EN;

	/* enable clock access to GPIOB*/
	RCC->AHB1ENR |= GPIOB;


	/* set PB8 & PB9 mode to alt func */
	/* set PB8 & PB9 output type to open drain */
	/* enable the pullup for PB8 & PB9*/
}

