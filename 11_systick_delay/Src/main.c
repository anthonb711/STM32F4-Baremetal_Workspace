#include <stdint.h>
#include <stdio.h>
#include "stm32f411xe.h"
#include "uart.h"
#include "adc.h"
#include "systick.h"

#define GPIOAEN		(1U<<0)
#define	GPIOA_5		(1U<<5)
#define LED			GPIOA_5

uint32_t sensor_value;

int main(void)
{
	uart2_tx_init();
	pa1_adc_init();
	start_conversion();

	RCC->AHB1ENR |= GPIOAEN;	// enable the clock from the AHB1 bus to Port A. Write the enable bit to the Bus register0

	// set pin 5 direction. Pin 5 is bits 10 & 11 in the MODE register
	GPIOA->MODER |= (1U<<10);	// set bit 10 to 1
	GPIOA->MODER &=~(1U<<11);	// set bit 11 to 0

	while(1)
	{
		sensor_value = adc_read();
		if((sensor_value > 900) | (sensor_value < 300))
		{
		printf("Sensor_value: %d \n\r", (int)sensor_value);

		GPIOA->ODR ^= LED;

		}
		systickDelayMs(1000);
	}

}





