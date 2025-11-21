#ifndef	__MY_STM32F4_USART_DRIVER_H__
#define __MY_STM32F4_USART_DRIVER_H__
#include "my_stm32f4_gpio_driver.h"
#define USART2_START	(PERIPHERAL_BASE+0x4400u)
#define  __IO		volatile
typedef struct 
{
		__IO	uint32_t SR;
		__IO 	uint32_t DR;
	  __IO  uint32_t BRR;
	  __IO  uint32_t CR1;
	  __IO  uint32_t CR2;
	  __IO  uint32_t CR3;
	  __IO  uint32_t GTPR;
	
}USART_t;

#define USART2	((USART_t *)USART2_START)
#endif