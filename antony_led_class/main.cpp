#include "led.h"
#include <time.h>
void delay(int sec)
{
	clock_t target_time=clock()+(1000*sec);
	while(clock()<target_time){}
}
int main()
{
	LED ledr(RED,CURR_HIGH,DIAM_NORMAL,OFF,VOLT_NORMAL);
	LED ledb(BLUE,CURR_NORMAL,DIAM_NORMAL,OFF,VOLT_NORMAL);
	LED ledy(YELLOW,CURR_NORMAL,DIAM_NORMAL,OFF,VOLT_NORMAL);
	LED ledg(GREEN,CURR_NORMAL,DIAM_NORMAL,OFF,VOLT_NORMAL);
	while(1)
	{
		ledr.LED_CHANGE_STATE(ON);
		delay(2);
		ledr.LED_CHANGE_STATE(OFF);
		
		ledg.LED_CHANGE_STATE(ON);
		delay(2);
		ledg.LED_CHANGE_STATE(OFF);
		
		ledb.LED_CHANGE_STATE(ON);
		delay(2);
		ledb.LED_CHANGE_STATE(OFF);
		
		ledy.LED_CHANGE_STATE(ON);
		delay(2);
		ledy.LED_CHANGE_STATE(OFF);
		
	}
	return 0;
}