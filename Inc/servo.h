#ifndef __SERVO_H
#define __SERVO_H

#include "stm32g0xx.h"

typedef enum
{
    TIM_CHANNEL_1 = 0x01,
    TIM_CHANNEL_2 = 0x02,
    TIM_CHANNEL_3 = 0x04,
    TIM_CHANNEL_4 = 0x08,
}TIM_ChannelTypeDef;

void SERVO_TIMConfig(TIM_TypeDef *tim, TIM_ChannelTypeDef channel);
void SERVO_SetAngle(TIM_TypeDef *tim, TIM_ChannelTypeDef channel, uint8_t angle);

#endif
