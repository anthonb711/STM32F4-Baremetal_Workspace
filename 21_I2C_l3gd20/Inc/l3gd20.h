#ifndef L3GD20_H_
#define L3GD20_H_

#include "i2c.h"


/*****************************************************
 * L3GD20 Adafruit Triple Axis Gyro break-out board
 * SUPPLY VOLTAGE:	3.3v - 5V
 * PINS:
 *	SCL -> PB8
 *	SDA -> PB9
 *	SA0
 *	CS
 *	DRDY
 *	INT1
 *	GND -> GND
 *	3Vo -> +3
 *	Vin
 *
 *	Data needed from Datasheet
 *	Register Map:
 *		* Device ID register	-->	WHO_AM_I
 *		* Slave Addr (SAD)		-->	0b110101 (0x35)
 ****************************************************/

#define WHO_AM_I_R	0x0F //  *WHO_AM_I = 0b1101 0100







#endif /* L3GD20_H_ */
