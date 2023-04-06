/*
 *  Author: The Fantastic Five ??
 */ 

#ifndef DEVICE_H_
#define DEVICE_H_

/*****************************************************************************
*					       Function  prototype
*****************************************************************************/

/******************************************************************************
* \Syntax          : void init_btns(void)
* \Description     : Init buttons pin   .
*
* \Sync\Async      : Synchronous
* \Reentrancy\Non :  Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void init_btns(void);
/******************************************************************************
* \Syntax          : void update_btns(void)
* \Description     : function to update state for each button  .
*
* \Sync\Async      : Synchronous
* \Reentrancy\Non : Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void update_btns(void);

#endif
