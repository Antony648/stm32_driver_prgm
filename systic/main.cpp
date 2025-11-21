#include "my_stm32f411_gpio.h"

#include "my_stm32f4_sys_tic_lib.h"
/*void delay_seconds(int seconds) {
    volatile unsigned int count = seconds * 100000;  // Adjust for timing
    while (count--) { }  // Busy-wait loop
}
void USAR_write(int c);
GPIO_pin_t PIN_OBJ;
GPIO_pin_t PIN_OBJ2;
*/

int main()
{
	GPIOx_Enable(GPIOA_num);			//enables gpioa by setting ahbr1 accordingly
	GPIO_pin_t pin_obj;
	pin_obj.Mode=OUTPUT;
	pin_obj.Pin=PIN_5;
	pin_obj.Pupd=NOPULLUP_NOPULLDOWN;
	GPIO gpio_obj(GPIOA,&pin_obj);
	
	//systic timer configuration
	SYSTIC_TIMER->SYST_RVR= 16000000 -1;	//we are to set 16million to cvr so it can 
	//count  so as to  get a 16Mhz,the program only continues if count flag is 
	// is set to 0 so we use 16000000-1 instead of 16000000.																	
	SYSTIC_TIMER->SYST_CSR=5;		//processor clock enabled and counter is enabled
	SYSTIC_TIMER->SYST_CVR=0;
	
	/* When ENABLE is set to 1, the counter loads the RELOAD value from the SYST_RVR  
	register and then counts down. On reaching 0, it sets the COUNTFLAG to 1 and  
	optionally asserts theSysTick depending on the value of TICKINT. It then loads 
	the RELOAD value again, and  begins counting*/
	
	
	while(1)
	{
		/*if(SYSTIC_TIMER->SYST_CSR & 0x10000)
		{
			Togglepin(GPIOA,&pin_obj);
		}*/
		systic_delay_ms(500);
		Togglepin(GPIOA,&pin_obj);
	}
}
