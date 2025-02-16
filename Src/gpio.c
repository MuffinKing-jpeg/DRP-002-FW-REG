#include "gpio.h"

CORE_HandleTypeDef GPIO_InitPort()
{
    RCC->IOPENR |= RCC_IOPENR_GPIOBEN;
    GPIOB->MODER &= ~ GPIO_MODER_MODE7_1;
    GPIOB->OTYPER |= GPIO_OTYPER_OT7;
    GPIOB->BSRR = GPIO_BSRR_BS7;

    return CORE_OK;
}

