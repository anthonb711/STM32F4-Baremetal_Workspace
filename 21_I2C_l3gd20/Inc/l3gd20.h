#ifndef L3GD20_H_
#define L3GD20_H_

#include <stdint.h>
#include "i2c.h"



/*****************************************************************
  	  ~~~ L3GD20 Adafruit Triple Axis Gyro break-out board ~~~

 SUPPLY VOLTAGE:	3.3v - 5V
 PINS:
 	 * SCL -> PB8
 	 * SDA -> PB9
 	 * SA0
 	 * CS
 	 * DRDY
 	 * INT1
	 * GND -> GND
	 * 3Vo -> +3
	 * Vin

 DEVICE ID REGISTER:		WHO_AM_I  (0x0F); value at register is (0xD4) 0b1101 0100
 SLAVE ADDR (SAD):			0b110100  (0x34); if SDO pin is high 0b110101 (0x35)
 POWER CONTROL:				CTRL_REG1 (0x20)
 DATA FORMAT:				CTRL_REG4 (0x23)
 OUTPUT RES:				CTRL_REG4 FS1, FS0 [5:4] 00:250dps, 01:500dps, 10:2000dps, 11:2000dps;
  *-------------------------------------------------------------*
  |			*** SAD+READ/WRITE PATTERNS ***                    	|
  |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|
  | COMAMND	| SAD[6:1]	| SAD[0] = SDO	|  R/W	| 	SAD+R/W		|
  |---------|-----------|---------------|-------|---------------|
  | READ 	| 110101	| 		0		|	1	| 11010101(D5)	|
  |---------|-----------|---------------|-------|---------------|
  | WRITE	| 110101	|		0		|	0	| 11010100 D4)	|
  |---------|-----------|---------------|-------|---------------|
  | READ	| 110101	|		1		|	1	| 11010111(D7)	|
  |---------------------|---------------|-------|---------------|
  | WRITE	| 110101	|		1		|	0	| 11010110(D6)	|
  *---------*-----------*---------------*-------*---------------*



 ****************************************************************/

#define CTRL_REG1_R		(0x20)	// used for power control
#define CTRL_REG4_R		(0x23)	// used for data formating
#define DATA_START_ADDR	(0x28)	// data output starts with OUT_X_L, ends with OUT_Z_H(0x2D)
#define RES_250DPS		(0x00)	// CTRL_REG4 FS1:FS0 bits[5:4] sensitivity is 8.75mdps/LSB
#define RESET			(0x00)	// used in CTRL_REG1 for power modes - reset - PD 0 - power cycles
#define SLAVE_ADDR 		(0x34)	// pin SDO(SA0) is connected to GND internally
#define STANDBY			(0x08)	// used in CTRL_REG1 for power modes - standby = PD on while data from axes is disabled
#define	NORMAL			(0x0F)
#define WHO_AM_I_R		(0x0F)	// *WHO_AM_I = (0xD4) 0b1101 0100

void l3gd20_init		(void					);
void l3gd20_read_addr	(uint8_t reg			);
void l3gd20_read_values	(uint8_t reg			);
void l3gd20_write		(uint8_t reg, char value);



#endif /* L3GD20_H_ */




















































