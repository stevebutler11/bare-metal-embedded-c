#include "gpio.h"
#include "systick.h"

int main(void)
{
	led_init();

	while(1)
	{
		systick_msec_delay(1000U);
		led_toggle();
	}
}
