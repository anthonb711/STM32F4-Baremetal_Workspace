#include "l3gd20.h"

#define MULTI_BYTE_EN (0x40)


void l3gd20_init(void)
{
	/* enable the SPI1 module */
	spi_gpio_init();
	spi1_config();

	/* read device ID should return (0xD7)*/
	l3gd20_read_addr(WHO_AM_I_R);

	/* enter stand by mode*/
	l3gd20_write(CTRL_REG1_R, STANDBY);

	/* set data format range  to +/-250dps*/
	l3gd20_write(CTRL_REG4_R, RES_250DPS);

	/* enter normal Mode */
	l3gd20_write(CTRL_REG1_R, NORMAL);
	/* set enable data from axes */
}



/* read a register on device */
void l3gd20_read_addr(uint8_t addr)
{

}


/* write to a register on device*/
void l3gd20_write(uint8_t addr, uint8_t value)
{
	uint8_t data[2];

	/* enable multi-byte and set data into buffer */
	data[0] = addr|MULTI_BYTE_EN;
	data[1] = value;

	/* pull cs pin LOW to enable slave */
	cs_enable();

	/* transmit the data and the size of the data*/
	spi1_transmit(data, 2);

	/* pull cs pin HIGH to disable slave */
	cs_disable();

}


/* read the data registers */
void l3gd20_read_values(uint8_t reg)
{

}



