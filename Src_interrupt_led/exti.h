#ifndef EXTI_H
#define EXTI_H

#include "stm32f4xx.h"

#define LINE13 (1U<<13)
static void exti_callback(void);

void pc13_exti_init(void);
void EXTI15_10_IRQHandler(void);

#endif /* EXTI_H */
