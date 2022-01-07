#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMERS_register.h"
#include "TIMERS_private.h"
#include "TIMERS_config.h"
#include "TIMERS_interface.h"
#define INTR_ATTRS used,externally_visible

void(* TIMER0CALLBACK)(void);
void(* TIMER2CALLBACK)(void);

void TimerInit(uint8_t TIMER){
if( TIMER == 0)
{
#if MODE0 == NORMAL
	/*Normal Mode*/
	CLR_BIT(TIMERS_TCCR0,TCCR0_WGM00);
	CLR_BIT(TIMERS_TCCR0,TCCR0_WGM01);
#elif MODE0 == PWM_PHASE_CORRECT
	/*Phase correct*/
	SET_BIT(TIMERS_TCCR0,TCCR0_WGM00);
	CLR_BIT(TIMERS_TCCR0,TCCR0_WGM01);

#elif MODE0 == CTC
	/*CTC*/
	CLR_BIT(TIMERS_TCCR0,TCCR0_WGM00);
	SET_BIT(TIMERS_TCCR0,TCCR0_WGM01);
	TIMERS_OCR0=OUT_COMPARE_0_REJ;

#elif MODE0 == PWM_FAST
	/*Fast PWM*/
	SET_BIT(TIMERS_TCCR0,TCCR0_WGM00);
	SET_BIT(TIMERS_TCCR0,TCCR0_WGM01);
#endif

#if PRESCALAR0 == NO_PRESCALAR
	/*Select NO prescalar*/
	SET_BIT(TIMERS_TCCR0,TCCR0_CS00);
	CLR_BIT(TIMERS_TCCR0,TCCR0_CS01);
	CLR_BIT(TIMERS_TCCR0,TCCR0_CS02);
#elif PRESCALAR0 == DIV_8
	/*select prescaler (Divide by 8)*/
	CLR_BIT(TIMERS_TCCR0,TCCR0_CS00);
	SET_BIT(TIMERS_TCCR0,TCCR0_CS01);
	CLR_BIT(TIMERS_TCCR0,TCCR0_CS02);
#elif PRESCALAR0 == DIV_64
	/*select prescaler (Divide by 64)*/
	SET_BIT(TIMERS_TCCR0,TCCR0_CS00);
	SET_BIT(TIMERS_TCCR0,TCCR0_CS01);
	CLR_BIT(TIMERS_TCCR0,TCCR0_CS02);

#elif PRESCALAR0 == DIV_256
	/*select prescaler (Divide by 256)*/
	CLR_BIT(TIMERS_TCCR0,TCCR0_CS00);
	CLR_BIT(TIMERS_TCCR0,TCCR0_CS01);
	SET_BIT(TIMERS_TCCR0,TCCR0_CS02);

#elif PRESCALAR0 == DIV_1024
	/*select prescaler (Divide by 1024)*/
	SET_BIT(TIMERS_TCCR0,TCCR0_CS00);
	CLR_BIT(TIMERS_TCCR0,TCCR0_CS01);
	SET_BIT(TIMERS_TCCR0,TCCR0_CS02);
#endif
}

if( TIMER == 2)
{
#if MODE2 == NORMAL
	/*Normal Mode*/
	CLR_BIT(TIMERS_TCCR2,TCCR2_WGM20);
	CLR_BIT(TIMERS_TCCR2,TCCR2_WGM21);
#elif MODE2 == PWM_PHASE_CORRECT
	/*Phase Correct Mode*/
	SET_BIT(TIMERS_TCCR2,TCCR2_WGM20);
	CLR_BIT(TIMERS_TCCR2,TCCR2_WGM21);
#elif MODE2 == CTC
	/*CTC Mode*/
	CLR_BIT(TIMERS_TCCR2,TCCR2_WGM20);
	SET_BIT(TIMERS_TCCR2,TCCR2_WGM21);
	TIMERS_OCR2=OUT_COMPARE_2_REJ;
#elif MODE2 == PWM_FAST
	/*Fast PWM Mode*/
	SET_BIT(TIMERS_TCCR2,TCCR2_WGM20);
	SET_BIT(TIMERS_TCCR2,TCCR2_WGM21);
#endif

#if PRESCALAR2 == NO_PRESCALAR
	/*select No prescaler*/
	SET_BIT(TIMERS_TCCR2,TCCR2_CS20);
	CLR_BIT(TIMERS_TCCR2,TCCR2_CS21);
	CLR_BIT(TIMERS_TCCR2,TCCR2_CS22);
#elif PRESCALAR2 == DIV_8
	/*select prescaler (Divide by 8)*/
	CLR_BIT(TIMERS_TCCR2,TCCR2_CS20);
	SET_BIT(TIMERS_TCCR2,TCCR2_CS21);
	CLR_BIT(TIMERS_TCCR2,TCCR2_CS22);
#elif PRESCALAR2 == DIV_32
	/*select prescaler (Divide by 32)*/
	SET_BIT(TIMERS_TCCR2,TCCR2_CS20);
	SET_BIT(TIMERS_TCCR2,TCCR2_CS21);
	CLR_BIT(TIMERS_TCCR2,TCCR2_CS22);
#elif PRESCALAR2 == DIV_64
	/*select prescaler (Divide by 64)*/
	CLR_BIT(TIMERS_TCCR2,TCCR2_CS20);
	CLR_BIT(TIMERS_TCCR2,TCCR2_CS21);
	SET_BIT(TIMERS_TCCR2,TCCR2_CS22);
#elif PRESCALAR2 == DIV_128
	/*select prescaler (Divide by 128)*/
	SET_BIT(TIMERS_TCCR2,TCCR2_CS20);
	CLR_BIT(TIMERS_TCCR2,TCCR2_CS21);
	SET_BIT(TIMERS_TCCR2,TCCR2_CS22);
#elif PRESCALAR2 == DIV_256
	/*select prescaler (Divide by 256)*/
	CLR_BIT(TIMERS_TCCR2,TCCR2_CS20);
	SET_BIT(TIMERS_TCCR2,TCCR2_CS21);
	SET_BIT(TIMERS_TCCR2,TCCR2_CS22);
#elif PRESCALAR2 == DIV_1024
	/*select prescaler (Divide by 1024)*/
	SET_BIT(TIMERS_TCCR2,TCCR2_CS20);
	SET_BIT(TIMERS_TCCR2,TCCR2_CS21);
	SET_BIT(TIMERS_TCCR2,TCCR2_CS22);
#endif
}
}//End of TIMER init Function

