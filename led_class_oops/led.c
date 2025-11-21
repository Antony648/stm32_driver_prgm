#include "led.h"
#include <stdio.h>

void Led_ctor(Led * const led_obj,LedColor_Type _color,LedState_Type _state)
{
	RCC->AHB1ENR |=LED_PORT_CLOCK;
	led_obj->color=_color;
	led_obj->state=_state;
	
	switch(_color)
	{
		case RED:
			GPIOB->MODER |=LED_RED_MODE_BIT;
			if(led_obj->state==ON)
			{
				GPIOB->ODR|=LED_RED_PIN;
			}
			else 
				GPIOB->ODR&= ~(LED_RED_PIN);
			break;
		case BLUE:
			GPIOB->MODER |=LED_BLUE_MOD_BIT ;
			if(led_obj->state==ON)
				GPIOB->ODR |=LED_BLUE_PIN;
			else
				GPIOB->ODR &= ~(LED_BLUE_PIN);
			break;
			
		case YELLOW:
			GPIOB->MODER |=LED_YELLOW_MODE_BIT;
			if(led_obj->state ==ON)
				GPIOB->ODR |=LED_YELLOW_PIN;
			else
				GPIOB->ODR &= ~(LED_YELLOW_PIN);
			break;
			
		case GREEN:
			GPIOB->MODER |=LED_GREEN_MODE_BIT;
			if(led_obj->state ==ON)
				GPIOB->ODR |=LED_GREEN_PIN;
			else
				GPIOB ->ODR &= ~(LED_GREEN_PIN);
			break;
			
	}
}
void Led_setstate(Led *const led_obj,LedState_Type _state_over) 
{
	led_obj->state=_state_over;
	
	
	switch(led_obj->color){
		case RED:
			printf("the red led is set to state %d \n\t",led_obj->state);
			break;
		case YELLOW:
			printf("the yellow led is set to state %d \n\t",led_obj->state);
			break;
		case BLUE:
			printf("the blue led is set to state %d \n\t",led_obj->state);
			break;
		case GREEN:
			printf("the green led is set to state %d \n\t",led_obj->state);
			break;
	}
		
}
LedState_Type Led_getstate(Led *const led_obj)
{
	switch(led_obj->color){
		case RED:
			printf("the red led is set to state %d \n\t",led_obj->state);
			break;
		case YELLOW:
			printf("the yellow led is set to state %d \n\t",led_obj->state);
			break;
		case BLUE:
			printf("the blue led is set to state %d \n\t",led_obj->state);
			break;
		case GREEN:
			printf("the green led is set to state %d \n\t",led_obj->state);
			break;
	
	return led_obj->state;
}