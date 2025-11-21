#ifndef __STM32F_GPIO_LIB_H__
#define __STM32F_GPIO_LIB_H__
#include "stm32f4_gpio_driver.h"

#define GPIO_PIN_0 ((uint16_t)0x0001)	//1u<<0
#define GPIO_PIN_1 ((uint16_t)0x0002)	//1u<<1
#define GPIO_PIN_2 ((uint16_t)0x0004)	//1u<<2
#define GPIO_PIN_3 ((uint16_t)0x0008)	//1u<<3
#define GPIO_PIN_4 ((uint16_t)0x0010) //1u<<4
#define GPIO_PIN_5 ((uint16_t)0x0020)	//1u<<5
#define GPIO_PIN_6 ((uint16_t)0x0040)	//1u<<6
#define GPIO_PIN_7 ((uint16_t)0x0080)	//1u<<7
#define GPIO_PIN_8 ((uint16_t)0x0100)	//1u<<8
#define GPIO_PIN_9 ((uint16_t)0x0200)	//1u<<9
#define GPIO_PIN_10 ((uint16_t)0x0400)	//1u<<10
#define GPIO_PIN_11 ((uint16_t)0x0800)	//1u<<11
#define GPIO_PIN_12 ((uint16_t)0x1000)	//1u<<12
#define GPIO_PIN_13 ((uint16_t)0x2000)	//1u<<13
#define GPIO_PIN_14 ((uint16_t)0x4000)	//1u<<14
#define GPIO_PIN_15 ((uint16_t)0x8000)	//1u<<15

#define GPIO_INPUT_MODE 		0x00u
#define	GPIO_OUTPUT_MODE 		0x01u
#define GPIO_ALTERNATE_MODE 0x02u
#define GPIO_ANALOG					0x03u

#define GPIO_NO_PULLUP_PULLDOWN 0x00u
#define GPIO_PULLUP 0x01u
#define GPIO_PULLDOWN 0x02u
#define GPIO_RESERVED 0x03u

typedef struct{
	uint32_t Pin;
	uint32_t Mode;
	uint32_t Speed;
	uint32_t Pull;
	uint32_t Alt;
}GPIO_InitTypeDef;

typedef enum
{
	GPIO_PIN_RESET=0,
	GPIO_PIN_SET
}GPIO_PinState;

void LIB_GPIO_Init(GPIO_Typedef *GPIOx,GPIO_InitTypeDef *GPIO_Init);
GPIO_PinState LIB_GPIO_readPinstate(GPIO_Typedef * GPIOx,uint16_t Pin_number);
void LIB_GPIO_writePinstate(GPIO_Typedef* GPIOx,uint16_t Pin_number,GPIO_PinState state);
void LIB_GPIO_TogglePin(GPIO_Typedef* GPIOx,uint16_t Pin_number);
void LIB_GPIOA_CLK_ENABLE(void);
void LIB_GPIOB_CLK_ENABLE(void);
void LIB_GPIOC_CLK_ENABLE(void);
void LIB_GPIOD_CLK_ENABLE(void);
void LIB_GPIOE_CLK_ENABLE(void);
void LIB_GPIOH_CLK_ENABLE(void);
#endif