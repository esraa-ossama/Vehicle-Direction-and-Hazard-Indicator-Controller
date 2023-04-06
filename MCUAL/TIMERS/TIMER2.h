/*
 * TIMER1.h
 *
 * Created: 2/9/2023 12:40:19 PM
 *  Author: nada
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_



#include "../utilities/std_types.h"
#include "../utilities/MCU_register.h"
#include "../utilities/common_macros.h"

#define  F_CPU_MCU  (8 * 1000000)

 /*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
// uint16_t prescaler ;

  typedef enum
 {
	 TIMER2_NORMAL_MODE,TIMER2_PHASE_CORRECT_MODE,TIMER2_CTC_MODE,TIMER2_FAST_PWM_MODE
 }TIMER2_mode;
 
 typedef enum
 {
	 TIMER2_NO_CLOCK,TIMER2_F_CPU_CLOCK,TIMER2_F_CPU_8,F_CPU_32,TIMER2_F_CPU_64,TIMER2_F_CPU_128,TIMER2_F_CPU_256,TIMER2_F_CPU_1024
 }TIMER2_clock;
 
 typedef enum {
	 TIMER2_NORMAL,TIMER2_RESERVED ,TIMER2_CLEAR_ON_COMPARE ,TIMER2_SET_ON_COMPARE
 }TIMER2_COMPARE_OUTPUT_MODE;
  typedef struct 
 {
	 TIMER2_mode TIMER2_mode;
	 TIMER2_clock TIMER2_clock;
	 TIMER2_COMPARE_OUTPUT_MODE TIMER2_compare_output_mode;
 }Timer2_ConfigType;

void TIMER2_init(const Timer2_ConfigType * config_Ptr);

 void PWM2_Write(uint8_t value);


#endif /* TIMER1_H_ */