/*Implementation of Start timer*/
void TIMER_START(uint8_t TIMER)
{
	/*If select timer0*/
	if(TIMER==0)
	{
		/*If select normal mode*/
		if(MODE0==NORMAL)
		{
			SET_BIT(TIMERS_TIMSK,TIMSK_TOIE0);
		}
		/*If select ctc mode*/
		else if(MODE0== CTC)
		{
			SET_BIT(TIMERS_TIMSK,TIMSK_OCIE0);
		}
	}
	/*If select timer2*/
	else if(TIMER==2)
	{
		/*If select normal mode*/
		if(MODE2==NORMAL)
		{
			SET_BIT(TIMERS_TIMSK,TIMSK_TOIE2);
		}
		/*If select ctc mode*/
		else if(MODE2== CTC)
		{
			SET_BIT(TIMERS_TIMSK,TIMSK_OCIE2);
		}
	}
}//End of Start function

void TIMER_STOP(uint8_t TIMER)
{
	/*If select timer0*/
	if(TIMER==0)
	{
		/*If select normal mode*/
		if(MODE0==NORMAL)
		{
			CLR_BIT(TIMERS_TIMSK,TIMSK_TOIE0);
		}
		/*If select ctc mode*/
		else if(MODE0== CTC)
		{
			CLR_BIT(TIMERS_TIMSK,TIMSK_OCIE0);
		}
	}
	/*If select timer2*/
	else if(TIMER==2)
	{
		/*If select normal mode*/
		if(MODE2==NORMAL)
		{
			CLR_BIT(TIMERS_TIMSK,TIMSK_TOIE2);
		}
		/*If select ctc mode*/
		else if(MODE2== CTC)
		{
			CLR_BIT(TIMERS_TIMSK,TIMSK_OCIE2);
		}
	}
}//End of Stop function

/*Implementation of timer callback function*/
void TIMER0_callback(void(* TIMER_ISR)(void))
{
	TIMER0CALLBACK=TIMER_ISR;
}//End of Callback function

/*Implementation of timer callback function*/
void TIMER2_callback(void(* TIMER_ISR)(void))
{
	TIMER2CALLBACK=TIMER_ISR;
}//End of Callback function

void __vector_11(void) __attribute__((signal,INTR_ATTRS));
void __vector_11(void)
{
	if(TIMER0CALLBACK!=NULL)
	{
		TIMER0CALLBACK();
	}
}//End of overflow interrupt function function of timer0


void __vector_10(void) __attribute__((signal,INTR_ATTRS));
void __vector_10(void)
{
	if(TIMER0CALLBACK!=NULL)
	{
		TIMER0CALLBACK();
	}
}//End of out compare interrupt function function of timer0

void __vector_5(void) __attribute__((signal,INTR_ATTRS));
void __vector_5(void)
{
	if(TIMER2CALLBACK!=NULL)
	{
		TIMER2CALLBACK();
	}
}//End of overflow interrupt function function of timer2


void __vector_4(void) __attribute__((signal,INTR_ATTRS));
void __vector_4(void)
{
	if(TIMER2CALLBACK!=NULL)
	{
		TIMER2CALLBACK();
	}
}//End of out compare interrupt function function of timer2
