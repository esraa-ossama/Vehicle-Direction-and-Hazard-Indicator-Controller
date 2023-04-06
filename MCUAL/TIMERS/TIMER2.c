/*
 * TIMER1.c
 *
 * Created: 2/9/2023 12:04:46 PM
 *  Author: nada
 */ 
#include "TIMER2.h"
void TIMER2_init(const Timer2_ConfigType * config_Ptr)
{
	if((config_Ptr->TIMER2_mode) != TIMER2_FAST_PWM_MODE)
	{ SET_BIT(TCCR0,7);  
		}/// active only for non-PWM
	
	TCCR2  |= (((config_Ptr->TIMER2_mode) & 0x01) << 6) | (((config_Ptr->TIMER2_mode) & 0x02) << 3);/*set WGM20 WGM21  */
	TCCR2  |= (((config_Ptr->TIMER2_compare_output_mode) & 0x01) <<4 ) | (((config_Ptr->TIMER2_compare_output_mode) & 0x02) << 5);/*set COM21 COM20  */

	TCCR2 |= config_Ptr->TIMER2_clock; /*  choose clock         */ 

	}


 void PWM2_Write(uint8_t value)
 {
	 OCR2 = value;
 }