#include "l3gd20.h"
#include "spi.h"

#define MULTI_BYTE_EN	(0x40)
#define READ_EN			(0x80)


void l3gd20_init(void)
{
	/* enable the SPI1 module */
	spi_gpio_init();
	spi1_config();

	/* enter stand by mode */
	l3gd20_write(CTRL_REG1_R, STANDBY);

	/* set data format range  to +/-250dps */
	l3gd20_write(CTRL_REG4_R, RES_250DPS);

	/* enter normal Mode */
	l3gd20_write(CTRL_REG1_R, NORMAL);
	/* set enable data from axes */
}



/* read a register from slave device */
void l3gd20_read(uint8_t addr, uint8_t * rxdata)
{

	/* pull CS pin LOW to enable slave */
	cs_enable();

	/* set read and multi-byte */
	addr |= READ_EN;
	addr |= MULTI_BYTE_EN;
	/* transmit the data and the size of the data */
	spi1_transmit(&addr, 1);

	/* set read 6 bytes of data */
	spi1_receive(rxdata, 6);

	/* pull CS pin HIGH to disable slave */
	cs_disable();

}


/* write to a register on device*/
void l3gd20_write(uint8_t addr, uint8_t value)
{
	uint8_t data[2];

	/* enable multi-byte and set data into buffer */
	data[0] = (addr|MULTI_BYTE_EN);
	data[1] = value;

	/* pull CS pin LOW to enable slave */
	cs_enable();

	/* transmit the data and the size of the data */
	spi1_transmit(data, 2);

	/* pull CS pin HIGH to disable slave */
	cs_disable();

}





















