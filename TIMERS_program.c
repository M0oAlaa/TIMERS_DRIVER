#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMERS_register.h"
#include "TIMERS_private.h"
#include "TIMERS_config.h"
#include "TIMERS_interface.h"
#define INTR_ATTRS used,externally_visible

void(* TIMERCALLBACK)(void);

void TimerInit(void){
#if TIMER == TIMER0
#if MODE == NORMAL
	/*Normal Mode*/
	CLR_BIT(TIMERS_TCCR0,TCCR0_WGM00);
	CLR_BIT(TIMERS_TCCR0,TCCR0_WGM01);
#elif MODE == PWM_PHASE_CORRECT
	/*Phase correct*/
	SET_BIT(TIMERS_TCCR0,TCCR0_WGM00);
	CLR_BIT(TIMERS_TCCR0,TCCR0_WGM01);

#elif MODE == CTC
	/*CTC*/
	CLR_BIT(TIMERS_TCCR0,TCCR0_WGM00);
	SET_BIT(TIMERS_TCCR0,TCCR0_WGM01);
	TIMERS_OCR0=OUT_COMPARE_REJ;

#elif MODE == PWM_FAST
	/*Fast PWM*/
	SET_BIT(TIMERS_TCCR0,TCCR0_WGM00);
	SET_BIT(TIMERS_TCCR0,TCCR0_WGM01);
#endif

#if PRESCALAR == NO_PRESCALAR
	/*Select NO prescalar*/
	SET_BIT(TIMERS_TCCR0,TCCR0_CS00);
	CLR_BIT(TIMERS_TCCR0,TCCR0_CS01);
	CLR_BIT(TIMERS_TCCR0,TCCR0_CS02);
#elif PRESCALAR == DIV_8
	/*select prescaler (Divide by 8)*/
	CLR_BIT(TIMERS_TCCR0,TCCR0_CS00);
	SET_BIT(TIMERS_TCCR0,TCCR0_CS01);
	CLR_BIT(TIMERS_TCCR0,TCCR0_CS02);
#elif PRESCALAR == DIV_64
	/*select prescaler (Divide by 64)*/
	SET_BIT(TIMERS_TCCR0,TCCR0_CS00);
	SET_BIT(TIMERS_TCCR0,TCCR0_CS01);
	CLR_BIT(TIMERS_TCCR0,TCCR0_CS02);

#elif PRESCALAR == DIV_256
	/*select prescaler (Divide by 256)*/
	CLR_BIT(TIMERS_TCCR0,TCCR0_CS00);
	CLR_BIT(TIMERS_TCCR0,TCCR0_CS01);
	SET_BIT(TIMERS_TCCR0,TCCR0_CS02);

#elif PRESCALAR == DIV_1024
	/*select prescaler (Divide by 1024)*/
	SET_BIT(TIMERS_TCCR0,TCCR0_CS00);
	CLR_BIT(TIMERS_TCCR0,TCCR0_CS01);
	SET_BIT(TIMERS_TCCR0,TCCR0_CS02);
#endif
#endif

#if TIMER == TIMER2
#if MODE == NORMAL
	/*Normal Mode*/
	CLR_BIT(TIMERS_TCCR2,TCCR2_WGM20);
	CLR_BIT(TIMERS_TCCR2,TCCR2_WGM21);
#elif MODE == PWM_PHASE_CORRECT
	/*Phase Correct Mode*/
	SET_BIT(TIMERS_TCCR2,TCCR2_WGM20);
	CLR_BIT(TIMERS_TCCR2,TCCR2_WGM21);
#elif MODE == CTC
	/*CTC Mode*/
	CLR_BIT(TIMERS_TCCR2,TCCR2_WGM20);
	SET_BIT(TIMERS_TCCR2,TCCR2_WGM21);
	TIMERS_OCR2=OUT_COMPARE_REJ;
#elif MODE == PWM_FAST
	/*Fast PWM Mode*/
	SET_BIT(TIMERS_TCCR2,TCCR2_WGM20);
	SET_BIT(TIMERS_TCCR2,TCCR2_WGM21);
#endif

#if PRESCALAR == NO_PRESCALAR
	/*select No prescaler*/
	SET_BIT(TIMERS_TCCR2,TCCR2_CS20);
	CLR_BIT(TIMERS_TCCR2,TCCR2_CS21);
	CLR_BIT(TIMERS_TCCR2,TCCR2_CS22);
#elif PRESCALAR == DIV_8
	/*select prescaler (Divide by 8)*/
	CLR_BIT(TIMERS_TCCR2,TCCR2_CS20);
	SET_BIT(TIMERS_TCCR2,TCCR2_CS21);
	CLR_BIT(TIMERS_TCCR2,TCCR2_CS22);
#elif PRESCALAR == DIV_32
	/*select prescaler (Divide by 32)*/
	SET_BIT(TIMERS_TCCR2,TCCR2_CS20);
	SET_BIT(TIMERS_TCCR2,TCCR2_CS21);
	CLR_BIT(TIMERS_TCCR2,TCCR2_CS22);
#elif PRESCALAR == DIV_64
	/*select prescaler (Divide by 64)*/
	CLR_BIT(TIMERS_TCCR2,TCCR2_CS20);
	CLR_BIT(TIMERS_TCCR2,TCCR2_CS21);
	SET_BIT(TIMERS_TCCR2,TCCR2_CS22);
#elif PRESCALAR == DIV_128
	/*select prescaler (Divide by 128)*/
	SET_BIT(TIMERS_TCCR2,TCCR2_CS20);
	CLR_BIT(TIMERS_TCCR2,TCCR2_CS21);
	SET_BIT(TIMERS_TCCR2,TCCR2_CS22);
#elif PRESCALAR == DIV_256
	/*select prescaler (Divide by 256)*/
	CLR_BIT(TIMERS_TCCR2,TCCR2_CS20);
	SET_BIT(TIMERS_TCCR2,TCCR2_CS21);
	SET_BIT(TIMERS_TCCR2,TCCR2_CS22);
#elif PRESCALAR == DIV_1024
	/*select prescaler (Divide by 1024)*/
	SET_BIT(TIMERS_TCCR2,TCCR2_CS20);
	SET_BIT(TIMERS_TCCR2,TCCR2_CS21);
	SET_BIT(TIMERS_TCCR2,TCCR2_CS22);
#endif
#endif
}//End of TIMER init Function

