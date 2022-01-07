#ifndef _TIMERS_INTERFACE_H_
#define _TIMERS_INTERFACE_H_

/*Declaration of timer initialization*/
void TimerInit(uint8_t TIMER);

/*Declaration of start timer*/
void TIMER_START(uint8_t TIMER);

/*Declaration of stop timer*/
void TIMER_STOP(uint8_t TIMER);

/*Declaration of timer0 callback function*/
void TIMER0_callback(void(* TIMER_ISR)(void));

/*Declaration of timer2 callback function*/
void TIMER2_callback(void(* TIMER_ISR)(void));

#endif
