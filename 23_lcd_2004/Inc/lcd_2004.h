#ifndef LCD_2004_H_
#define LCD_2204_H_

#include "stm32f411xe.h"
#include"i2c.h"

#define SLAVE_ADDR 		(0x27)


void lcd_init 	(void);
void gpio_init	(void);



#endif /* LCD_2004_H_ */
