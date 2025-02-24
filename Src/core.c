#include "stm32g0xx.h"
#include "core.h"


void CORE_PWRInit(void)
{
    PWR->CR1 |= PWR_CR1_DBP;
    PWR->CR1 |= PWR_CR1_FPD_STOP;
    PWR->CR1 &= ~PWR_CR1_LPR;

}

void CORE_ClockInit(void)
{
    RCC->APBENR1 |= RCC_APBENR1_PWREN;
    RCC->APBENR2 |= RCC_APBENR2_TIM1EN;

    RCC->APBSMENR2 |= RCC_APBSMENR2_TIM1SMEN;

    RCC->CR &= ~RCC_CR_HSIDIV;
    RCC->CFGR |= RCC_CFGR_PPRE;

    #ifdef BUILD_DEBUG
    CORE_AllowDebugInSTOP();
    #endif
}

void CORE_EnterSTOP(void)
{
    // Slow down to 2MHz and keep APB 2MHz
    RCC->CR |= (3UL << RCC_CR_HSIDIV_Pos);      
    RCC->CFGR &= ~RCC_CFGR_PPRE;

    PWR->CR1 |= PWR_CR1_LPR;                    // Enable LP regulator
    PWR->CR1 &= ~PWR_CR1_LPMS;
    __WFI();
}

void CORE_ExitSTOP(void)
{
    PWR->CR1 &= ~PWR_CR1_LPR;                   // Disable LP regulator
    RCC->CR &= ~RCC_CR_HSIDIV;                  // Speed-up to 16MHz
    RCC->CFGR |= RCC_CFGR_PPRE;                 // Keep APB at 2MHz
}

#ifdef BUILD_DEBUG
void CORE_AllowDebugInSTOP(void)
{
    DBG->CR |= DBG_CR_DBG_STOP;
}
#endif
