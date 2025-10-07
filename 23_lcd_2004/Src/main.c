#include <stdint.h>
#include <stdio.h>
#include "stm32f411xe.h"
#include "lcd_2004.h"
#include "systick.h"

char data_string[23];

int main(void)
{

lcd_init();

	lcd_data('H');
	lcd_data('E');
	lcd_data('L');
	lcd_data('L');
	lcd_data('O');
	lcd_data(',');
	lcd_data(' ');
	lcd_data('W');
	lcd_data('O');
	lcd_data('R');
	lcd_data('L');
	lcd_data('D');
	lcd_data('!');
	lcd_cmd(0x0C);

	while (1){}

}


























