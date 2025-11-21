#include "stm32f4_gpio_lib.h"
#include <stdint.h>
#define GPIO_NUM 		16u
#define GPIO_MODER_MODE0	0x3u<<0
#define GPIO_MODE					0x3u
#define GPIO_PUPDR				0X03U<<0

void LIB_GPIO_Init(GPIO_Typedef *GPIOx,GPIO_InitTypeDef *GPIO_Init)
{
	/*the aim of this function is to set the values of GPIOx based on the values
	of GPIO_Init*/
	uint32_t temp=0x0u,position,ioposition=0x00u,iocurrent=0x00u;
	for(position=0x00;position< GPIO_NUM;position++)
	{
		ioposition=0x01u<<position;
		iocurrent=(GPIO_Init->Pin) &ioposition;
		if(iocurrent == ioposition)  //if(iocurrent!=0x00u)
		{
				temp=GPIOx->MODER;
				temp &=~(GPIO_MODER_MODE0 <<(position *2u));
				//we are clearing the space in register for storing the gpio mode for the pin
				temp |= (GPIO_Init->Mode & GPIO_MODE)<<(position*2u);
				//we are setting the value in GPIO_Init->Mode at the position we cleared earlier
				//we have to make sure that all the bits except last two bits must be 0,we perform
				//bitwise and operation using 0x3 to make sure of this
				// then to put these bits in the right place we use positon multipled by 2 because 
				// two bits are used to represent the output mode of  a pin
				GPIOx->MODER=temp;
			
				temp=GPIOx->PUPDR;
				temp &=~(GPIO_MODER_MODE0 <<(position *2u));
				temp |= (GPIO_Init->Pull & GPIO_MODE)<<(position*2u);
				GPIOx->PUPDR=temp;
		}
	}
}
GPIO_PinState LIB_GPIO_readPinstate(GPIO_Typedef * GPIOx,uint16_t Pin_number)
{
	GPIO_PinState rtnval;
	if((GPIOx->IDR & Pin_number)!=GPIO_PIN_RESET)
	{
		rtnval =GPIO_PIN_SET;
	}
	else
		rtnval=GPIO_PIN_RESET;
	return rtnval;
			
}
void LIB_GPIO_writePinstate(GPIO_Typedef* GPIOx,uint16_t Pin_number,GPIO_PinState state)
{
	if(state != GPIO_PIN_RESET)
	{
		GPIOx->BSRR=(uint32_t)Pin_number;
	}
	else
		GPIOx->BSRR=(uint32_t)Pin_number<<16;
}
void LIB_GPIO_TogglePin(GPIO_Typedef* GPIOx,uint16_t Pin_number)
{
	GPIOx->ODR ^=(uint32_t)Pin_number;
}

void LIB_GPIOA_CLK_ENABLE(void){RCC->AHB1ENR|= GPIOA_EN;}
void LIB_GPIOB_CLK_ENABLE(void){RCC->AHB1ENR|= GPIOB_EN;}
void LIB_GPIOC_CLK_ENABLE(void){RCC->AHB1ENR|= GPIOC_EN;}
void LIB_GPIOD_CLK_ENABLE(void){RCC->AHB1ENR|= GPIOD_EN;}
void LIB_GPIOE_CLK_ENABLE(void){RCC->AHB1ENR|= GPIOE_EN;}
void LIB_GPIOH_CLK_ENABLE(void){RCC->AHB1ENR|= GPIOH_EN;}