/*Implementation of Start timer*/
void TIMER_START(void)
{
	/*If select timer0*/
	if(TIMER==TIMER0)
	{
		/*If select normal mode*/
		if(MODE==NORMAL)
		{
			SET_BIT(TIMERS_TIMSK,TIMSK_TOIE0);
		}
		/*If select ctc mode*/
		else if(MODE== CTC)
		{
			SET_BIT(TIMERS_TIMSK,TIMSK_OCIE0);
		}
	}
	/*If select timer2*/
	else if(TIMER==TIMER2)
	{
		/*If select normal mode*/
		if(MODE==NORMAL)
		{
			SET_BIT(TIMERS_TIMSK,TIMSK_TOIE2);
		}
		/*If select ctc mode*/
		else if(MODE== CTC)
		{
			SET_BIT(TIMERS_TIMSK,TIMSK_OCIE2);
		}
	}
}//End of Start function

void TIMER_STOP(void)
{
	/*If select timer0*/
	if(TIMER==TIMER0)
	{
		/*If select normal mode*/
		if(MODE==NORMAL)
		{
			CLR_BIT(TIMERS_TIMSK,TIMSK_TOIE0);
		}
		/*If select ctc mode*/
		else if(MODE== CTC)
		{
			CLR_BIT(TIMERS_TIMSK,TIMSK_OCIE0);
		}
	}
	/*If select timer2*/
	else if(TIMER==TIMER2)
	{
		/*If select normal mode*/
		if(MODE==NORMAL)
		{
			CLR_BIT(TIMERS_TIMSK,TIMSK_TOIE2);
		}
		/*If select ctc mode*/
		else if(MODE== CTC)
		{
			CLR_BIT(TIMERS_TIMSK,TIMSK_OCIE2);
		}
	}
}//End of Stop function

/*Implementation of timer callback function*/
void TIMER_callback(void(* TIMER_ISR)(void))
{
	TIMERCALLBACK=TIMER_ISR;
}//End of Callback function

void __vector_11(void) __attribute__((signal,INTR_ATTRS));
void __vector_11(void)
{
	if(TIMERCALLBACK!=NULL)
	{
		TIMERCALLBACK();
	}
}//End of overflow interrupt function function of timer0


void __vector_10(void) __attribute__((signal,INTR_ATTRS));
void __vector_10(void)
{
	if(TIMERCALLBACK!=NULL)
	{
		TIMERCALLBACK();
	}
}//End of out compare interrupt function function of timer0

void __vector_5(void) __attribute__((signal,INTR_ATTRS));
void __vector_5(void)
{
	if(TIMERCALLBACK!=NULL)
	{
		TIMERCALLBACK();
	}
}//End of overflow interrupt function function of timer2


void __vector_4(void) __attribute__((signal,INTR_ATTRS));
void __vector_4(void)
{
	if(TIMERCALLBACK!=NULL)
	{
		TIMERCALLBACK();
	}
}//End of out compare interrupt function function of timer2
