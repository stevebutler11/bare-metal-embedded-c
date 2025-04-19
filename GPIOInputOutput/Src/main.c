#include "gpio.h"

int main(void)
{
	/* Initialize LED */
	led_init();
	/* Initialize BTN */
	btn_init();

	while(1)
	{
		if (get_btn_state())
		{
			led_on();
		}
		else
		{
			led_off();
		}
	}
}
