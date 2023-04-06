 /******************************************************************************
 *
 * Module: TIMER0
 *
 * File Name: timer0.h
 *
 * Description: Header file for the AVR timer0 driver
 *
 * Author: Hesham Shehata
 *
 *******************************************************************************/


#ifndef TIMER_H_
#define TIMER_H_

#include "../utilities/std_types.h"
#include "../utilities/MCU_register.h"
#include "../utilities/common_macros.h"


#define  F_CPU_MCU  (8 * 1000000)

 /*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
  typedef enum 
 {
	 TIMER0_NORMAL_MODE,TIMER0_PHASE_CORRECT_MODE,TIMER0_CTC_MODE,TIMER0_FAST_PWM_MODE
 }TIMER0_mode;
 
 typedef enum
 {
	 TIMER0_NO_CLOCK,TIMER0_F_CPU_CLOCK,TIMER0_F_CPU_8,TIMER0_F_CPU_64,TIMER0_F_CPU_256,TIMER0_F_CPU_1024
 }TIMER0_clock;
 
  typedef enum {
	  TIMER0_NORMAL,TIMER0_RESERVED ,TIMER0_CLEAR_ON_COMPARE ,TIMER0_SET_ON_COMPARE
  }TIMER0_COMPARE_OUTPUT_MODE;
  typedef struct
 {
	 TIMER0_mode TIMER0_mode;
	 TIMER0_clock TIMER0_clock;
	 TIMER0_COMPARE_OUTPUT_MODE TIMER0_compare_output_mode;
	 
 }Timer0_ConfigType;


	
	
 /*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
 
  /*
 * Description : 
 * 	1. Set the required mode.
 * 	2. Set the required prescaller.
 */
 void TIMER0_init(const Timer0_ConfigType * config_Ptr);
 
/*
* Description : 
* 	make delay 
* as it take number of count and initial value and this value provided in this case
* if T_delay < T_max_delay then number of count =1 and Timer_initail_value = (T_max_delay - T_delay)/T_tick
* if T_delay = T_max_delay then number of count =1 and Timer_initail_value = 0
* T_delay > T_max_delay then number of count(num_overflow) =(ceil) (T_delay / T_max_delay) and Timer_initail_value = 256 - ( (T_delay / T_tick) / number of count)
*/
//  void TIMER0_delay(uint16_t num_count , uint8_t initial_value);
//  
//  /*
//  * Note
//  * 100     ->this is 100 Us delay  num < 10^3 delay in Msec ( micro second)  -->micro not work(not supported)
//  * 1000    ->this is 1 ms delay  num * 10^3  delay im msec (milli second) 
//  * 1000000 ->this is 1 sec delay   num * 10^6  delay in sec
//  */
//  /////Note for some round in calculation minimum delay can ably is 3 msec and function take 2000  and more increase delay accuracy increase
//  void TIMER0_Delay_ms(uint32_t T_delay);
//  
// /*
// * Description : 
// * stop timer0 as make no clock source for Timer 0 peripheral
// */
//  void TIMER0_stop(void);
//  
//  void TIMER0_intialTime(uint8_t initialTime);
//  
//  void TIMER0_OVFInterruptEnable(void);
//  
 
 void PWM_Write(uint8_t value);

 
#endif /* TIMER_H_ */