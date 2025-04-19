#ifndef GPIO_H_
#define GPIO_H_

#include <stdbool.h>
#include "stm32l552xx.h"

void led_init(void);
void btn_init(void);
bool get_btn_state(void);
void led_on(void);
void led_off(void);
#endif /* GPIO_H_ */
