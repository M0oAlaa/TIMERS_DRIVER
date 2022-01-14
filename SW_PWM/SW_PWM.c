#include "SWPWM_APP_includes.h"


int main(void)
{
	DIO_SETpinDir(DIO_PORTB,DIO_PIN4,DIO_OUTPUT);//Set the direction of the led to be output
	DIO_SETpinDir(DIO_PORTB,DIO_PIN5,DIO_OUTPUT);//Set the direction of the led to be output
	DIO_SETpinDir(DIO_PORTB,DIO_PIN6,DIO_OUTPUT);//Set the direction of the led to be output
	DIO_SETpinDir(DIO_PORTB,DIO_PIN7,DIO_OUTPUT);//Set the direction of the led to be output
	DIO_SETpinVal(DIO_PORTB,DIO_PIN4,DIO_HIGH);//Set the Value of the led to be HIGH
	DIO_SETpinVal(DIO_PORTB,DIO_PIN5,DIO_HIGH);//Set the Value of the led to be HIGH
	DIO_SETpinVal(DIO_PORTB,DIO_PIN6,DIO_HIGH);//Set the Value of the led to be HIGH
	DIO_SETpinVal(DIO_PORTB,DIO_PIN7,DIO_HIGH);//Set the Value of the led to be HIGH
	SREG_Enable();//Enable the global interrupt
	TimerInit(TIMER0);//calling timer initialization
	TIMER0_SETcompareMatchValue(CompVal);//set compare match value of timer0 by 125
	TIMER_START(TIMER0);//Start timer
	TIMER0_callback(&SW_PWM);//call timer callback
	while(1)
	{

	}
}

