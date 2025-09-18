#include "l3gd20.h"

char data;
uint8_t data_vals[6];


void l3gd20_init(void)
{
	/* read device ID should return (0xD4)*/
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
void l3gd20_read_addr(uint8_t reg)
{
	I2C_byteRead(SLAVE_ADDR, reg, &data);
}


/* write to a register on device*/
void l3gd20_write(uint8_t reg, char value)
{
	char data[1];
	data[0] = value;
	I2C_burstWrite(SLAVE_ADDR, reg, 1, data);
}


/* read the data registers */
void l3gd20_read_values(uint8_t reg)
{
	I2C_burstRead(SLAVE_ADDR, reg, 6, (char *)data_vals);
}



