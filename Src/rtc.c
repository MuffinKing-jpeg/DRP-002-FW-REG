#include "rtc.h"
#define LED_DURATION 100

uint8_t LED_Counter = 0;

CORE_HandleTypeDef RTC_Init(void)
{
    RCC->APBENR1 |= RCC_APBENR1_RTCAPBEN;
    RCC->BDCR &= ~RCC_BDCR_BDRST;
    RCC->BDCR |= RCC_BDCR_RTCEN;
    RCC->BDCR |= RCC_BDCR_RTCSEL_1;

    RTC->WPR = 0xCA;
    RTC->WPR = 0x53;

    RTC->CR &= ~RTC_CR_WUTE;
    RTC->ICSR = RTC_ICSR_INIT;

    while (!(RTC->ICSR & RTC_ICSR_WUTWF) && !(RTC->ICSR & RTC_ICSR_INITF));
    

    RTC->CR |= RTC_CR_WUTIE | RTC_CR_WUCKSEL_0;
    RTC->WUTR = CORE_RTC_SLEEP_PERIOD;

    RTC->CR |= RTC_CR_WUTE;

    RTC->ICSR &= ~ (RTC_ICSR_INIT | RTC_ICSR_INITF);
    
    while ((RTC->ICSR & RTC_ICSR_INITF));

    NVIC_EnableIRQ(RTC_TAMP_IRQn);
    return CORE_OK;
}

void RTC_TAMP_IRQHandler(void)
{
    CORE_ExitSTOP();
    RTC->SCR = RTC_SCR_CWUTF;
    LED_Counter++;

    if (LED_Counter >= LED_DURATION)
    {
        LED_Counter = 0;
        GPIOB->ODR ^= GPIO_ODR_OD7;  
    }
}
