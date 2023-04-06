/*
 * LED_MANAGER.h
 *
 * Created: 2/11/2023 6:17:10 PM
 *  Author: sigma
 */ 


#ifndef LED_MANAGER_H_
#define LED_MANAGER_H_

#include "../utilities/std_types.h"
#include "../../MCUAL/DIO/DIO.h"

#define Left_LED_Port PORTB_ID
#define Right_LED_Port PORTD_ID
#define Left_LED_Pin PIN3_ID
#define Right_LED_Pin PIN7_ID




void Right_LED_init(void);
void Left_LED_init(void);
void Right_LED_BLINKING(void);
void Left_LED_BLINKING(void);
void Blink_Both(void);






#endif /* LED_MANAGER_H_ */