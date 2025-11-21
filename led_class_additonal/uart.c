#include "uart.h"
void USART2_Init(void)
{
	//1.enable clock access to uart2
	RCC->APB1ENR|= 0X20000;	
	/* to set apb bus to enable clock cycle by setting its 17th bit to one 
	 for RX and TX*/
	
	//2.enable clock access to port A
	RCC->AHB1ENR = 0X01;
	/* to set ahb bus to enable clock cycle by setting its 1st bit to one 
	for PORT A*/
	
	//3.enable pins for alternate functions in pa2,pa3
	GPIOA->MODER &=~ 0x00F0;
	GPIOA->MODER |= 0x00A0;
	
	//4.configure type of alternate functions for pins because there are different varities
	GPIOA->AFR[0] &= ~0xFF00;
	GPIOA->AFR[0] |= 0x7700;
	
	//cofigure uart
	USART2->BRR =0x0683;
	USART2->CR1 =0x000c;
	USART2->CR2 =0x000;
	USART2->CR3= 0X000;
	USART2-> CR1 |=0X2000;
	
}

int USART2_write(int ch)
{	
	while(!(USART2->SR & 0x0080)){}
		// the function waits till  status register's 7th bit is one
		// if 7th bit is one it will return 0x00800 which will be evaluated to true 
		//which will be inverted, so it stays in the loop till 7th bit of sr is zero
		
	USART2->DR=(ch & 0xFF);
	return ch;
}
int USART2_read(void)
{
	while(!(USART2->SR & 0x0020)){}
		//
	return USART2->DR;
}

//all these are redefintion of file in standard IO in c

/*#ifndef __STDIO_H
 
struct __FILE {
    int handle;
};
#endif*/


FILE __stdin={0};
FILE __stdout={1};
FILE __stderr={3};

int fgetc(FILE *f __attribute((unused)))
{
	 int c;
	 
	 c=USART2_read();
	 if (c =='\r')
	 {
		 USART2_write(c);
		 c='\n';
	 }
	 USART2_write(c);
	 return c;
}

int fputc(int c,FILE *f __attribute((unused)))
{
	
	return USART2_write(c);
}

int n;char str[80];
void test_setup()
{
	printf("Enter the input integer value:");
	scanf("%d",&n);
	printf(" number is %d",n);
	printf("Enter the string inputr:");
	gets(str);
	printf("String inputed is");
	puts(str);
	printf("\n'\r");
}