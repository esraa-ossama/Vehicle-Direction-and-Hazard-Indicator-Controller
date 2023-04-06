/*
 *  Author: The Fantastic Five ??
 */
#ifndef POLLDATACLIENT_H_
#define POLLDATACLIENT_H_


typedef enum
{
	R_BTN,
	L_BTN,
	H_BTN,
	NO_INDICATOR,
}state_types;

//extern state_types state ;
//function prototypes//

void handle_state(void);
//void test(void);

#endif
