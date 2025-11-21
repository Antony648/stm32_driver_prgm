#include "led.h"
#include <stdio.h>

Led::Led (LedColor_Type _color,LedState_Type _state)
{
	RCC->AHB1ENR |=LED_PORT_CLOCK;
	this->color=_color;
	this->state=_state;
	
	switch(_color)
	{
		case RED:
			GPIOB->MODER |=LED_RED_MODE_BIT;
			if(this->state==ON)
			{
				GPIOB->ODR|=LED_RED_PIN;
			}
			else 
				GPIOB->ODR&= ~(LED_RED_PIN);
			break;
		case BLUE:
			GPIOB->MODER |=LED_BLUE_MOD_BIT ;
			if(this->state==ON)
				GPIOB->ODR |=LED_BLUE_PIN;
			else
				GPIOB->ODR &= ~(LED_BLUE_PIN);
			break;
			
		case YELLOW:
			GPIOB->MODER |=LED_YELLOW_MODE_BIT;
			if(this->state ==ON)
				GPIOB->ODR |=LED_YELLOW_PIN;
			else
				GPIOB->ODR &= ~(LED_YELLOW_PIN);
			break;
			
		case GREEN:
			GPIOB->MODER |=LED_GREEN_MODE_BIT;
			if(this->state ==ON)
				GPIOB->ODR |=LED_GREEN_PIN;
			else
				GPIOB ->ODR &= ~(LED_GREEN_PIN);
			break;
			
	}
}
void Led::Led_setstate(LedState_Type _state_over) 
{
	this->state=_state_over;
	
	
	switch(this->color){
		case RED:
			printf("the red led is set to state %d \n\t",this->state);
			break;
		case YELLOW:
			printf("the yellow led is set to state %d \n\t",this->state);
			break;
		case BLUE:
			printf("the blue led is set to state %d \n\t",this->state);
			break;
		case GREEN:
			printf("the green led is set to state %d \n\t",this->state);
			break;
	}
		
}
LedState_Type Led::Led_getstate() const
{
	switch(this->color){
		case RED:
			printf("the red led is set to state %d \n\t",this->state);
			break;
		case YELLOW:
			printf("the yellow led is set to state %d \n\t",this->state);
			break;
		case BLUE:
			printf("the blue led is set to state %d \n\t",this->state);
			break;
		case GREEN:
			printf("the green led is set to state %d \n\t",this->state);
			break;
	}
	return this->state;
}
