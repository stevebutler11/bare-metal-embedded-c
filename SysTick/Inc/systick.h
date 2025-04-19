#ifndef SYSTICK_H_
#define SYSTICK_H_
#include <stdint.h>
#include "stm32l552xx.h"

void systick_msec_delay(uint32_t delay);

#endif
