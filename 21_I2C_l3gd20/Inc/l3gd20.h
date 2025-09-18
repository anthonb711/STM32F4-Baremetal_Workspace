#ifndef L3GD20_H_
#define L3GD20_H_

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

 DEVICE ID REGISTER:		WHO_AM_I  (0x0F)
 SLAVE ADDR (SAD):			0b110100  (0x34); if SDO pin is high 0b110101 (0x35)
 POWER CONTROL:				CTRL_REG1 (0x20)
 DATA FORMAT:				CTRL_REG4 (0x23)
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

#define WHO_AM_I_R	(0x0F)	// *WHO_AM_I = 0b1101 0100
#define DEVICE_ADDR (0x35)	// SDO is connected to GND
#define CTRL_REG4_R	(0x23)	// used for data formating
#define CTRL_REG1_R	(0x20)	// used for power control







#endif /* L3GD20_H_ */
