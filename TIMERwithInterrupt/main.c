#include "STD_TYPES.h"
#include "SREG.h"
#include "DIO_interface.h"
#include "TIMERS_interface.h"

#define TIMER0	0
#define TIMER2	2

/*Declaration of ISR0 & ISR2*/
void ISR0(void);
void ISR2(void);

uint8_t gu8_counter1=0,gu8_counter2=0;//Declaration of global counter to count interrupts happening
uint8_t gu8_flag1=0,gu8_flag2=0;//Declaration of global flag
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

/*Implementation of ISR function of timer0*/
void ISR0(void)
{
	/*check if the led on or off*/
	if(gu8_flag1==0)
	{
		gu8_counter1++;
		if(gu8_counter1==16)
		{
			DIO_SETpinVal(DIO_PORTB,DIO_PIN5,DIO_HIGH);//LED on
			gu8_counter1=0;
			gu8_flag1=1;
		}
	}
	else
	{
		gu8_counter1++;
		if(gu8_counter1==10)
		{
			DIO_SETpinVal(DIO_PORTB,DIO_PIN5,DIO_LOW);//LED off
			gu8_counter1=0;
			gu8_flag1=0;
		}
	}
}

/*Implementation of ISR function of timer2*/
void ISR2(void)
{
	/*check if the led on or off*/
	if(gu8_flag2==0)
	{
		gu8_counter2++;
		if(gu8_counter2==125)
		{
			DIO_SETpinVal(DIO_PORTB,DIO_PIN4,DIO_HIGH);//LED on
			gu8_counter2=0;
			gu8_flag2=1;
		}
	}
	else
	{
		gu8_counter2++;
		if(gu8_counter2==75)
		{
			DIO_SETpinVal(DIO_PORTB,DIO_PIN4,DIO_LOW);//LED off
			gu8_counter2=0;
			gu8_flag2=0;
		}
	}
}
