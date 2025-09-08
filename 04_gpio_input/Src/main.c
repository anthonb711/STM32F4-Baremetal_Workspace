#include "stm32f411xE.h"

#define GPIOAEN		(1U<<0)
#define GPIOCEN		(1U<<2)

#define PIN5		(1U<<5)
#define PIN13		(1U<<13)

#define LED_PIN		PIN5
#define BTN_PIN	    PIN13 // active low



int main(void)
{

	/* enable clock access to GPIOA & GPIOC */
	RCC->AHB1ENR |= GPIOAEN;
	RCC->AHB1ENR |= GPIOCEN;

	/* set PA5 to the output direction */
	GPIOA->MODER |=  (1U<<10);
	GPIOA->MODER &= ~(1U<<11);

	/* set PC13 to the input direction */
	GPIOC->MODER &= ~(1U<<26);
	GPIOC->MODER &= ~(1U<<27);



	while (1)
	{
		/* check if btn is pressed - User btn is active low */
		if (GPIOC->IDR & BTN_PIN)
		{
			/* turn on led */
			GPIOA->BSRR = LED_PIN;
		}
		else{
			/* turn off led*/
			GPIOA->BSRR = (1U<<21);
		}
	}
}
