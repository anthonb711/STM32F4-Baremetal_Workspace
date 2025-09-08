#include "stm32f411xE.h"


#define GPIOAEN			(1U<<0)
#define GPIOA_5			(1U<<5)
#define LED_PIN			GPIOA_5

int main(void)
{

	RCC->AHB1ENR |= GPIOAEN;	// enable the clock from the AHB1 bus to Port A. Write the enable bit to the Bus register0

		// set pin 5 direction. Pin 5 is bits 10 & 11 in the MODE register
		GPIOA->MODER |= (1U<<10);	// set bit 10 to 1
		GPIOA->MODER &=~(1U<<11);	// set bit 11 to 0

	while(1)
	{
		// toggle pin 5 on and off in the Output Data Register
		GPIOA->ODR ^= LED_PIN;	// "^=" is the toggle operator

		/* loop is just a wait/pause for the while loop. State of ODR will stay in a state while the for loop runs
		 * then when finished, the while loop with run again changing the the ODR state and wait again*/
		for(int i = 0; i< 100000; i++){}
	}
}
