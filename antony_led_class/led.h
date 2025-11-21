#ifndef _LED_H
#define _LED_H
#include <stdint.h>
#include "stm32f4xx.h"

#define RED_LED_PIN (1U<<14)
#define GREEN_LED_PIN (1U<<12)
#define BLUE_LED_PIN (1U<<15)
#define YELLOW_LED_PIN (1U<<13)

/*
00:input
01:output
10:alternate function
11:analog
*/

#define RED_MODER_BIT (1U<<28)
#define GREEN_MODER_BIT (1U<<24)
#define BLUE_MODER_BIT (1U<<30)
#define YELLOW_MODER_BIT (1U<<26)

typedef enum
{
	ON=1,
	OFF=0
}LED_state;

typedef enum
{
	RED,GREEN,BLUE,YELLOW
}LED_color;
typedef enum
{
	DIAM_SMALL=2,
	DIAM_NORMAL=5,
	DIAM_HIGH= 7
}LED_diameter;

typedef enum
{
	VOLT_LOW=2,
	VOLT_NORMAL=5,
	VOLT_HIGH=7
}LED_voltage;

typedef enum
{
	CURR_LOW=2,
	CURR_HIGH=9,
	CURR_NORMAL=5
}LED_current;


class LED
{
	private:
		LED_color color;
		LED_current current;
		LED_diameter diameter;
		LED_state state;
		LED_voltage voltage;
	public:
		LED(LED_color _color,
						 LED_current _current,
						 LED_diameter _diam,
						 LED_state _state,
						 LED_voltage _voltage);
	//void LED_CHANGE_COLOR(LED_color _color);
	void LED_CHANGE_VOLTAGE(LED_voltage _voltage);
	void LED_CHANGE_STATE(LED_state _state);
	void LED_CHANGE_CURRENT(LED_current _current);
	
	
	uint8_t LED_GET_COLOR();
	uint8_t LED_GET_VOLTAGE();
	uint8_t LED_GET_STATE();
	uint8_t LED_GET_CURRENT();
	uint8_t LED_GET_DIAMETER();
	uint8_t LED_GET_POWER();
	
};
#endif