#ifndef __KEY_H
#define __KEY_H

#include "stm32f10x.h"

// YEHUO KEYA LOCATION
#define KEYA_PORT GPIOA
#define KEYA_PIN GPIO_Pin_0
#define KEYA_CLOCK RCC_APB2Periph_GPIOA

//KEYB
#define KEYB_PORT GPIOC
#define KEYB_PIN GPIO_Pin_13
#define KEYB_CLOCK RCC_APB2Periph_GPIOC

// THE LOCATIONS OF KEYS
#define KEYS_CONTROL_CLOCK RCC_APB2Periph_GPIOC

#define KEY_UP_PORT GPIOC
#define KEY_UP_PIN GPIO_Pin_8
#define KEY_UP_CLOCK RCC_APB2Periph_GPIOC

#define KEY_DOWN_PORT GPIOC
#define KEY_DOWN_PIN GPIO_Pin_10
#define KEY_DOWN_CLOCK RCC_APB2Periph_GPIOC

#define KEY_LEFT_PORT GPIOC
#define KEY_LEFT_PIN GPIO_Pin_9
#define KEY_LEFT_CLOCK RCC_APB2Periph_GPIOC

#define KEY_RIGHT_PORT GPIOC
#define KEY_RIGHT_PIN GPIO_Pin_11
#define KEY_RIGHT_CLOCK RCC_APB2Periph_GPIOC

// THE STATEMENTS OF KEYS
#define KEY_ON 1
#define KEY_OFF 0


void KEY_Config(void);
uint16_t Key_Scan( GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin );


#endif // __KEY_
