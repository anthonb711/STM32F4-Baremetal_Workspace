#ifndef LCD_2004_H_
#define LCD_2204_H_

#include "stm32f411xe.h"
#include"i2c.h"

/* GIPO defines */
#define GPIOAEN	(1U<<0)
#define GPIOCEN	(1U<<2)
#define PA3		(1U<<3)
#define PA5		(1U<<5)
#define	PA6		(1U<<6)
#define PC0		(1U<<0)
#define PC1		(1U<<1)
#define PC2		(1U<<2)
#define PC3		(1U<<3)
#define PC4		(1U<<4)
#define PC5		(1U<<5)
#define PC6		(1U<<6)
#define PC7		(1U<<7)

/* 2004 defines */
#define E_PIN	PA3
#define RS_PIN	PA5
#define RW_PIN	PA6
#define D0_PIN	PC0
#define D1_PIN	PC1
#define D2_PIN	PC2
#define D3_PIN	PC3
#define D4_PIN	PC4
#define D5_PIN	PC5
#define D6_PIN	PC6
#define D7_PIN	PC7

/* 2004 cmd defines */
#define

void lcd_init 	(void				);
void gpio_init	(void				);
void lcd_cmd	(unsigned char cmd	);
void lcd_data	(char data			);



#endif /* LCD_2004_H_ */
