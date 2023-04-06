/*
 *  Author: The Fantastic Five ??
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_


/*****************************************************************************
*					       Prototypes
*****************************************************************************/


/******************************************************************************
* \Syntax          : void app_init(void)
* \Description     : Init all divers needed .
*
* \Sync\Async      : Synchronous
* \Reentrancy\None : Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void app_init(void);

/******************************************************************************
* \Syntax          : void app_startSchedular(void)
* \Description     : Create task and put it in Ready state  .
*
* \Sync\Async      : Synchronous
* \Reentrancy\Non : Non Reentrant
* \Parameters (in) : None
* \Parameters (out): None
* \Return value:   : None
*******************************************************************************/
void app_startSchedular(void);


#endif /* APPLICATION_H_ */