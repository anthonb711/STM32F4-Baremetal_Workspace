#include <stdint.h>
#include <stdio.h>
#include "stm32f411xe.h"
#include "l3gd20.h"
#include "systick.h"


int16_t x, y, z;
float xdps, ydps, zdps;


int main(void)
{
	l3gd20_init();

	while (1)
	{


		systickDelayMs(200);

	}
}






