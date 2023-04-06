/*
 * CFile1.c
 *
 * Created: 2/11/2023 6:16:15 PM
 *  Author: sigma
 */ 

#include "LED_MANAGER.h"
#include "LED.h"
#include "../FreeRTOS/Source/include/FreeRTOS.h"
#include "../FreeRTOS/Source/include/task.h"
#include "../FreeRTOS/Source/include/timers.h"
#include "../../MCUAL/TIMERS/TIMER0.h"
#include "../../MCUAL/TIMERS/TIMER2.h"
#include "../POLLING/PollDataClient.h"
#include "../utilities/std_types.h"

extern TimerHandle_t Right_BlinkTimer;
extern TimerHandle_t Left_BlinkTimer;
extern state_types state;

void Right_LED_init(void)
{
	LED_init(Right_LED_Port, Right_LED_Pin);
	Timer2_ConfigType config2 = {TIMER2_FAST_PWM_MODE,TIMER2_F_CPU_CLOCK,TIMER2_CLEAR_ON_COMPARE};
	TIMER2_init(&config2);
	PWM2_Write(1);
	
}

void Left_LED_init(void)
{
	LED_init(Left_LED_Port, Left_LED_Pin);
	Timer0_ConfigType config0 = {TIMER0_FAST_PWM_MODE,TIMER0_F_CPU_CLOCK,TIMER0_CLEAR_ON_COMPARE};
	TIMER0_init(&config0);
	PWM_Write(1);

}

void Right_LED_BLINKING(void)
{
	
	xTimerReset(Right_BlinkTimer, 0);

}

void Left_LED_BLINKING(void)
{
	xTimerStart(Left_BlinkTimer, 0);

}

void Blink_Both(void)
{
		
	xTimerStart(Right_BlinkTimer, 0);
	xTimerStart(Left_BlinkTimer, 0);
	
}