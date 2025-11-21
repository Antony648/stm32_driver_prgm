#include "my_stm32f4_usart.h"

#define CR1_CNF1_RX		0x0004
#define BRR_CNF1			0x0683
#define BRR_CNF2			0x008b
#define CR1_CNF1_TX		0x0008
#define CR2_CNF1			0x0000
#define CR3_CNF1			0x0000
#define USART2_CR1_EN1		0x2000		//enable usart
#define USART2_CR1_DIS		0x0000		//disable usart
//GPIOx_Enable(GPIOA_num);
//	RCC->APB1ENR|=0x2000u;
//	USART2->BRR=0X0683;
//	USART2->CR1 |=(0x1u << 13);
//	USART2->CR1 |=(0x1u <<3);
void LIB_USART_Init(USART_com_t comtype,USART_BAUD baud_rate)
{
	USART2->CR1 =USART2_CR1_DIS;
	switch(comtype)
	{
		case TX_ONLY:
			GPIOA->MODER |= 0x0020
			GPIOA->AFR[0] |=0x0700;
			USART2->CR1 =CR1_CNF1_TX;
			break;
		case RX_ONLY:
			GPIOA->MODER |=0x080;
			GPIOA->AFR[0] |= 0x7000;
			USART2->CR1= CR1_CNF1_RX;
			break;
		case RX_AND_TX:
			GPIOA->MODER |= 0x0020 | 0x0080;
			GPIOA->AFR[0] |=0x7000 |0x0700;
			USART2->CR1  |= CR1_CNF1_RX|CR1_CNF1_TX;
			break;
		default:
			break;
	}
	switch(baud_rate)
	{
		case __115200:
			USART2->BRR=BRR_CNF1;
			break;
		case __9600:
			USART2->BRR=BRR_CNF2;
			break;
		default:
			break;
	}
	USART2->CR2=CR2_CNF1;
	USART2->CR3=CR3_CNF1;
	USART2->CR1 |=USART2_CR1_EN1;
}