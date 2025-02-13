#ifndef __MAIN_H
#define __MAIN_H

#include <stdint.h>
#include "stm32g0xx.h"
#include "rtc.h"
#include "core.h"

CORE_HandleTypeDef RTC_Init(uint8_t sleep_period);

#endif