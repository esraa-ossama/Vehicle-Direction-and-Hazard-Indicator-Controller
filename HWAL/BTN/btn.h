/*
 * btn.h
 *
 *  Created on: Feb 8, 2023
 *      Author: Esraa Ossama
 */

#ifndef BTN_H_
#define BTN_H_

#include "../../MCUAL/DIO/DIO.h"
#include "btn_cfg.h"


/*********************************************************
*               Prototypes
*********************************************************/
/*
* Description:
* setup direction of specific pin in port as input pin to connect with button
* as if BUTTON_STATE is "BUTTON_NORMAL": set pin as input pin only and in addition to activate internal pull up resistor at "BUTTON_WITH_PULLUP"
* if input port number and pin number are not correct ,function will not handle request
*/
void BUTTON_init(btn_init_param *btn_id);

/*
* Description:
* read value of specific pin in port
* if input port number and pin number are not correct ,function will not handle request
*/
uint8_t BUTTON_read(btn_init_param *btn_id);


#endif
