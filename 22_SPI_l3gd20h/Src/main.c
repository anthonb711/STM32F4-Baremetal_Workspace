#include <stdint.h>
#include <stdio.h>
#include "stm32f411xe.h"
#include "l3gd20.h"
#include "systick.h"


int16_t x, y, z;
float xdps, ydps, zdps;

uint8_t data_rec[6];

int main(void)
{
	l3gd20_init();

	while (1)
	{

		l3gd20_read(DATA_START_ADDR, data_rec);

		x = ((data_rec[1]<<8 | data_rec[0]));
		y = ((data_rec[3]<<8 | data_rec[2]));
		z = ((data_rec[5]<<8 | data_rec[4]));

		xdps = (x * .00875);
		ydps = (y * .00875);
		zdps = (z * .00875);

		systickDelayMs(200);

	}
}






