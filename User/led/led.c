#include "led.h"

void LED_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd( LED_CLOCK, ENABLE);

    GPIO_InitStructure.GPIO_Mode    =    GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed   =    GPIO_Speed_50MHz;

    GPIO_InitStructure.GPIO_Pin = LED_B_PIN;
    GPIO_Init(LED_B_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = LED_G_PIN;
    GPIO_Init(LED_G_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = LED_R_PIN;
    GPIO_Init(LED_R_PORT, &GPIO_InitStructure);
}

void LED_R_ON(void)
{
    GPIO_ResetBits(LED_R_PORT, LED_R_PIN);
    GPIO_SetBits(LED_G_PORT, LED_G_PIN);
    GPIO_SetBits(LED_B_PORT, LED_B_PIN);
}

void LED_G_ON(void)
{
    GPIO_SetBits(LED_R_PORT, LED_R_PIN);
    GPIO_ResetBits(LED_G_PORT, LED_G_PIN);
    GPIO_SetBits(LED_B_PORT, LED_B_PIN);
}

void LED_B_ON(void)
{
    GPIO_SetBits(LED_R_PORT, LED_R_PIN);
    GPIO_SetBits(LED_G_PORT, LED_G_PIN);
    GPIO_ResetBits(LED_B_PORT, LED_B_PIN);
}

void LED_Y_ON(void)
{
    GPIO_ResetBits(LED_R_PORT, LED_R_PIN);
    GPIO_ResetBits(LED_G_PORT, LED_G_PIN);
    GPIO_SetBits(LED_B_PORT, LED_B_PIN);
}



void LED_R_OFF(void)
{
    GPIO_SetBits(LED_R_PORT, LED_R_PIN);
    GPIO_ResetBits(LED_G_PORT, LED_G_PIN);
    GPIO_ResetBits(LED_B_PORT, LED_B_PIN);
}

void LED_G_OFF(void)
{
    GPIO_ResetBits(LED_R_PORT, LED_R_PIN);
    GPIO_SetBits(LED_G_PORT, LED_G_PIN);
    GPIO_ResetBits(LED_B_PORT, LED_B_PIN);
}

void LED_B_OFF(void)
{
    GPIO_ResetBits(LED_R_PORT, LED_R_PIN);
    GPIO_ResetBits(LED_G_PORT, LED_G_PIN);
    GPIO_SetBits(LED_B_PORT, LED_B_PIN);
}

void LED_Y_OFF(void)
{
    GPIO_SetBits(LED_R_PORT, LED_R_PIN);
    GPIO_SetBits(LED_G_PORT, LED_G_PIN);
    GPIO_ResetBits(LED_B_PORT, LED_B_PIN);
}

