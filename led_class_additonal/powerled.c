#include "powerled.h"
void PowerLed_ctor(PowerLed_Type* const pled_obj,
									LedColor_Type _color,
									LedState_Type _state,
									LedCurrnet_Type _current,
									LedDiameter_Type _diameter,
									LedVoltage_Type _voltage)
{
	Led_ctor(&pled_obj->super,_color,_state);
	pled_obj->current=_current;
	pled_obj->diameter=_diameter;
	pled_obj->voltage=_voltage;
	
}
void PowerLed_setcurrent(PowerLed_Type* const pled_obj, LedCurrnet_Type _current)
{
	pled_obj->current=_current;
}


void PowerLed_setvoltage(PowerLed_Type* const pled_obj, LedVoltage_Type _voltage)
{
	pled_obj->voltage=_voltage;
}


void PowerLed_setdiameter(PowerLed_Type* const pled_obj, LedDiameter_Type _diameter)
{
	pled_obj->diameter=_diameter;
}


led_elec_type Powerled_powerconsumed(PowerLed_Type* const pled_obj)
{
	return pled_obj->current *pled_obj->voltage;
}


led_elec_type Powerled_getcurrent(PowerLed_Type* const pled_obj)
{
	return pled_obj->current;
}


led_elec_type Powerled_getvoltage(PowerLed_Type* const pled_obj)
{
	return pled_obj->voltage;
}


led_elec_type Powerled_getdiameter(PowerLed_Type* const pled_obj)
{
	return pled_obj->diameter;
}