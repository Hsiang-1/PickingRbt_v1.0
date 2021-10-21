#include "aoutput.h"

void AOUTPUT_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_InitStructure.GPIO_Pin = AA_A2_PIN;
    RCC_APB2PeriphClockCmd( AA_A2_CLOCK, ENABLE);
    GPIO_Init(AA_A2_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = AA_A1_PIN;
    RCC_APB2PeriphClockCmd( AA_A1_CLOCK, ENABLE);
    GPIO_Init(AA_A1_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = BB_A2_PIN;
    RCC_APB2PeriphClockCmd( BB_A2_CLOCK, ENABLE);
    GPIO_Init(BB_A2_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = BB_A1_PIN;
    RCC_APB2PeriphClockCmd( BB_A1_CLOCK, ENABLE);
    GPIO_Init(BB_A1_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = CC_A2_PIN;
    RCC_APB2PeriphClockCmd( CC_A2_CLOCK, ENABLE);
    GPIO_Init(CC_A2_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = CC_A1_PIN;
    RCC_APB2PeriphClockCmd( CC_A1_CLOCK, ENABLE);
    GPIO_Init(CC_A1_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = DD_A2_PIN;
    RCC_APB2PeriphClockCmd( DD_A2_CLOCK, ENABLE);
    GPIO_Init(DD_A2_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = DD_A1_PIN;
    RCC_APB2PeriphClockCmd( DD_A1_CLOCK, ENABLE);
    GPIO_Init(DD_A1_PORT, &GPIO_InitStructure);


    GPIO_InitStructure.GPIO_Pin = POWER_A24V_PIN;
    RCC_APB2PeriphClockCmd( POWER_A24V_CLOCK, ENABLE);
    GPIO_Init(POWER_A24V_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = POWER_B20V_PIN;
    RCC_APB2PeriphClockCmd( POWER_B20V_CLOCK, ENABLE);
    GPIO_Init(POWER_B20V_PORT, &GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Pin = POWER_C6V4_PIN;
    RCC_APB2PeriphClockCmd( POWER_C6V4_CLOCK, ENABLE);
    GPIO_Init(POWER_C6V4_PORT, &GPIO_InitStructure);
    
    GPIO_InitStructure.GPIO_Pin = BUZZER_PIN;
    RCC_APB2PeriphClockCmd( BUZZER_CLOCK, ENABLE);
    GPIO_Init(BUZZER_PORT, &GPIO_InitStructure);
}

void AA_STOP(void)
{
    GPIO_ResetBits(AA_A2_PORT,AA_A2_PIN);
    GPIO_ResetBits(AA_A1_PORT,AA_A1_PIN);
}

void AA_GOFORWARD(void)
{
    GPIO_ResetBits(AA_A2_PORT,AA_A2_PIN);
    GPIO_SetBits(AA_A1_PORT,AA_A1_PIN);
}

void AA_BACKUP(void)
{
    GPIO_SetBits(AA_A2_PORT,AA_A2_PIN);
    GPIO_ResetBits(AA_A1_PORT,AA_A1_PIN);
}

void BB_STOP(void)
{
    GPIO_ResetBits(BB_A2_PORT,BB_A2_PIN);
    GPIO_ResetBits(BB_A1_PORT,BB_A1_PIN);
}

void BB_GOFORWARD(void)
{
    GPIO_ResetBits(BB_A2_PORT,BB_A2_PIN);
    GPIO_SetBits(BB_A1_PORT,BB_A1_PIN);
}

void BB_BACKUP(void)
{
    GPIO_SetBits(BB_A2_PORT,BB_A2_PIN);
    GPIO_ResetBits(BB_A1_PORT,BB_A1_PIN);
}

void CC_STOP(void)
{
    GPIO_ResetBits(CC_A2_PORT,CC_A2_PIN);
    GPIO_ResetBits(CC_A1_PORT,CC_A1_PIN);
}

void CC_GOFORWARD(void)
{
    GPIO_ResetBits(CC_A2_PORT,CC_A2_PIN);
    GPIO_SetBits(CC_A1_PORT,CC_A1_PIN);
}

void CC_BACKUP(void)
{
    GPIO_SetBits(CC_A2_PORT,CC_A2_PIN);
    GPIO_ResetBits(CC_A1_PORT,CC_A1_PIN);
}

void DD_STOP(void)
{
    GPIO_ResetBits(DD_A2_PORT,DD_A2_PIN);
    GPIO_ResetBits(DD_A1_PORT,DD_A1_PIN);
}

void DD_GOFORWARD(void)
{
    GPIO_ResetBits(DD_A2_PORT,DD_A2_PIN);
    GPIO_SetBits(DD_A1_PORT,DD_A1_PIN);
}

void DD_BACKUP(void)
{
    GPIO_SetBits(DD_A2_PORT,DD_A2_PIN);
    GPIO_ResetBits(DD_A1_PORT,DD_A1_PIN);
}



void POWER_A24V_OPEN(void)
{
    GPIO_SetBits(POWER_A24V_PORT,POWER_A24V_PIN);
}

void POWER_A24V_CLOSE(void)
{
    GPIO_ResetBits(POWER_A24V_PORT,POWER_A24V_PIN);
}



void POWER_B20V_OPEN(void)
{
    GPIO_SetBits(POWER_B20V_PORT,POWER_B20V_PIN);
}

void POWER_B20V_CLOSE(void)
{
    GPIO_ResetBits(POWER_B20V_PORT,POWER_B20V_PIN);
}




void POWER_C6V4_OPEN(void)
{
    GPIO_SetBits(POWER_C6V4_PORT,POWER_C6V4_PIN);
}

void POWER_C6V4_CLOSE(void)
{
    GPIO_ResetBits(POWER_C6V4_PORT,POWER_C6V4_PIN);
}




void BUZZER_OPEN(void)
{
    GPIO_ResetBits(BUZZER_PORT,BUZZER_PIN);
}

void BUZZER_CLOSE(void)
{
    GPIO_SetBits(BUZZER_PORT,BUZZER_PIN);
}



