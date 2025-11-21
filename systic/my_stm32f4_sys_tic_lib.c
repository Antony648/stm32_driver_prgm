#include "my_stm32f4_sys_tic_lib.h"

void systic_delay(uint32_t sec)
{
	SYSTIC_TIMER->SYST_RVR=(16000000 -1);
	SYSTIC_TIMER->SYST_CSR=5;
	SYSTIC_TIMER->SYST_CVR=0;
	for(int i=0;i<sec;i++)
	{
		while(!(SYSTIC_TIMER->SYST_CSR & 0x10000))
		{}
	}
	SYSTIC_TIMER->SYST_CSR=0; //disable timer
}

void systic_delay_ms(uint32_t milli)
{
	SYSTIC_TIMER->SYST_RVR=(16000 -1);
	SYSTIC_TIMER->SYST_CSR=5;
	SYSTIC_TIMER->SYST_CVR=0;
	for(int i=0;i<milli;i++)
	{
		while(!(SYSTIC_TIMER->SYST_CSR & 0x10000))
		{}
	}
	SYSTIC_TIMER->SYST_CSR=0; //disable t
}