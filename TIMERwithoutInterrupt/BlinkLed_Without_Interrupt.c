#include "TIMERwithoutINT_APP_includes.h"

void main(void)
{
	uint8_t u8_TimerReading=0;//Declare a local variable to hold the overflow flag state
	uint8_t u8_counter=0,u8_flag=0;//Some local variables to control led
	DIO_SETpinDir(DIO_PORTB,DIO_PIN4,DIO_OUTPUT);//Set the led direction as output
	TimerInit(TIMER0);//Initialization of timer 0
	while(1)
	{
		/*Get overflow flag reading*/
		u8_TimerReading=TIMER_checkOverFlow(TIMER0);
		/*Pooling until the overflow flag = 1*/
		while(u8_TimerReading != 1)
		{
			u8_TimerReading=TIMER_checkOverFlow(TIMER0);
		}
		/*If flag = 1*/
		if(u8_TimerReading==1)
		{
			/*Led on for 300 ms*/
			if(u8_flag==0)
				{
					u8_counter++;
					if(u8_counter==16)
					{
						DIO_SETpinVal(DIO_PORTB,DIO_PIN4,DIO_HIGH);//LED on
						u8_counter=0;
						u8_flag=1;
					}
				}
			/*Led off for 500 ms*/
				else
				{
					u8_counter++;
					if(u8_counter==10)
					{
						DIO_SETpinVal(DIO_PORTB,DIO_PIN4,DIO_LOW);//LED off
						u8_counter=0;
						u8_flag=0;
					}
				}
			TIMER_CLRoverflowFlag(0);
		}
		else
		{

		}
	}
}
