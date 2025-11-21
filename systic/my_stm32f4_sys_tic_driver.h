#ifndef	__MY_STM32F4_SYS_TIC_H__
#define __MY_STM32F4_SYS_TIC_H__
#include <stdint.h>
#define _RW volatile
#define _RO	volatile
#define _WO	volatile
typedef struct
{
	_RW	uint32_t SYST_CSR; 
	_RW uint32_t SYST_RVR;
	_RW uint32_t SYST_CVR;
	_RO uint32_t SYST_CALIB;
	
}sys_tic_t;
#define SYSTIC_TIMER	((sys_tic_t*)(0xe000e010))
#endif