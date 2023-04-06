/******************************************
* Module: LED
*
* File Name: LED.h
*
* Description: header file for AVR LED Driver
*
* Author: Hesham Shehata
*
******************************************/


#ifndef LED_H_
#define LED_H_

#include "../../MCUAL/DIO/DIO.h"



/*********************************************************
*               Prototypes
*********************************************************/

/*
* Description:
* set pin for specific port as output pin to be able to connect led
* if input port number and pin number are not correct ,function will not handle request
*/
void LED_init(uint8_t PORT_X , uint8_t PIN_NUM);

/*
* Description:
* set pin high to turn led on if connected as active high or turn led off if connected as active low 
* if input port number and pin number are not correct ,function will not handle request
* if this pin not make for it "LED_init function and not output pin " ,function will not handle request
*/
void LED_on(uint8_t PORT_X , uint8_t PIN_NUM);

/*
* Description:
* Clear pin high to turn led off if connected as active high or turn led on if connected as active low
* if input port number and pin number are not correct ,function will not handle request
* if this pin not make for it "LED_init function and not output pin " ,function will not handle request
*/
void LED_off(uint8_t PORT_X , uint8_t PIN_NUM);

/*
* Description:
* Toggle pin
* if input port number and pin number are not correct ,function will not handle request
* if this pin not make for it "LED_init function and not output pin " ,function will not handle request
*/
void LED_toggle(uint8_t PORT_X , uint8_t PIN_NUM);




#endif /* LED_H_ */