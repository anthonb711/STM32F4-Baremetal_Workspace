#include <stdint.h>
#include <stdio.h>
#include "stm32f411xe.h"
#include "lcd_2004.h"
#include "systick.h"

char data_string[23];
//void lcd_probe(void);
int main(void)
{

	//lcd_probe();
lcd_init();
lcd_data('H');

//
	while (1)
	{
//		lcd_data('H');
//		lcd_data('E');
//		lcd_data('L');
//		lcd_data('L');
//		lcd_data('O');
//		lcd_data(',');
//		lcd_data(' ');
//		lcd_data('W');
//		lcd_data('O');
//		lcd_data('R');
//		lcd_data('L');
//		lcd_data('D');
//		lcd_data('!');
//
//		//systickDelayMs(500);
//
//		lcd_cmd(CLEAR_DSP);
//		systickDelayMs(500);
	}

}



void lcd_probe(void){
    // assumes gpio_init already done and RW is 0
    // init kick x3
    systickDelayMs(30);
    lcd_cmd(0x30); systickDelayMs(5);
    lcd_cmd(0x30); systickDelayMs(1);
    lcd_cmd(0x30); systickDelayMs(1);

    lcd_cmd(0x38);         // function set
    while(1){
        lcd_cmd(0x08);     // display OFF
        systickDelayMs(250);
        lcd_cmd(0x0C);     // display ON, cursor off
        systickDelayMs(250);
    }
}






















