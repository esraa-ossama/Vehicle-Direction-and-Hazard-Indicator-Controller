/******************************************
* Module: LED
*
* File Name: LED.c
*
* Description: source file for AVR LED Driver
******************************************/


#include "LED.h"


/*********************************************************
*               Implement
*********************************************************/
void LED_init(uint8_t PORT_X , uint8_t PIN_NUM)
{
	DIO_setupPinDirection(PORT_X , PIN_NUM , OUTPUT_PIN); //set for this pin as output pin as put one for this pin in DDR
}

void LED_on(uint8_t PORT_X , uint8_t PIN_NUM)
{
	DIO_writePin(PORT_X,PIN_NUM,LOGIC_HIGH); // set pin for this port 
}

void LED_off(uint8_t PORT_X , uint8_t PIN_NUM)
{
	DIO_writePin(PORT_X,PIN_NUM,LOGIC_LOW); // clear pin for this port 
}

void LED_toggle(uint8_t PORT_X , uint8_t PIN_NUM)
{
	DIO_togglePin(PORT_X,PIN_NUM); //toggle pin value
}

