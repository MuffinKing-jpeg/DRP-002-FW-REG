#include "gpio.h"

void GPIO_EnablePort(GPIO_TypePortDef port_pos)
{
    RCC->IOPENR |= (1UL << port_pos);
}

void GPIO_SelectMode(GPIO_TypeDef *port, GPIO_TypePinDef pin, GPIO_TypeModeDef mode)
{
    port->MODER = (port->MODER & ~(3UL << pin*2)) | (mode << pin*2);
}

void GPIO_SelectOpMode(GPIO_TypeDef *port, GPIO_TypePinDef pin, GPIO_TypeOpModeDef mode)
{
    port->OTYPER = (port->OTYPER & ~(1 << pin)) | (mode << pin);
}

void GPIO_TogglePin(GPIO_TypeDef *port, GPIO_TypePinDef pin)
{
    port->ODR ^= (1UL << pin);
}

void GPIO_SetPin(GPIO_TypeDef *port, GPIO_TypePinDef pin)
{
    port->BSRR = (1UL << pin);
}

void GPIO_ResetPin(GPIO_TypeDef *port, GPIO_TypePinDef pin)
{
    port->BSRR = ((1UL << pin) << 16);
}

void GPIO_SetAF(GPIO_TypeDef *port, GPIO_TypePinDef pin, GPIO_TypeAFDef af)
{
    uint8_t AFR_Index = 0;

    if(pin > 7)
    {
        AFR_Index = 1;
        pin = pin - 8; 
    }

    port->AFR[AFR_Index] = (port->AFR[AFR_Index] & ~(15UL << pin*4)) | (af << pin*4);
}

void GPIO_ConfigALL(void)
{
    GPIO_EnablePort(GPIO_PORT_B);
    GPIO_EnablePort(GPIO_PORT_A);

    // Config CTRL_LED (PB7) pin
    GPIO_SelectMode(GPIOB, GPIO_PIN7, GPIO_MODE_OUTPUT);
    GPIO_SelectOpMode(GPIOB, GPIO_PIN7, GPIO_OP_MODE_OPENDRAIN);

    // Config SERVO (PB3) pin
    GPIO_SelectMode(GPIOB, GPIO_PIN3, GPIO_MODE_AF);
    GPIO_SelectOpMode(GPIOB, GPIO_PIN3, GPIO_OP_MODE_OPENDRAIN);
    GPIO_SetAF(GPIOB, GPIO_PIN3, GPIO_AF1);

}
