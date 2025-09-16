
#ifndef I2C_H_
#define I2C_H_

void I2C1_init		(void								);
void I2C_byteRead	(char saddr, char maddr, char* data	);

#endif /* I2C_H_ */
