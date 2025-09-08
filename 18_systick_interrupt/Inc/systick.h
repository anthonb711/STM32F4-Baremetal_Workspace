

#ifndef SYSTICK_H_
#define SYSTICK_H_

#define GPIOAEN		(1U<<0)
#define	GPIOA_5		(1U<<5)
#define LED			GPIOA_5

void systickDelayMs 		(int delay	);
void systick_1hz_interrupt	(void		);

#endif /* SYSTICK_H_ */
