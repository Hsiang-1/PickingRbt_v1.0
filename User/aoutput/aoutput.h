#ifndef __AOUTPUT_H
#define __AOUTPUT_H

#include "stm32f10x.h"




#define         AA_A2_PORT          GPIOE
#define         AA_A2_PIN           GPIO_Pin_8
#define         AA_A2_CLOCK         RCC_APB2Periph_GPIOE

#define         BB_A2_PORT          GPIOE
#define         BB_A2_PIN           GPIO_Pin_10
#define         BB_A2_CLOCK         RCC_APB2Periph_GPIOE

#define         CC_A2_PORT          GPIOE
#define         CC_A2_PIN           GPIO_Pin_12
#define         CC_A2_CLOCK         RCC_APB2Periph_GPIOE

#define         DD_A2_PORT          GPIOE
#define         DD_A2_PIN           GPIO_Pin_14
#define         DD_A2_CLOCK         RCC_APB2Periph_GPIOE

#define         AA_A1_PORT          GPIOE
#define         AA_A1_PIN           GPIO_Pin_9
#define         AA_A1_CLOCK         RCC_APB2Periph_GPIOE

#define         BB_A1_PORT          GPIOE
#define         BB_A1_PIN           GPIO_Pin_11
#define         BB_A1_CLOCK         RCC_APB2Periph_GPIOE

#define         CC_A1_PORT          GPIOE
#define         CC_A1_PIN           GPIO_Pin_13
#define         CC_A1_CLOCK         RCC_APB2Periph_GPIOE

#define         DD_A1_PORT          GPIOE
#define         DD_A1_PIN           GPIO_Pin_15
#define         DD_A1_CLOCK         RCC_APB2Periph_GPIOE



#define         POWER_A24V_PORT          GPIOC
#define         POWER_A24V_PIN           GPIO_Pin_6
#define         POWER_A24V_CLOCK         RCC_APB2Periph_GPIOC

#define         POWER_B20V_PORT          GPIOC
#define         POWER_B20V_PIN           GPIO_Pin_7
#define         POWER_B20V_CLOCK         RCC_APB2Periph_GPIOC

#define         POWER_C6V4_PORT          GPIOC
#define         POWER_C6V4_PIN           GPIO_Pin_8
#define         POWER_C6V4_CLOCK         RCC_APB2Periph_GPIOC

#define         BUZZER_PORT          GPIOC
#define         BUZZER_PIN           GPIO_Pin_9
#define         BUZZER_CLOCK         RCC_APB2Periph_GPIOC





void AOUTPUT_Config(void);

void AA_STOP(void);
void AA_GOFORWARD(void);
void AA_BACKUP(void);

void BB_STOP(void);
void BB_GOFORWARD(void);
void BB_BACKUP(void);

void CC_STOP(void);
void CC_GOFORWARD(void);
void CC_BACKUP(void);

void DD_STOP(void);
void DD_GOFORWARD(void);
void DD_BACKUP(void);




void POWER_A24V_OPEN(void);
void POWER_A24V_CLOSE(void);

void POWER_B20V_OPEN(void);
void POWER_B20V_CLOSE(void);

void POWER_C6V4_OPEN(void);
void POWER_C6V4_CLOSE(void);



void BUZZER_OPEN(void);
void BUZZER_CLOSE(void);




#endif // __AOUTPUT_H

