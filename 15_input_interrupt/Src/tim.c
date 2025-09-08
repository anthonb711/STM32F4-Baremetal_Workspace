
#include "stm32f411xE.h"
#include "tim.h"

#define GPIOAEN			(1U<<0)
#define	GPIOA_5			(1U<<5)
#define GPIOA_6			(1U<<6)

#define TIM2EN			(1U<<0)
#define TIM3EN			(1U<<1)

#define CR1_CEN			(1U<<0)
#define OC_TOGGLE		((1U<<4) | (1U<<5))	// because the CCMR1 reset value is 0x000 we do not need to explicitly set bit 6 low.
#define IC_EVERY_EDGE	((1U<<) | (1U<<))
#define CCER_CC1E		(1U<<0)
#define CC1S_IC			(1U<<0)

#define AFR5_TIM		(1U<<20)	// AF01 = 0001 (AFRL5 bits 20-23)
#define AFR6_TIM		(1U<<25)	// AF02 = 0010 (AFRL6 bits 24-27)



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


void tim3_pa6_input_capture(void)
{
	// timer 3 is on PA6 with Alternate function AF02

	/* enable clock access to GPIOA */
	RCC->AHB1ENR |= GPIOAEN;	// enable the clock from the AHB1 bus to Port A. Write the enable bit to the Bus register

	/* PA6 direction to alternate function */
	GPIOA->MODER &=~(1U<<12);
	GPIOA->MODER |= (1U<<13);

	/* set PA6 alternate function type to TIM2_CH1 (AF01 = 0001)(AFRL5 bits 24-26) */
	GPIOA->AFR[0] |= AFR6_TIM;

	/* enable clock access to tim2 */
	RCC->APB1ENR |= TIM3EN;

	/* set prescaler */
	TIM3->PSC = 16000 -1;		// sysclk 16,000,000 / psc 1,600 = 10,000 Mhz

	/* set CH1 to capture at every edge */
	TIM3->CCMR1 |= CC1S_IC;

	/* set capture at rising edge */
	TIM3->CCER = CCER_CC1E;

	/* enable tim3 */
	TIM3->CR1 = CR1_CEN;

}

























































