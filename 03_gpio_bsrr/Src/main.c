#include "stm32f411xe.h"


#define GPIOAEN		(1U<<0)
#define PIN5		(1U<<5)
#define LED_PIN		PIN5

int main(void)
{

	RCC->AHB1ENR |= GPIOAEN;	// enable the clock from the AHB1 bus to Port A. Write the enable bit to the Bus register0

		/* set pin 5 direction. Pin 5 is bits 10 & 11 in the MODE register */
		GPIOA->MODER |= (1U<<10);	// set bit 10 to 1
		GPIOA->MODER &=~(1U<<11);	// set bit 11 to 0


	/* loop is just a delay/pause for the while loop. State of ODR will stay in a state while the for loop runs
	 * then when finished, the while loop with run again changing the the ODR state and delay again*/
	while(1)
	{

		GPIOA->BSRR = LED_PIN; // bit 5 on the bit set/reset register is the set bit for pin5 - high for ON
		for(int i = 0; i< 100000; i++){}

		GPIOA->BSRR = (1U<<21); // bit 21 on the bit set/reset register is the reset bit for pin5. High for OFF
		for(int i = 0; i< 1000000; i++){}
	}
}
