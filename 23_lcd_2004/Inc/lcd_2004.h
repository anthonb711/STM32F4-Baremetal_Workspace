#ifndef LCD_2004_H_
#define LCD_2204_H_

#include "stm32f411xe.h"
#include "systick.h"

/* GIPO defines */
#define GPIOBEN	(1U<<1)
#define GPIOCEN	(1U<<2)
#define PB8		(1U<<8)
#define PB5		(1U<<5)
#define	PB6		(1U<<6)

/* 2004 defines */
#define E_PIN	PB8
#define RS_PIN	PB5
#define RW_PIN	PB6

/* 2004 cmd defines */
#define INIT_VAL		(0x30) // used to initialize the lcd with delays
#define EIGHT_BIT_FUN	(0x38) // this is for 8 bit, 5x8 char, 2 lines
#define	CURSOR_R		(0x06) //
#define CLEAR_DSP		(0x01) // homes cursor
#define	CURSOR_BLINK	(0x0F) // turns on display and blinks cursor


void lcd_init 	(void				);
void gpio_init	(void				);
void lcd_cmd	(uint8_t cmd		);
void lcd_data	(char data			);



#endif /* LCD_2004_H_ */
