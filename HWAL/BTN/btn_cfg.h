/*
 * btn_cfg.h
 *
 *  Created on: Feb 8, 2023
 *      Author: Esraa Ossama
 */


#ifndef BTN_CFG_H_
#define BTN_CFG_H_
#include "../utilities/std_types.h"



#define BTNS_NUM ((unsigned char)5)

typedef enum
{
	BUTTON_NORMAL,
	BUTTON_WITH_PULLUP
}BUTTON_pinResistorState;


typedef struct{
	uint8_t PORT_X;
	uint8_t PIN_NUM;
	BUTTON_pinResistorState BUTTON_STATE;
}btn_init_param;

extern btn_init_param button_init_parameters[BTNS_NUM], *hbtn_id, *rbtn_id, *lbtn_id, *ignition_btn_id, *null_btn_id;


#endif /* INCLUDES_INC_BTN_CFG_H_ */
