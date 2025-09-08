/*
 * adc.h
 *
 *  Created on: Aug 27, 2025
 *      Author: thewiz
 */

#ifndef ADC_H_


#include <stdint.h>

uint32_t adc_read		(void);
void 	pa1_adc_init	(void);
void 	start_conversion(void);



#endif /* ADC_H_ */
