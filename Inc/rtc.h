#ifndef __RTC_H
#define __RTC_H

#include "stm32g0xx.h"
#include "core.h"


CORE_HandleTypeDef RTC_Init(void);

void RTC_TAMP_IRQHandler(void);

#endif