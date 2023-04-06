/*
 * btn.c
 *
 *  Created on: Feb 8, 2023
 *      Author: Esraa Ossama
 */


#include "btn.h"
#include "btn_cfg.h"
#include "../../MCUAL/DIO/DIO.h"
#include "btn_cfg.h"

void BUTTON_init(btn_init_param *btn_id)
{
	if(btn_id -> BUTTON_STATE == BUTTON_NORMAL)
		DIO_setupPinDirection(btn_id -> PORT_X, btn_id -> PIN_NUM,INPUT_PIN);
	else if(btn_id -> BUTTON_STATE == BUTTON_WITH_PULLUP)
		DIO_setupPinDirection(btn_id -> PORT_X,btn_id -> PIN_NUM,INPUT_PIN_PULLUP);
}

uint8_t BUTTON_read(btn_init_param *btn_id)
{
	return DIO_readPin(btn_id -> PORT_X, btn_id -> PIN_NUM);
}
