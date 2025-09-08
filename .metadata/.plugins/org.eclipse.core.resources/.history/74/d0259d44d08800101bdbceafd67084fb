
#include "stm32f411xE.h"
#include "tim.h"

#define GPIOAEN		(1U<<0)
#define	GPIOA_5		(1U<<5)
#define TIM2EN		(1U<<0)
#define CR1_CEN		(1U<<0)
#define OC_TOGGLE	((1U<<4) | (1U<<5))	// because the CCMR1 reset value is 0x000 we do not need to explicitly set bit 6 low.
#define CCER_CC1E	(1U<<0)
#define AFR5_TIM	(1U<<20) // AF01 = 0001)(AFRL5 bits 20-23) */



void tim2_1hz_init(void)
{
	/* enable clock access to tim2 */
	RCC->APB1ENR |= TIM2EN;
	/* set prescaler value */
	TIM2->PSC = 1600 -1;		// sysclk 16,000,000 / psc 1,600 = 10,000 Mhz
	/* set autoreload value */
	TIM2->ARR = 10000 -1; 		// 10,000 / 10,0000 = 1Hz
	/* clear counter */
	TIM2->CNT= 0;
	/* enable timer*/
	TIM2->CR1 |= CR1_CEN;

}

void tim2_pa5_output_compare(void)
{

	/* enable clock access to GPIOA */
	RCC->AHB1ENR |= GPIOAEN;	// enable the clock from the AHB1 bus to Port A. Write the enable bit to the Bus register

	/* PA5 direction to alternate function */
	GPIOA->MODER &=~(1U<<10);
	GPIOA->MODER |= (1U<<11);

	/* set PA5 alternate function type to TIM2_CH1 (AF01 = 0001)(AFRL5 bits 20-23) */
	GPIOA->AFR[0] |= AFR5_TIM;

	/* enable clock access to tim2 */
	RCC->APB1ENR |= TIM2EN;
	/* set prescaler value */
	TIM2->PSC = 1600 -1;		// sysclk 16,000,000 / psc 1,600 = 10,000 Mhz
	/* set autoreload value */
	TIM2->ARR = 10000 -1; 		// 10,000 / 10,0000 = 1Hz


	/* set output_compare toggle mode */

	TIM2->CCMR1 = OC_TOGGLE;

	TIM2->CCMR1 &=~ (1U<<0);
	TIM2->CCMR1 &=~ (1U<< 1);


	/* enable tim2 ch1 */
	TIM2->CCER |= CCER_CC1E;

	/* clear counter */
	TIM2->CNT= 0;
	/* enable timer*/
	TIM2->CR1 |= CR1_CEN;

}
