#include "TIMERwithINT_APP_includes.h"

int main(void)
{
	DIO_SETpinDir(DIO_PORTB,DIO_PIN4,DIO_OUTPUT);//Set the direction of pin to be output
	DIO_SETpinDir(DIO_PORTB,DIO_PIN5,DIO_OUTPUT);//Set the direction of pin to be output
	SREG_Enable();//Enable the global interrupt
	TimerInit(TIMER2);//calling timer initialization
	TIMER2_SETcompareMatchValue(125);
	TIMER_START(TIMER2);//Start timer
	TIMER2_callback(&ISR2);//call timer callback
	TimerInit(TIMER0);
	TIMER_START(TIMER0);
	TIMER0_callback(&ISR0);
	while(1)
	{

	}
}

