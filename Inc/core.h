#ifndef __CORE_H
#define __CORE_H

#define CORE_RTC_SLEEP_PERIOD (100-1)

typedef enum{
    CORE_OK,
    CORE_ERR,
    CORE_BUSY,
}CORE_HandleTypeDef;

void CORE_EnterSTOP(void);
void CORE_ExitSTOP(void);

void CORE_ClockInit(void);
void CORE_PWRInit(void);

#ifdef BUILD_DEBUG
void CORE_AllowDebugInSTOP(void);
#endif

#endif