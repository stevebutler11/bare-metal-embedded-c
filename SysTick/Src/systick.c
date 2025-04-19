#include "systick.h"

#define CTRL_ENABLE (1U<<0)
#define CTRL_CLCKSRC (1U<<2)
#define CTRL_COUNTFLAG (1U<<16)

/* after reset, the mcu restarts by default with an internal 4 MHz clock (MSI) */
#define ONE_MSEC_LOAD 4000

void systick_msec_delay(uint32_t delay)
{
	 /*Load number of clock cycles per millisecond*/
	 SysTick->LOAD = ONE_MSEC_LOAD - 1;

	 /*Clear systick current value register*/
	 SysTick->VAL = 0;

	 /*Select internal clock source*/
	 SysTick->CTRL = CTRL_CLCKSRC;

	 /*Enable systick*/
	 SysTick->CTRL |= CTRL_ENABLE;
	 for(int i = 0; i < delay; i++)
	 {
		 while((SysTick->CTRL & CTRL_COUNTFLAG) == 0){}
	 }

	 /*Disable systick*/
	 SysTick->CTRL = 0;
}
