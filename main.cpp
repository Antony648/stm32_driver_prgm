#include "my_stm32f411_gpio.h"

void delay_seconds(int seconds) {
    volatile unsigned int count = seconds * 100000;  // Adjust for timing
    while (count--) { }  // Busy-wait loop
}
GPIO_pin_t PIN_OBJ;
int main()
{
	GPIOx_Enable(GPIOA_num);
	PIN_OBJ.Pin=PIN_5;
	//PIN_OBJ.Mode=OUTPUT;
	PIN_OBJ.Ospeed=HIGH_SPEED;
	PIN_OBJ.Otype=PUSH_PULL;
	PIN_OBJ.Pupd=NOPULLUP_NOPULLDOWN;
	GPIO gpio_obj(GPIOA,&PIN_OBJ);
	
	//GPIOA->ODR |=(uint32_t)(0x1u<<PIN_5);
	while(1)
	{
		delay_seconds(9);
		Togglepin(GPIOA,&PIN_OBJ);
	}
	
	
}