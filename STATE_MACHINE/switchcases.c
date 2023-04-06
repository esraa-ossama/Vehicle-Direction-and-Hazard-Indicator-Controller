#include "../HWAL/LED/LED.h"
#include "../HWAL/LED/LED_MANAGER.h"
#include "../POLLING/PollDataClient.h"
#include "../MCUAL/TIMERS/TIMER0.h"
#include "../MCUAL/TIMERS/TIMER2.h"


static uint8_t u8_static_CurrState;
static uint8_t u8_static_PrevState;
uint8_t u8_global_Counter = 0;
extern state_types state;
extern uint8_t Change_State;

void SYSTEM_BEHAVIOR (void)
{
	
	if (Change_State == 1){
		Change_State = 0;
	switch (state)
	{
		case R_BTN :
		
		Right_LED_BLINKING();
		break;
		
		case L_BTN :

		Left_LED_BLINKING();
		break;
		
		case H_BTN :
		
		Blink_Both();
		break;
		
		default:

		PWM2_Write(1);
		PWM_Write(1);
		break;
	}
	
}
}