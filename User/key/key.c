#include "key.h"

void KEY_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_InitStructure.GPIO_Pin = KEYA_PIN;
    RCC_APB2PeriphClockCmd( KEYA_CLOCK, ENABLE);
    GPIO_Init(KEYA_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = KEYB_PIN;
    RCC_APB2PeriphClockCmd( KEYB_CLOCK, ENABLE);
    GPIO_Init(KEYB_PORT, &GPIO_InitStructure);

    RCC_APB2PeriphClockCmd( KEYS_CONTROL_CLOCK, ENABLE);

    GPIO_InitStructure.GPIO_Pin = KEY_UP_PIN;
    GPIO_Init(KEY_UP_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = KEY_DOWN_PIN;
    GPIO_Init(KEY_DOWN_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = KEY_LEFT_PIN;
    GPIO_Init(KEY_LEFT_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = KEY_RIGHT_PIN;
    GPIO_Init(KEY_RIGHT_PORT, &GPIO_InitStructure);
}


uint16_t Key_Scan( GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin )
{
    if(GPIO_ReadInputDataBit( GPIOx, GPIO_Pin) == KEY_ON)
    {
        while(GPIO_ReadInputDataBit( GPIOx, GPIO_Pin) == KEY_ON);
        return KEY_ON;
    }
    else
        return KEY_OFF;
}
