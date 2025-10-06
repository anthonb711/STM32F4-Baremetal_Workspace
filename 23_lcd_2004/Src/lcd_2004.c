
#include "lcd_2004.h"

void gpio_init	(void)
{
	/* enable clock access for GPIOA and GPIOC */
	RCC->AHB1ENR |= (GPIOBEN | GPIOCEN);

	/* set GPIO directions -  keep it friendly */
	/* PB3 E_PIN */
	GPIOB->MODER |= (1U<<6);
	GPIOB->MODER &=~(1U<<7);
	/* PB5 RS_PIN */
	GPIOB->MODER |= (1U<<10);
	GPIOB->MODER &=~(1U<<11);
	/* PB6 RW_PIN */
	GPIOB->MODER |= (1U<<12);
	GPIOB->MODER &=~(1U<<13);

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
	GPIOB->BSRR |= (1U<<19);
	GPIOB->BSRR |= (1U<<22);
}


void lcd_init(void)
{
	/*  setup the GPIO */
	gpio_init();


	/* initialize by instructions  */
	systickDelayMs(30);
	lcd_cmd(INIT_VAL);

	systickDelayMs(10);
	lcd_cmd(INIT_VAL);

	systickDelayMs(1);
	lcd_cmd(INIT_VAL);

	/*FUNCTION SET -  set 8-bit and 2 lines */
	lcd_cmd(EIGHT_BIT_FUN);

	/* ENTRY MODE SET -   move the cursor to the right */
	lcd_cmd(CURSOR_R);

	/* clear screen and set cursor home */
	lcd_cmd(CLEAR_DSP);

	/* blink cursor */
	lcd_cmd(CURSOR_BLINK);




}


void lcd_cmd(uint8_t cmd)
{
	/* set the RS and RW LOW for IR write */
	GPIOA->BSRR = ((RS_PIN | RW_PIN) << 16);

	/* output the command */
	GPIOC->ODR = cmd;

	/* HIGH LOW Pulse on E pin */
	GPIOA->BSRR |= (E_PIN);
	systickDelayMs(1);
	GPIOA->BSRR |= (E_PIN <<16);
}


void lcd_data(char data)
{
	/* set RS pin HIGH & RW pin LOW for DR write */
	GPIOA->BSRR |= (RS_PIN);
	GPIOA->BSRR |= (RW_PIN<<16);

	/* send the data */
	GPIOC->ODR = data;

	/* HIGH LOW Pulse on E pin */
	GPIOA->BSRR |= (E_PIN);
	systickDelayMs(1);
	GPIOA->BSRR |= (E_PIN <<16);


	/*  */
}












