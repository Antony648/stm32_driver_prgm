#ifndef _POWERLED_H
#define _POWERLED_H		//used to avoid conflicts

#include "led.h"
//creating an alias for uint8_t 

typedef uint8_t led_elec_type;	//for led_elec_type
typedef uint8_t led_dim_type;		//for led_dim_type

typedef enum
{
	CURR_LOW=10, //set low current to 10mA
	CURR_NORMAL=20,
	CURR_HIGH=35,
	CURR_VERY_HIGH=60
}LedCurrnet_Type;

typedef enum
{
	DIAM_2MM=2,
	DIAM_5MM=5,
	DIAM_7MM=7
}LedDiameter_Type;

typedef enum
{
	VOLTAGE_LOW=3,
	VOLTAGE_NORMAL=5,
	VOLTAGE_HIGH=9
}LedVoltage_Type;

typedef struct
{
	Led super;
	LedDiameter_Type  diameter;
	LedCurrnet_Type current;
	LedVoltage_Type voltage;
	
}PowerLed_Type;

void PowerLed_ctor(PowerLed_Type* const pled_obj,
									LedColor_Type _color,
									LedState_Type _state,
									LedCurrnet_Type _current,
									LedDiameter_Type _diameter,
									LedVoltage_Type _voltage);

void PowerLed_setcurrent(PowerLed_Type* const pled_obj, LedCurrnet_Type _current);
void PowerLed_setvoltage(PowerLed_Type* const pled_obj, LedVoltage_Type _voltage);
void PowerLed_setdiameter(PowerLed_Type* const pled_obj, LedDiameter_Type _diameter);

void PowerLed_diagnostics(PowerLed_Type const*const obj);
uint32_t PowerLed_effeciency(PowerLed_Type const*const obj);

led_elec_type Powerled_powerconsumed(PowerLed_Type* const pled_obj);
led_elec_type Powerled_getcurrent(PowerLed_Type* const pled_obj);
led_elec_type Powerled_getvoltage(PowerLed_Type* const pled_obj);
led_elec_type Powerled_getdiameter(PowerLed_Type* const pled_obj);
#endif  