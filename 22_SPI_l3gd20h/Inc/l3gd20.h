#ifndef L3GD20_H_
#define L3GD20_H_

#include <stdint.h>
#include "spi.h"
#include "stm32f411xe.h"



/*****************************************************************
  	  ~~~ L3GD20 Adafruit Triple Axis Gyro break-out board ~~~

SPI Wiring for STM32F411RE
 PINS:
 	 * SCL	-> PA5 SCK
 	 * SDA 	-> PA7 MOSI
 	 * SA0	-> PA6 MISO
 	 * CS	-> PA9
 	 * DRDY
 	 * INT1
	 * GND	-> GND
	 * 3Vo	-> +3v
	 * Vin


 SLAVE ADDR (SAD):			0b110100  (0x34); if SDO pin is high 0b110101 (0x35)
 POWER CONTROL:				CTRL_REG1 (0x20)
 DATA FORMAT:				CTRL_REG4 (0x23)
 OUTPUT RES:				CTRL_REG4 FS1, FS0 [5:4] 00:250dps, 01:500dps, 10:2000dps, 11:2000dps;


 ****************************************************************/

#define CTRL_REG1_R		(0x20)	// used for power control
#define CTRL_REG4_R		(0x23)	// used for data formating
#define DATA_START_ADDR	(0x28)	// data output starts with OUT_X_L, ends with OUT_Z_H(0x2D)
#define RES_250DPS		(0x00)	// CTRL_REG4 FS1:FS0 bits[5:4] sensitivity is 8.75mdps/LSB
#define RESET			(0x00)	// used in CTRL_REG1 for power modes - reset - PD 0 - power cycles
#define STANDBY			(0x08)	// used in CTRL_REG1 for power modes - standby = PD on while data from axes is disabled
#define	NORMAL			(0x0F)


void l3gd20_init		(void							);
void l3gd20_read		(uint8_t addr, uint8_t * rxdata	);
void l3gd20_write		(uint8_t addr, uint8_t value	);



#endif /* L3GD20_H_ */




















































