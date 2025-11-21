#include "my_stm32f411_gpio.h"


GPIO::GPIO(GPIO_port_t* port_obj,GPIO_pin_t* pin_obj)
{
	
	GPIO::PIN_OBJ=pin_obj;GPIO::PORT_OBJ=port_obj;
	uint32_t temp;
	uint32_t pin_pos= PIN_OBJ->Pin;
	
	temp=PORT_OBJ->MODER;
	temp &=~((uint32_t)(0x3u<<(pin_pos*0x2u)));
	temp |= (uint32_t)((PIN_OBJ->Mode)<<(pin_pos*0x2u));
	PORT_OBJ->MODER=temp;
	
	if(PIN_OBJ->Mode==OUTPUT)
	{
		//setting otyper
		temp=PORT_OBJ->OTYPER;
		temp&= ~((uint32_t)(0x01u <<pin_pos));
		temp |= (uint32_t)((PIN_OBJ->Otype)<<pin_pos);
		PORT_OBJ->OTYPER=temp;
		
		temp=PORT_OBJ->OSPEEDR;
		temp &=~((uint32_t)(0x3u<<(pin_pos*0x2u)));
		temp |= (uint32_t)((PIN_OBJ->Ospeed)<<(pin_pos*0x2u));
		PORT_OBJ->OSPEEDR=temp;
		
		temp=PORT_OBJ->BSRR;
		temp &= ~( (uint32_t)((0x1<<pin_pos)|(0x1<<(pin_pos+16u))) );
		temp |= (uint32_t)(((PIN_OBJ->Bsrr &0x1)<<pin_pos) |((PIN_OBJ->Bsrr >>0x1u)<<(pin_pos+16u)));
		PORT_OBJ->BSRR=temp;
	}
	if(PIN_OBJ->Mode ==ALTERNATE)
	{
		/*code for setting the alternate register*/
		temp=PORT_OBJ->AFR[pin_pos>>3];
		temp &=~((uint32_t)(0xfu<<((pin_pos & 0x7u)*0x4u)));
		temp |= (uint32_t)((PIN_OBJ->Afr)<<((pin_pos& 0x7u)*0x4u));
		PORT_OBJ->AFR[pin_pos>>3]=temp;
		
	}
	if (PIN_OBJ->Mode==INPUT || PIN_OBJ->Mode==OUTPUT)
	{
		temp=PORT_OBJ->PUPDR;
		temp &=~((uint32_t)(0x3u<<(pin_pos*0x2u)));
		temp |= (uint32_t)((PIN_OBJ->Pupd)<<(pin_pos*0x2u));
		PORT_OBJ->PUPDR=temp;
	}
	
}
GPIO_pin_state readpin(GPIO_port_t* port_obj,GPIO_pin_t* pin_obj)
{
	if( (port_obj->IDR)&(0x1u<<(pin_obj->Pin)) )
		return PIN_SET;
	else
		return PIN_RESET;
}

void writepin(GPIO_port_t* port_obj,GPIO_pin_t* pin_obj,GPIO_pin_state state)
{
	if(state != PIN_RESET)
		port_obj->BSRR |= (0x1u<<(pin_obj->Pin));
	else
		port_obj->BSRR |= (0x1u<<(pin_obj->Pin + 16));
}

void Togglepin(GPIO_port_t* port_obj,GPIO_pin_t* pin_obj)
{
	port_obj->ODR ^=(uint32_t)(01u<<pin_obj->Pin);
}