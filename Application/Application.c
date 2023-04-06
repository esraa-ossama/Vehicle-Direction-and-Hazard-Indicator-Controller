/*
 *  Author: The Fantastic Five ??
 */

/*****************************************************************************
*					       Includes
*****************************************************************************/
#include "../FreeRTOS/Source/include/FreeRTOS.h"
#include "../FreeRTOS/Source/include/task.h"
#include "../FreeRTOS/Source/include/timers.h"
#include "../MCUAL/EXT_INTERRUPT/EXT_INTTERUPT.h"
#include "../MCUAL/DIO/DIO.h"
#include "../STATE_MACHINE/switchcases.h"
#include "../POLLING/poller.h"
#include "../POLLING/device.h"
#include "../POLLING/PollDataClient.h"
#include "../HWAL/LED/LED.h"
#include "../HWAL/LED/LED_MANAGER.h"
#include "../utilities/std_types.h"
#include "../MCUAL/TIMERS/TIMER0.h"
#include "../MCUAL/TIMERS/TIMER2.h"
#include  "Application.h"

/*****************************************************************************
*					       Global Data
*****************************************************************************/

state_types state;
uint8_t Right_LED_Counter = 0;
uint8_t Left_LED_Counter = 0;
uint8_t ticks = pdMS_TO_TICKS( 50 );
/*****************************************************************************
*					       Local Data
*****************************************************************************/

/* declare tasks handler */
TaskHandle_t myCallerPollHandler = NULL;
TaskHandle_t FSM_Handler = NULL;
/* declare timer handle */
TimerHandle_t Right_BlinkTimer;
TimerHandle_t Left_BlinkTimer;

uint8_t LED_ticks = pdMS_TO_TICKS( 500 );
/*****************************************************************************
*					       Local Function  prototype
*****************************************************************************/

void Blink_Right_LED(TimerHandle_t xTimer);
void Blink_Left_LED(TimerHandle_t xTimer );
void call_Polling(void);
void call_FSM(void);

/******************************************************************************
* \Syntax          : void app_init(void)
* \Description     : Init all divers needed .
*
* \Sync\Async      : Synchronous
* \Reentrancy\None : Reentrant
*******************************************************************************/
void app_init(void)
{
	
	init_btns();
	Right_LED_init();
	Left_LED_init();
	
	
}

/******************************************************************************
* \Syntax          : void app_startSchedular(void)
* \Description     : Create task and put it in Ready state  .
*
* \Sync\Async      : Synchronous
* \Reentrancy\Non : Non Reentrant
*******************************************************************************/
void app_startSchedular(void)
{
	
		xTaskCreate(call_Polling,"Calling_poll",200,NULL,2,&myCallerPollHandler);
		xTaskCreate(call_FSM,"Calling_switchCases",200,NULL,1,&FSM_Handler);
		Right_BlinkTimer=xTimerCreate("Right_blink_timer",LED_ticks,pdTRUE, ( void * ) 0,Blink_Right_LED);
		Left_BlinkTimer=xTimerCreate("Left_blink_timer",LED_ticks,pdTRUE, ( void * ) 0,Blink_Left_LED);
// 		xTimerStart(Right_BlinkTimer, 0);
// 		xTimerStart(Left_BlinkTimer, 0);

		
		vTaskStartScheduler();
		
	
	
}




/*****************************************************************************
*					       Local Function  Implement
*****************************************************************************/

/******************************************************************************
* \Syntax          : void call_Polling(void)
* \Description     : funtion called periodic every 50 ms to update button read and update state  .
*
* \Sync\Async      : Synchronous
* \Reentrancy\Non  : Non Reentrant
*******************************************************************************/
void call_Polling(void){

	while(1){
		
		Poll();
		vTaskDelay(ticks);/*delay as this task should start every 50ms */
	}
}

/******************************************************************************
* \Syntax          : void call_FSM(void)
* \Description     : function  called to use state updated and do its effect .
*
* \Sync\Async      : Synchronous
* \Reentrancy\Non : Non Reentrant
*******************************************************************************/
void call_FSM(void){
	
	while(1){
		
		SYSTEM_BEHAVIOR();
		//vTaskDelay(1);

	}
}

/******************************************************************************
* \Syntax          : void Blink_Right_LED(TimerHandle_t xTimer)
* \Description     : used to toggle led every 500  ms  .
*
* \Sync\Async      : Synchronous
* \Reentrancy\Non  : Reentrant
*******************************************************************************/
void Blink_Right_LED(TimerHandle_t xTimer){

	if (Right_LED_Counter == 0){ /*check If this time zero enter function make led low*/
		PWM2_Write(1);
		Right_LED_Counter ++;
	}
	else {/*check If this time one enter function make led low*/
		PWM2_Write(200);
		Right_LED_Counter = 0;
	}
	
}

/******************************************************************************
* \Syntax          : void Blink_Left_LED(TimerHandle_t xTimer)
* \Description     : used to toggle led every 500  ms  .
*
* \Sync\Async      : Synchronous
* \Reentrancy\Non  : Reentrant
*******************************************************************************/
void Blink_Left_LED(TimerHandle_t xTimer ){

	if (Left_LED_Counter == 0){/*check If this time zero enter function make led low*/
		PWM_Write(1);
		Left_LED_Counter ++;
	}
	else {/*check If this time one enter function make led low*/
		PWM_Write(200);
		Left_LED_Counter = 0;
	}
}

