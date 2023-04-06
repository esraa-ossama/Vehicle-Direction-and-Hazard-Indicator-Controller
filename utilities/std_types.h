/******************************************
* Module: common - standard types 
*
* File Name: std_types.h
*
* Description: typedefs for data types to meaningful easy
*
* Author: Hesham Shehata
*
******************************************/


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/* Boolean Values */
#ifndef FALSE
#define FALSE       (0u)
#endif
#ifndef TRUE
#define TRUE        (1u)
#endif

#define LOGIC_HIGH        (1u)
#define LOGIC_LOW         (0u)
/*********************************************************
*               Types Declaration
*********************************************************/

typedef unsigned char                    uint8_t;
typedef signed char                      sint8_t;
/*typedef unsigned short int               uint16_t;*/
typedef signed short int 				 sint16_t;
typedef unsigned long int 				 uint32_t;
typedef signed long int 				 sint32_t;
typedef unsigned long long  			 uint64_t;
typedef signed long long 				 sint64_t;

//null pointer 
#define NULL_POINTER  (void*)0)


#endif /* STD_TYPES_H_ */