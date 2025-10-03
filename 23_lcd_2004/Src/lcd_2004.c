#include "lcd_2004.h"
#include "i2c.h"


void gpio_init	(void)
{
	/* enable clock access for GPIOA and GPIOC */
	RCC->AHB1ENR |= (GPIOAEN | GPIOCEN);

	/* set GPIO directions -  keep it friendly */
	/* PA3 E_PIN */
	GPIOA->MODER |= (1U<<6);
	GPIOA->MODER &=~(1U<<7);
	/* PA5 RS_PIN */
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &=~(1U<<11);
	/* PA6 RW_PIN */
	GPIOA->MODER |= (1U<<12);
	GPIOA->MODER &=~(1U<<13);

	/* PC0 D0_PIN */
	GPIOC->MODER |= (1U<<0);
	GPIOC->MODER &=~(1U<<1);
	/* PC1 D1_PIN */
	GPIOC->MODER |= (1U<<2);
	GPIOC->MODER &=~(1U<<3);
	/* PC2 D2_PIN */
	GPIOC->MODER |= (1U<<4);
	GPIOC->MODER &=~(1U<<5);
	/* PC3 D3_PIN */
	GPIOC->MODER |= (1U<<6);
	GPIOC->MODER &=~(1U<<7);
	/* PC4 D4_PIN */
	GPIOC->MODER |= (1U<<8);
	GPIOC->MODER &=~(1U<<9);
	/* PC5 D5_PIN */
	GPIOC->MODER |= (1U<<10);
	GPIOC->MODER &=~(1U<<11);
	/* PC6 D6_PIN */
	GPIOC->MODER |= (1U<<12);
	GPIOC->MODER &=~(1U<<13);
	/* PC7 D7_PIN */
	GPIOC->MODER |= (1U<<14);
	GPIOC->MODER &=~(1U<<15);

	/* E & RW need to init LOW */
	GPIOA->BSRR |= (1U<<19);
	GPIOA->BSRR |= (1U<<22);
}


void lcd_init(void)
{
	/*  */
	/*  */

}


void lcd_cmd(unsigned char cmd)
{
	/* set the RS and RW LOW for IR write */
	GPIOA->BSRR = (RS_PIN | RW_PIN) << 16;

	/* output the command */
	GPIOC->ODR = cmd;

	/* HIGH LOW Pulse on E pin */
	GPIOA->BSRR |= E_PIN;
	GPIOA->BSRR |= E_PIN <<16;
}


void lcd_data(char data)
{
	/*  */
	/*  */
}












