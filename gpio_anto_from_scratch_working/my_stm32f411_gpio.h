#ifndef __MY_STM32F411_GPIO_H__ 
#define __MY_STM32F411_GPIO_H__
#include "my_stm32f4_gpio_driver.h"

typedef enum
{
	PIN_0=0x0000u,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7,
	PIN_8,
	PIN_9,
	PIN_10,
	PIN_11,
	PIN_12,
	PIN_13,
	PIN_14,
	PIN_15
}PIN_NO_t;

typedef enum
{
	INPUT=0x00u,
	OUTPUT,
	ALTERNATE,
	ANALOG
}MODE_t;

typedef enum
{
	PUSH_PULL=0x0u,
	OUTPUT_DRAIN
}OTYPE_t;

typedef enum
{
	LOW_SPEED   =0x00u,
	MEDIUM_SPEED,
	FAST_SPEED,
	HIGH_SPEED
}OSPEED_t;

typedef enum
{
	NOPULLUP_NOPULLDOWN=0x00u,
	PULLUP,
	PULLDOWN,
	RESERVED
}PUPD_t;

typedef enum
{
	NOBS_NOBR=0x00u,
	BS_NOBR,
	NOBS_BR,
	BS_BR
}BSRR_t;

typedef enum
{
	ALT_F0 =0x0u,
	ALT_F1,
	ALT_F2,
	ALT_F3,
	ALT_F4,
	ALT_F5,
	ALT_F6,
	ALT_F7,
	ALT_F8,
	ALT_F9,
	ALT_F10,
	ALT_F11,
	ALT_F12,
	ALT_F13,
	ALT_F14,
	ALT_F15
}AFR_t;

//these states specified below are represented
//by odr and can be configured using 	bssr
typedef enum
{
	PIN_RESET=0x0u,
	PIN_SET
}GPIO_pin_state;

typedef struct
{
	PIN_NO_t Pin;
	MODE_t   Mode;
	OTYPE_t  Otype;
	OSPEED_t Ospeed;
	PUPD_t   Pupd;
	BSRR_t   Bsrr;
	AFR_t		 Afr;
	
}GPIO_pin_t;

class GPIO
{
	private:
		GPIO_pin_t		*PIN_OBJ;
		GPIO_port_t		*PORT_OBJ;
	public:
		GPIO(GPIO_port_t* port_obj,GPIO_pin_t* pin_obj);
};
GPIO_pin_state readpin(GPIO_port_t* port_obj,GPIO_pin_t* pin_obj);
void writepin(GPIO_port_t* port_obj,GPIO_pin_t* pin_obj,GPIO_pin_state state);
void Togglepin(GPIO_port_t* port_obj,GPIO_pin_t* pin_obj);
#endif