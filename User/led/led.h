#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"

#define         LED_CLOCK           RCC_APB2Periph_GPIOB

#define         LED_B_PORT          GPIOB
#define         LED_B_PIN           GPIO_Pin_1
#define         LED_B_CLOCK         RCC_APB2Periph_GPIOB

#define         LED_R_PORT          GPIOB
#define         LED_R_PIN           GPIO_Pin_5
#define         LED_R_CLOCK         RCC_APB2Periph_GPIOB

#define         LED_G_PORT          GPIOB
#define         LED_G_PIN           GPIO_Pin_0
#define         LED_G_CLOCK         RCC_APB2Periph_GPIOB

#define         LED_ON              1
#define         LED_OFF             0

#define     LED_B(i)    \
            if(i == 1)  GPIO_ResetBits(LED_B_PORT,LED_B_PIN);       \
            else        GPIO_SetBits(LED_B_PORT,LED_B_PIN); 

#define     LED_B_TOGGLE            {LED_B_PORT->ODR ^= LED_B_PIN;}



void LED_Config(void);
void LED_R_ON(void);
void LED_G_ON(void);
void LED_B_ON(void);
void LED_Y_ON(void);
void LED_R_OFF(void);
void LED_G_OFF(void);
void LED_B_OFF(void);
void LED_Y_OFF(void);

#endif // __LED_H
