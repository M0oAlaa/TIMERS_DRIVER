#ifndef _SWPWM_APP_INCLUDES_H_
#define _SWPWM_APP_INCLUDES_H_

#include "STD_TYPES.h"
#include "SREG.h"
#include "DIO_interface.h"
#include "TIMERS_interface.h"

#define TIMER0	0
#define TIMER2	2

#define PeriodTimePerCycle	20 //period time of sw pwm
#define requiredPWM	30
#define CompVal	125

uint8_t gu8_counter=0;//Declaration of global counter to count interrupts happening
uint8_t gu8_flag=0;//Declaration of global flag

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
	else if(local_u8Counter==12)//60% on
	{
		DIO_SETpinVal(DIO_PORTB,DIO_PIN5,DIO_LOW);
	}
	else if(local_u8Counter==18)//90% on
	{
		DIO_SETpinVal(DIO_PORTB,DIO_PIN6,DIO_LOW);
	}
	else if(local_u8Counter==PeriodTimePerCycle)
	{
		DIO_SETpinVal(DIO_PORTB,DIO_PIN4,DIO_HIGH);
		DIO_SETpinVal(DIO_PORTB,DIO_PIN5,DIO_HIGH);
		DIO_SETpinVal(DIO_PORTB,DIO_PIN6,DIO_HIGH);
		local_u8Counter=0;
	}
}

#endif
