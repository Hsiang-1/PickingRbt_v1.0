#ifndef __BSP_GENERALTIME_H
#define __BSP_GENERALTIME_H


#include "stm32f10x.h"


// duty_cycle test datas

#define		       TIM2_OUT1	                  50
#define	           TIM2_OUT2	                  100
#define	           TIM2_OUT3	                  150
#define	           TIM2_OUT4	                  180

#define		       TIM3_OUT1                      0
#define		       TIM3_OUT2                      2500
#define		       TIM3_OUT3                      3500
#define		       TIM3_OUT4                      10000

#define		       TIM4_OUT1                      2000
#define		       TIM4_OUT2                      3000
#define		       TIM4_OUT3                      4000
#define		       TIM4_OUT4                      4500

// test data end



// definitions of TIM2/3/4

#define            GENERAL_TIM2                   TIM2
#define            GENERAL_TIM2_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            GENERAL_TIM2_CLK               RCC_APB1Periph_TIM2
#define            GENERAL_TIM2_Period            199
#define            GENERAL_TIM2_Prescaler         23

#define            GENERAL_TIM3                   TIM3
#define            GENERAL_TIM3_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            GENERAL_TIM3_CLK               RCC_APB1Periph_TIM3
#define            GENERAL_TIM3_Period            10000
#define            GENERAL_TIM3_Prescaler         35

#define            GENERAL_TIM4                   TIM4
#define            GENERAL_TIM4_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            GENERAL_TIM4_CLK               RCC_APB1Periph_TIM4
#define            GENERAL_TIM4_Period            10000
#define            GENERAL_TIM4_Prescaler         35


// to rename the corresponding ports

#define            GENERAL_TIM2_CH1_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM2_CH1_PORT          GPIOA
#define            GENERAL_TIM2_CH1_PIN           GPIO_Pin_0

#define            GENERAL_TIM2_CH2_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM2_CH2_PORT          GPIOA
#define            GENERAL_TIM2_CH2_PIN           GPIO_Pin_1

#define            GENERAL_TIM2_CH3_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM2_CH3_PORT          GPIOA
#define            GENERAL_TIM2_CH3_PIN           GPIO_Pin_2

#define            GENERAL_TIM2_CH4_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM2_CH4_PORT          GPIOA
#define            GENERAL_TIM2_CH4_PIN           GPIO_Pin_3


#define            GENERAL_TIM3_CH1_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM3_CH1_PORT          GPIOA
#define            GENERAL_TIM3_CH1_PIN           GPIO_Pin_6

#define            GENERAL_TIM3_CH2_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM3_CH2_PORT          GPIOA
#define            GENERAL_TIM3_CH2_PIN           GPIO_Pin_7

#define            GENERAL_TIM3_CH3_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM3_CH3_PORT          GPIOB
#define            GENERAL_TIM3_CH3_PIN           GPIO_Pin_0

#define            GENERAL_TIM3_CH4_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM3_CH4_PORT          GPIOB
#define            GENERAL_TIM3_CH4_PIN           GPIO_Pin_1


#define            GENERAL_TIM4_CH1_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM4_CH1_PORT          GPIOB
#define            GENERAL_TIM4_CH1_PIN           GPIO_Pin_6

#define            GENERAL_TIM4_CH2_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM4_CH2_PORT          GPIOB
#define            GENERAL_TIM4_CH2_PIN           GPIO_Pin_7

#define            GENERAL_TIM4_CH3_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM4_CH3_PORT          GPIOB
#define            GENERAL_TIM4_CH3_PIN           GPIO_Pin_8

#define            GENERAL_TIM4_CH4_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM4_CH4_PORT          GPIOB
#define            GENERAL_TIM4_CH4_PIN           GPIO_Pin_9


// define end





// declare of the functions


// the GPIO about TIM2/3/4 config

void GENERAL_TIM2_GPIO_Config(void);
void GENERAL_TIM3_GPIO_Config(void);
void GENERAL_TIM4_GPIO_Config(void);


// The time base structure init
void GENERAL_TIM2_Mode_Config(void);
void GENERAL_TIM3_Mode_Config(void);
void GENERAL_TIM4_Mode_Config(void);


// channel ctl

void TIM2_CH_Change(unsigned int channel, unsigned int value);
void TIM3_CH_Change(unsigned int channel, unsigned int value);
void TIM4_CH_Change(unsigned int channel, unsigned int value);

















#endif	/* __BSP_GENERALTIME_H */


