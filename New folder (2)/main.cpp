#include "my_stm32f411_gpio.h"
#include <stdio.h>
GPIO_pin_t PIN_OBJ;
int main()
{
	PIN_OBJ.Pin=PIN_5;
	PIN_OBJ.Mode=OUTPUT;
	PIN_OBJ.Pupd=NOPULLUP_NOPULLDOWN;
	GPIO gpio_obj(GPIOA,&PIN_OBJ);
	
	while(1)
	{
		for(int i=0;i<90000;i++);
		Togglepin(GPIOA,&PIN_OBJ);
		printf("value is %d",PIN_OBJ.Pin);
		//printf("hello world!");
	}
	
	
}