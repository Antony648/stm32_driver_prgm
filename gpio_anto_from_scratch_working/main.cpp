#include "my_stm32f411_gpio.h"
#include "my_stm32f4_usart_driver.h"
void delay_seconds(int seconds) {
    volatile unsigned int count = seconds * 100000;  // Adjust for timing
    while (count--) { }  // Busy-wait loop
}
void USAR_write(int c);
GPIO_pin_t PIN_OBJ;
GPIO_pin_t PIN_OBJ2;
int main()
{
	/*GPIOx_Enable(GPIOA_num);
	PIN_OBJ.Pin=PIN_5;
	PIN_OBJ.Mode=OUTPUT;
	PIN_OBJ.Ospeed=HIGH_SPEED;
	PIN_OBJ.Otype=PUSH_PULL;
	PIN_OBJ.Pupd=NOPULLUP_NOPULLDOWN;
	GPIO gpio_obj(GPIOA,&PIN_OBJ);
	
	//GPIOA->ODR |=(uint32_t)(0x1u<<PIN_5);
	while(1)
	{
		delay_seconds(9);
		Togglepin(GPIOA,&PIN_OBJ);
	}*/
	
	GPIOx_Enable(GPIOA_num);
	RCC->APB1ENR|=0x2000u;
	USART2->BRR=0X0683;
	USART2->CR1 |=(0x1u << 13);
	USART2->CR1 |=(0x1u <<3);
	//to put pin2 to alternate function 7
	PIN_OBJ.Pin=PIN_2;
	PIN_OBJ.Mode=ALTERNATE;
	PIN_OBJ.Afr=ALT_F7;
	GPIO gpio_obj2(GPIOA,&PIN_OBJ);
	
	GPIOx_Enable(GPIOA_num);
	PIN_OBJ2.Pin=PIN_3;
	PIN_OBJ2.Mode=ALTERNATE;
	PIN_OBJ2.Afr=ALT_F7;
	GPIO gpio_obj3(GPIOA,&PIN_OBJ2);
	
	while(1)
	{
		USAR_write('Y');
		USAR_write('e');
		USAR_write('s');
		USAR_write('\r');
		USAR_write('\n');
	}
}
void USAR_write(int c)
{
	while(!(USART2->SR & 0x0080))
	{
		
	}
	USART2->DR = (c & 0xFF);
}