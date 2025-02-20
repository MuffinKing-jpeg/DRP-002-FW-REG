#include "stm32g0xx.h"
#include "core.h"


void CORE_PWRInit(void)
{
    RCC->APBENR1 |= RCC_APBENR1_PWREN;
    PWR->CR1 |= PWR_CR1_DBP;
    PWR->CR1 |= PWR_CR1_FPD_STOP;
    PWR->CR1 &= ~PWR_CR1_LPR;

    #ifdef BUILD_DEBUG
    CORE_AllowDebugInSTOP();
    #endif
}

void CORE_ClockInit(void)
{
    RCC->CR &= ~RCC_CR_HSIDIV;
}

void CORE_EnterSTOP(void)
{
    RCC->CR |= (4UL << RCC_CR_HSIDIV_Pos);      // Slow down to 1MHz
    PWR->CR1 |= PWR_CR1_LPR;                    // Enable LP regulator
    PWR->CR1 &= ~PWR_CR1_LPMS;
    __WFI();
}

void CORE_ExitSTOP(void)
{
    PWR->CR1 &= ~PWR_CR1_LPR;                   // Disable LP regulator
    RCC->CR &= ~RCC_CR_HSIDIV;              // Speed-up to 16MHz
}

#ifdef BUILD_DEBUG
void CORE_AllowDebugInSTOP(void)
{
    DBG->CR |= DBG_CR_DBG_STOP;
}
#endif
