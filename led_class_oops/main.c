#include "led.h"
Led l1;
int main()
{
	USART2_Init();
	Led_ctor(&(l1),RED,ON);
	Led_getstate(&(l1));
	while(1)
	{}
}