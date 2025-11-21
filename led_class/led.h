#ifndef LED_H
#define LED_H
#include "uart.h"


#define LED_PORT  GPIOB
#define LED_PORT_CLOCK (1U<<1)

#define LED_RED_PIN (1U<<14) 
//this will take a single 1 and add 14 0s behind making bit 14 1
#define LED_GREEN_PIN (1U<<12)
#define LED_BLUE_PIN (1U<<15)
#define LED_YELLOW_PIN (1U<<13)

#define LED_RED_MODE_BIT (1U<<28)
#define LED_GREEN_MODE_BIT (1U<<24)
#define LED_YELLOW_MODE_BIT (1U<<26)
#define LED_BLUE_MOD_BIT (1U<<30)



#include <stdint.h>
typedef enum{
	RED=0,
	YELLOW,
	BLUE,
	GREEN,
	
}LedColor_Type;

typedef enum{
	OFF=0,
	ON
}LedState_Type;
 
typedef struct{
	struct LedVtable const *virt; /*virtual pointer*/
	LedColor_Type color;
	LedState_Type state;
	//uint32_t last_update;
}Led;

/*Led virtual table*/
struct LedVtable
{
	void(*run_diagnostics)(Led const* const me);
	uint32_t (*compute_effeciency)(Led const* const me);
};

void Led_ctor(Led * const led_obj,LedColor_Type _color,LedState_Type _state);
void Led_setstate(Led *const led_obj,LedState_Type _state_over) ;
LedState_Type Led_getstate(Led *const len_obj);

//Method1
static inline void Led_runDiagnostics_vcall(Led const * const me)
{
	(*me->virt->run_diagnostics)(me);
}
static inline uint32_t Led_CalculateEffeciency(Led const* const me)
{
	return (*me->virt->compute_effeciency)(me);
}
//Method2
#define RUN_DAIG(me) ((*me->virt->run_diagnostics)(me))
#define CAL_EFFE(me) ((*me->virt->compute_effeciency)(me))
#endif