// Where is the led connected? - Look in the dev board User Manual for User LED LD2
// Port:	A
// Pin:		5


// How do we get to Port A? - Look in the controller datasheet - Memory Map Peripherals GIPO Port A
#include <stdint.h>

#define PERIPH_BASE			(0x40000000UL)
#define AHB1PERIPH_OFFSET	(0x00020000UL) // 0x4002 0000 = starting point of the AHB1 bus and GPIO A
#define AHB1PERIPH_BASE		(PERIPH_BASE + AHB1PERIPH_OFFSET)
#define GPIOA_OFFSET		(0x0000UL)
#define GPIOA_BASE			(AHB1PERIPH_BASE + GPIOA_OFFSET)

// RCC(resetting clock control) use to enable the clock for AGH1 Bus
#define RCC_OFFSET			(0x3800UL)
#define RCC_BASE			(AHB1PERIPH_BASE + RCC_OFFSET)	// 0x4002 3800

#define GPIOAEN				(1U<<0)	// bit 0 gets set high (0b 0000 0000 0000 0000 0000 0000 0000 0001)
#define PIN5				(1U<<5)
#define LED_PIN				PIN5



typedef struct
{
	volatile uint32_t DUMMY[12];
	volatile uint32_t AHB1ENR; 	/*!< RCC AHB1 peripheral clock register,	Address offset: 0x30	*/
} RCC_TypeDef;


typedef struct
{
	volatile uint32_t MODER;	/*!< GPIO port mode register,			Address offset: 0x00	*/
	volatile uint32_t DUMMY[4];
	volatile uint32_t ODR;		/*!< GPIO port output data register,	Address offset: 0x14	*/
} GPIO_TypeDef;

#define RCC		( (RCC_TypeDef*) RCC_BASE)
#define GPIOA	( (GPIO_TypeDef*) GPIOA_BASE)



int main(void)
{
	RCC->AHB1ENR |= GPIOAEN;  // friendly programming the "\=" OR operator changes only the bits specified.
	GPIOA->MODER|= (1U<<10);	// set bit 10 to 1
	GPIOA->MODER &=~(1U<<11);	//sets bit 11 to 0

	while(1)
	{
		GPIOA->ODR ^= LED_PIN;
		for(int i = 0; i <100000; i++){;}
	}
}














