#include "gpio.h"


#define GPIOCEN (1U<<2)
#define LED_BS7 (1U<<7) /* Bit Set Pin 7 */
#define LED_BR7 (1U<<23) /* Bit Reset Pin 7 */
#define BTN_PIN (1U<<13)


void led_init(void)
{
	/* Enable clock access to GPIOC */
	RCC->AHB2ENR |= GPIOCEN;
	/* Set PC7 mode to output mode */
	GPIOC->MODER |= (1U<<14);
	GPIOC->MODER &= ~(1U<<15);
}

void btn_init(void)
{
	/* Enable clock access to GPIOC */
	RCC->AHB2ENR |= GPIOCEN;
	/* Set PC13 mode as an input pin */
	GPIOC->MODER &=~(1U<<26);
	GPIOC->MODER &=~(1U<<27);
}

bool get_btn_state(void)
{
	/* bitwise AND with the input data register and the pin */
	/* true if pin is pressed, as docs say btn down logic is 1, up is 0 */
	if (GPIOC->IDR & BTN_PIN)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void led_on(void)
{
	/* Set PC7 high */
	GPIOC->BSRR |=LED_BS7;
}
void led_off(void)
{
	/* Set PC7 low */
	GPIOC->BSRR |=LED_BR7;
}
