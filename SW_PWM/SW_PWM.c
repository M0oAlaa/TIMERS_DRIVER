#include "STD_TYPES.h"
#include "SREG.h"
#include "DIO_interface.h"
#include "TIMERS_interface.h"

#define PeriodTimePerCycle	20 //period time of sw pwm

/*Declaration of software PWM*/
void SW_PWM(void);

uint8_t gu8_counter=0;//Declaration of global counter to count interrupts happening
uint8_t gu8_flag=0;//Declaration of global flag
int main(void)
{
	DIO_SETpinDir(DIO_PORTB,DIO_PIN4,DIO_OUTPUT);//Set the direction of pin to be output
	DIO_SETpinDir(DIO_PORTB,DIO_PIN5,DIO_OUTPUT);
	DIO_SETpinDir(DIO_PORTB,DIO_PIN6,DIO_OUTPUT);
	DIO_SETpinDir(DIO_PORTB,DIO_PIN7,DIO_OUTPUT);
	DIO_SETpinVal(DIO_PORTB,DIO_PIN4,DIO_HIGH);//LED on
	DIO_SETpinVal(DIO_PORTB,DIO_PIN5,DIO_HIGH);
	DIO_SETpinVal(DIO_PORTB,DIO_PIN6,DIO_HIGH);
	DIO_SETpinVal(DIO_PORTB,DIO_PIN7,DIO_HIGH);
	SREG_Enable();//Enable the global interrupt
	TimerInit(0);//calling timer initialization
	TIMER0_SETcompareMatchValue(125);//set compare match value of timer0 by 125
	TIMER_START(0);//Start timer
	TIMER0_callback(&SW_PWM);//call timer callback
	while(1)
	{

	}
}

void SW_PWM(void)
{
	static uint8_t local_u8Counter;
	uint8_t ONtime;
	ONtime=(PeriodTimePerCycle*requiredPWM)/100;
	local_u8Counter++;
	if(local_u8Counter==ONtime)//30% on
	{
		DIO_SETpinVal(DIO_PORTB,DIO_PIN4,DIO_LOW);
	}
	else if(local_u8Counter==12)
	{
		DIO_SETpinVal(DIO_PORTB,DIO_PIN5,DIO_LOW);
	}
	else if(local_u8Counter==18)
	{
		DIO_SETpinVal(DIO_PORTB,DIO_PIN6,DIO_LOW);
	}
	else if(local_u8Counter==PeriodTimePerCycle)//70 %off
	{
		DIO_SETpinVal(DIO_PORTB,DIO_PIN4,DIO_HIGH);
		DIO_SETpinVal(DIO_PORTB,DIO_PIN5,DIO_HIGH);
		DIO_SETpinVal(DIO_PORTB,DIO_PIN6,DIO_HIGH);
		local_u8Counter=0;
	}
}
