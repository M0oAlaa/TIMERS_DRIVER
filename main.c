#include "STD_TYPES.h"
#include "SREG.h"
#include "DIO_interface.h"
#include "TIMERS_interface.h"

/*Declaration of ISR*/
void ISR(void);
uint8_t gu8_counter=0;//Declaration of global counter to count interrupts happening
uint8_t gu8_flag=0;//Declaration of global flag
int main(void)
{
	DIO_SETpinDir(DIO_PORTB,DIO_PIN4,DIO_OUTPUT);//Set the direction of pin to be output
	SREG_Enable();//Enable the global interrupt
	TimerInit();//calling timer initialization
	TIMER_START();//Start timer
	TIMER_callback(&ISR);//call timer callback
	while(1)
	{

	}
}

/*Implementation of ISR function*/
void ISR(void)
{
	/*check if the led on or off*/
	if(gu8_flag==0)
	{
		gu8_counter++;
		if(gu8_counter==16)
		{
			DIO_SETpinVal(DIO_PORTB,DIO_PIN4,DIO_HIGH);//LED on
			gu8_counter=0;
			gu8_flag=1;
		}
	}
	else
	{
		gu8_counter++;
		if(gu8_counter==10)
		{
			DIO_SETpinVal(DIO_PORTB,DIO_PIN4,DIO_LOW);//LED off
			gu8_counter=0;
			gu8_flag=0;
		}
	}
}
