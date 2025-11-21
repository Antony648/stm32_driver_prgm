#ifndef			__MY_STM32F4_USART_H__
#define			__MY_STM32F4_USART_H__

#include "my_stm32f4_usart_driver.h"
typedef enum
{
	RX_ONLY=0,
	TX_ONLY,
	RX_AND_TX
}USART_com_t;

typedef enum
{
	__115200=0,
	__9600
}USART_BAUD;
#endif