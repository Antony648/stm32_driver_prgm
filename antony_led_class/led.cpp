#include "led.h"


LED::LED(LED_color _color,
						 LED_current _current,
						 LED_diameter _diam,
						 LED_state _state,
						 LED_voltage _voltage)
{
	RCC->AHB1ENR |= 0X02;	//turn the 2bit to high for clk enable in gpioB
	
	this->color=_color;this->current=_current;
	this->diameter=_diam;this->state=_state;this->voltage=_voltage;
	
	
	//abstraction completed real board stuff starts here.
	
	switch(this->color)
	{
		case RED:
			GPIOB->MODER |= RED_MODER_BIT;
			if(this->state==ON)
				GPIOB->ODR |= RED_LED_PIN;
			else
				GPIOB->ODR &= ~(RED_LED_PIN);
			break;
			
		case BLUE:
			GPIOB->MODER |= BLUE_MODER_BIT;
			if(this->state==ON)
				GPIOB->ODR |= BLUE_LED_PIN;
			else
				GPIOB->ODR &= ~(BLUE_LED_PIN);
			break;
			
		case GREEN:
			GPIOB->MODER |= GREEN_MODER_BIT;
			if(this->state==ON)
				GPIOB->ODR |= GREEN_LED_PIN;
			else
				GPIOB->ODR &= ~(GREEN_LED_PIN);
			break;
			
		case YELLOW:
			GPIOB->MODER |= YELLOW_MODER_BIT;
			if(this->state==ON)
				GPIOB->ODR |= YELLOW_LED_PIN;
			else
				GPIOB->ODR &= ~(YELLOW_LED_PIN);
			break;
			
	}
	
}
void LED::LED_CHANGE_STATE(LED_state _state)
{
	this->state=_state;
	switch(this->color)
	{
		case RED:
			
			if(this->state==ON)
				GPIOB->ODR |= RED_LED_PIN;
			else
				GPIOB->ODR &= ~(RED_LED_PIN);
			break;
			
		case BLUE:
			
			if(this->state==ON)
				GPIOB->ODR |= BLUE_LED_PIN;
			else
				GPIOB->ODR &= ~(BLUE_LED_PIN);
			break;
			
		case GREEN:
			
			if(this->state==ON)
				GPIOB->ODR |= GREEN_LED_PIN;
			else
				GPIOB->ODR &= ~(GREEN_LED_PIN);
			break;
			
		case YELLOW:
			
			if(this->state==ON)
				GPIOB->ODR |= YELLOW_LED_PIN;
			else
				GPIOB->ODR &= ~(YELLOW_LED_PIN);
			break;
			
	}
	
}
/*void LED::LED_GET_COLOR(LED_color _color)
{
	this->color=_color;
}*/
void LED::LED_CHANGE_VOLTAGE(LED_voltage _voltage)
{
	this->voltage=_voltage;
}
void LED::LED_CHANGE_CURRENT(LED_current _current)
{
	this->current=_current;
}
uint8_t LED::LED_GET_COLOR()
{
	return this->color;
}
uint8_t LED::LED_GET_VOLTAGE()
{
	return this->voltage;
}
uint8_t LED::LED_GET_STATE()
{
	return this->state;
}
uint8_t LED::LED_GET_CURRENT()
{
	return this->current;
}
uint8_t LED::LED_GET_DIAMETER()
{
		return this->diameter;
}
uint8_t LED::LED_GET_POWER()
{
		return this->current *this->voltage;
}
	