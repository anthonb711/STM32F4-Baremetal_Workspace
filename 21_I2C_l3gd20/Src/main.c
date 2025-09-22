#include <stdint.h>
#include <stdio.h>
#include "stm32f411xe.h"
#include "l3gd20.h"
#include "systick.h"


int16_t x, y, z;
float xdps, ydps, zdps;

extern uint8_t data_vals[6];


int main(void)
{
	l3gd20_init();

	while (1)
	{
		/* read starts at OUT_X_L and increments the address */
		l3gd20_read_values(DATA_START_ADDR | 0x80);

		/* combine high and low for each axis */
		x = ((data_vals[1]<<8) | data_vals[0]);
		y = ((data_vals[3]<<8) | data_vals[2]);
		z = ((data_vals[5]<<8) | data_vals[4]);

		/* convert raw to degrees per second */
		xdps = (x * .00875);
		ydps = (y * .00875);
		zdps = (z * .00875);

		systickDelayMs(200);

	}
}






