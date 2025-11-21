#include "medical_led.h"
void medical_led_diagnostic(medical_led const* const obj)
{
	/*implementation of algorithm to (dummy)*/
	printf("Algorithm to perform diagnostics on medical led\n");
}
uint32_t medical_led_effeciency(medical_led const* const obj)
{
	/*algorithm to compute medical led effeciency(dummy)*/
	printf("Algorithm to perform effeciency calculation on medical led\n");
	return 1;
}

void medical_led_ctor(medical_led* obj,Led_Wavelength wavelen,
											LedState_Type _state,LedColor_Type _color)
{
	static struct  LedVtable vtable={
		(void(*)(Led const * const obj))&medical_led_diagnostic,
		(uint32_t(*)(Led const * const obj))&medical_led_effeciency
	};
	obj->wavelength= wavelen;
	obj->super.color= _color;obj->super.state=_state;
	obj->super.virt =&vtable;
}

Led_Wavelength medical_led_getwave(medical_led* obj){
	return obj->wavelength;
}

void medical_led_setwave(medical_led* obj,Led_Wavelength wave)
{
	obj->wavelength=wave;
}