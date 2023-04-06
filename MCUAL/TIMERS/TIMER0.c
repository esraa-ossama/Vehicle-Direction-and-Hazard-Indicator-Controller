/******************************************************************************
 *
 * Module: TIMER0
 *
 * File Name: timer0.c
 *
 * Description: source file for the AVR timer0 driver
 *
 * Author: Hesham Shehata
 *
 *******************************************************************************/	
#include "TIMER0.h"
#include "../utilities/std_types.h"


// uint16_t prescaler ;

void TIMER0_init(const Timer0_ConfigType * config_Ptr)
{
	if((config_Ptr->TIMER0_mode) != TIMER0_FAST_PWM_MODE)
		SET_BIT(TCCR0,7);  /// active only for non-PWM 
	
	TCCR0  |= (((config_Ptr->TIMER0_mode) & 0x01) << 6) | (((config_Ptr->TIMER0_mode) & 0x02) << 3);/*set WGM00 WGM01  */
	TCCR0  |= (((config_Ptr->TIMER0_compare_output_mode) & 0x01) <<4 ) | (((config_Ptr->TIMER0_compare_output_mode) & 0x02) << 5);/*set COM21 COM20  */
	TCCR0 |= config_Ptr->TIMER0_clock; /*  choose clock         */
}
// 	if(config_Ptr->TIMER0_clock == TIMER0_F_CPU_CLOCK)
// 		prescaler = 1;
// 	else if (config_Ptr->TIMER0_clock == TIMER0_F_CPU_8)
// 		prescaler = 8;
// 	else if (config_Ptr->TIMER0_clock == TIMER0_F_CPU_64)
// 		prescaler = 64;
// 	else if (config_Ptr->TIMER0_clock == TIMER0_F_CPU_256)
// 		prescaler = 256;
// 	else if (config_Ptr->TIMER0_clock == TIMER0_F_CPU_1024)
// 		prescaler = 1024;
// 		
// 	
// 		
// }

// void TIMER0_delay(uint16_t num_count , uint8_t initial_value) //num_count = number of overflow wanted
// {
// 	uint16_t actaul_counted_overflow =0;
// 	while(actaul_counted_overflow < num_count)
// 	{
// 		TCNT0 = initial_value; //set TCNT0 with initail value
// 		while(! BIT_IS_SET(TIFR,0)); //check bit TOV0 is set that mean overflow occur
// 		SET_BIT(TIFR,0); //as not using interrupt should set this bit to clear flag
// 		actaul_counted_overflow++;
// 	}
// }

 /////Note for some round in calculation minimum delay can ably is 3 msec and function take 2000  and more increase delay accuracy increase
// void TIMER0_Delay_ms(uint32_t T_delay)
// {
// 	uint32_t T_tick = 1000000;
// 	T_tick = (prescaler * 1000000) / (F_CPU_MCU);
// 	uint32_t T_maxdelay = T_tick * 256;
// 	if(T_delay < T_maxdelay)
// 	{
// 		uint8_t T_initialvalue = ( (T_maxdelay - T_delay) / T_tick );
// 		TCNT0 = T_initialvalue; //set TCNT0 with initial value
// 		while(! BIT_IS_SET(TIFR,0)); //check bit TOV0 is set that mean overflow occur
// 		SET_BIT(TIFR,0); //as not using interrupt should set this bit to clear flag
// 	}
// 	else if(T_delay > T_maxdelay)
// 	{
// 		uint8_t NUM_overflow = (T_delay / T_maxdelay) + 1;
// 		uint8_t T_initialvalue =  ( 256 - ( ( T_delay / T_tick ) / NUM_overflow ) ) ;
// 		uint8_t actaul_counted_overflow = 0 ;
// 		while(actaul_counted_overflow < NUM_overflow)
// 		{
// 			TCNT0 = T_initialvalue; //set TCNT0 with initial value
// 			while(! BIT_IS_SET(TIFR,0)); //check bit TOV0 is set that mean overflow occur
// 			SET_BIT(TIFR,0); //as not using interrupt should set this bit to clear flag
// 			actaul_counted_overflow++;
// 		}
// 	}
// 	
// }
// 
//  void TIMER0_stop(void)
//  {
// 	 TCCR0 = 0x00; /* to make no clock source        */
//  }
//  
//  void TIMER0_intialTime(uint8_t initialTime)
//  {
// 	 TCNT0 = initialTime;
//  }
//  
//  void TIMER0_OVFInterruptEnable(void)
//  {
// 	 SET_BIT(TIMSK,0);
//  }
//  
 void PWM_Write(uint8_t value)
 {
	 OCR0 = value;
 }