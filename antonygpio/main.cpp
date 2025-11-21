#include "stm32f4_cpp_gpio_lib.h"
GPIO_InitTypeDef GPIO_INIT;

int main()
{
	
	GPIO_INIT.Mode=GPIO_OUTPUT_MODE;
	GPIO_INIT.Pin=GPIO_PIN_5 ;
	GPIO_INIT.Pull=GPIO_NO_PULLUP_PULLDOWN;
	
	GPIO output(GPIO_A, GPIOA,&GPIO_INIT);
	while(1)
	{
		for(int i=0;i<900000;i++)
		{}
			output.LIB_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
		
	}
	return  0;
}