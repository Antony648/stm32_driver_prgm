#ifndef __MEDICAL_H
#define __MEDICAL_H

#include "led.h"

typedef enum
{
	INFRARED=690,
	NEAR_INFRARED= 880
}Led_Wavelength;
typedef struct
{
	Led super;
	Led_Wavelength wavelength;
}medical_led;

void medical_led_ctor(medical_led* obj,Led_Wavelength wavelen,
											LedState_Type _state,LedColor_Type _color);
Led_Wavelength medical_led_getwave(medical_led* obj);
void medical_led_setwave(medical_led* obj,Led_Wavelength wave);
void medical_led_diagnostic(medical_led const* const obj);
uint32_t medical_led_effeciency(medical_led const* const obj);
#endif