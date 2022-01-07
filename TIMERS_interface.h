#ifndef _TIMERS_INTERFACE_H_
#define _TIMERS_INTERFACE_H_

/*Declaration of timer initialization*/
void TimerInit(void);

/*Declaration of start timer*/
void TIMER_START(void);

/*Declaration of stop timer*/
void TIMER_STOP(void);

/*Declaration of timer callback function*/
void TIMER_callback(void(* TIMER_ISR)(void));

#endif
