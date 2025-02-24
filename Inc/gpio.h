#ifndef __GPIO_H
#define __GPIO_H

#include "stm32g0xx.h"
#include "core.h"

typedef enum 
{
    GPIO_PORT_A,
    GPIO_PORT_B,
    GPIO_PORT_C,
    GPIO_PORT_D,
    GPIO_PORT_E,
    GPIO_PORT_F,

}GPIO_TypePortDef;

typedef enum
{
    GPIO_PIN0,
    GPIO_PIN1,
    GPIO_PIN2,
    GPIO_PIN3,
    GPIO_PIN4,
    GPIO_PIN5,
    GPIO_PIN6,
    GPIO_PIN7,
    GPIO_PIN8,
    GPIO_PIN9,
    GPIO_PIN10,
    GPIO_PIN11,
    GPIO_PIN12,
    GPIO_PIN13,
    GPIO_PIN14,
    GPIO_PIN15,

}GPIO_TypePinDef;

typedef enum
{
    GPIO_MODE_INPUT,
    GPIO_MODE_OUTPUT,
    GPIO_MODE_AF,
    GPIO_MODE_RST
}GPIO_TypeModeDef;

typedef enum
{
    GPIO_OP_MODE_PUSHPULL,
    GPIO_OP_MODE_OPENDRAIN,
}GPIO_TypeOpModeDef;

typedef enum
{
    GPIO_AF0,
    GPIO_AF1,
    GPIO_AF2,
    GPIO_AF3,
    GPIO_AF4,
    GPIO_AF5,
    GPIO_AF6,
    GPIO_AF7,

}GPIO_TypeAFDef;


void GPIO_TogglePin(GPIO_TypeDef *port, GPIO_TypePinDef pin);
void GPIO_SetPin(GPIO_TypeDef *port, GPIO_TypePinDef pin);
void GPIO_ResetPin(GPIO_TypeDef *port, GPIO_TypePinDef pin);

void GPIO_EnablePort(GPIO_TypePortDef port_pos);
void GPIO_SelectMode(GPIO_TypeDef *port, GPIO_TypePinDef pin, GPIO_TypeModeDef mode);
void GPIO_SelectOpMode(GPIO_TypeDef *port, GPIO_TypePinDef pin, GPIO_TypeOpModeDef mode);
void GPIO_SetAF(GPIO_TypeDef *port, GPIO_TypePinDef pin, GPIO_TypeAFDef af);

void GPIO_ConfigALL(void);
#endif
