# include "stm32f4_gpio_lib.h"
#include <stdio.h>
GPIO_InitTypeDef GPIO_INIT;
int main()
{
	GPIO_INIT.Mode=GPIO_OUTPUT_MODE;
	GPIO_INIT.Pin=GPIO_PIN_5 ;
	GPIO_INIT.Pull=GPIO_NO_PULLUP_PULLDOWN;
	
	LIB_GPIOA_CLK_ENABLE();
	LIB_GPIO_Init(GPIOA,&GPIO_INIT);
	while(1)
	{
		for(int i=0;i<900000;i++)
		{}
			LIB_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
			printf("hi\n");
	}
}