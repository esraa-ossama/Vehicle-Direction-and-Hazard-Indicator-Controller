/*
 * btn_cfg.c
 *
 *  Created on: Feb 8, 2023
 *      Author: Esraa Ossama
 */

#include "btn_cfg.h"
#include "../../MCUAL/DIO/DIO.h"
#include "../utilities/std_types.h"

#define BTNS_NUM ((unsigned char)5)

btn_init_param button_init_parameters[BTNS_NUM] = {
	{
		PORTA_ID,
		PIN0_ID,
		BUTTON_NORMAL
	},
	{
		PORTA_ID,
		PIN1_ID,
		BUTTON_WITH_PULLUP
	},
	{
		PORTA_ID,
		PIN2_ID,
		BUTTON_WITH_PULLUP
	},
	{
		PORTA_ID,
		PIN3_ID,
		BUTTON_WITH_PULLUP
	},
	{
		PORTA_ID,
		PIN4_ID,
		BUTTON_WITH_PULLUP
	}
};

btn_init_param *hbtn_id = &button_init_parameters[0];
btn_init_param *rbtn_id = &button_init_parameters[1];
btn_init_param *lbtn_id = &button_init_parameters[2];
btn_init_param *ignition_btn_id = &button_init_parameters[3];
btn_init_param *null_btn_id = &button_init_parameters[4];
