//#include "stm32f4xx.h"                  // Device header

#include "stm32f4_gpio_driver.h"
int main()
{
	RCC->AHB1ENR |= GPIOA_EN|GPIOB_EN;
	GPIOA->MODER |= PIN5_OUT_MOD;
	GPIOB->MODER |= PIN5_OUT_MOD;
	while(1)
	{
		for(int i=0;i<900000;i++)
			GPIOA->ODR ^=LED_PIN;
			GPIOB->ODR ^=LED_PIN;
	}
	
}