
#include "stm32f411xe.h"
#include "adc.h"

#define ADC1EN			(1U<<8)
#define GPIOAEN			(1U<<0)
#define GPIOA_1			(1U<<1)
#define ADC_CH1			(1U<<0)
#define ADC_SEQ_LEN_1	0x00
#define CR2_ADON		(1U<<0)
#define CR2_CONT		(1U<<1)
#define CR2_SWSTART		(1U<<30)
#define SR_EOC			(1U<<1)

void pa1_adc_init(void)
{
	/* enable clock access to GPIOA */
	RCC->AHB1ENR |= GPIOAEN;

	/* set the mode of PA1 to analog mode */
	GPIOA->MODER |= ((1U<<2)|(1U<<3));

	/***  configure the ADC module ***/
	/* enable clock access to ADC*/
	RCC->APB2ENR |= ADC1EN;


	/* conversion sequence start */
	ADC1->SQR3 = ADC_CH1;
	/* conversion sequence length */
	ADC1->SQR1 = ADC_SEQ_LEN_1;
	/* enable ADC Module */
	ADC1->CR2 |= CR2_ADON;
}

void start_conversion(void)
{
	/* enable continuous conversion */
	ADC1->CR2 |= CR2_CONT;
	/* start ADC conversion */
	ADC1->CR2 |= CR2_SWSTART;
}

uint32_t adc_read(void)
{
	/* wait for conversion to finish */
	while (!(ADC1->SR & SR_EOC)){}	// while conversation is not complete wait in the while loop

	/* read converted result */
		return ADC1->DR;	// conversion is complete, read the data
}
