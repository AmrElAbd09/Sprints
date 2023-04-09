/*
 * interrupt.h
 *
 * Created: 08-Apr-23 2:03:54 AM
 *  Author: Zerconium
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_
/*****************************************************************************************************************************************************************
*																		Includes																				 *
******************************************************************************************************************************************************************/
#include "../../Utilities/registers.h"
#include "../../Utilities/manu.h"
/*****************************************************************************************************************************************************************
*																		Macros																				 *
******************************************************************************************************************************************************************/
#define INT0_vect __vector_1
#define INT1_vect __vector_2
#define INT2_vect __vector_3


#define sei() __asm__ __volatile__("sei" ::: "memory")
#define cli() __asm__ __volatile__("cli" ::: "memory")

#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)

#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3
#define ISC2  6
#define INT0 6
#define INT1 7
#define INT2 5
/*****************************************************************************************************************************************************************
*																		Typedefs																				 *
******************************************************************************************************************************************************************/
typedef enum EN_int__error_t {
	ok,
	Error
	}EN_int__error_t;

typedef enum {
	LOW_LEVEL,
	ANY_LOGIC_CHANGE,
	FALLING_EDGE,
	RISING_EDGE
	}EN_trig;

typedef enum{
	EXT_INT_0,
	EXT_INT_1,
	EXT_INT_2,
	}EN_int_t;

EN_int__error_t EXI_Enable (EN_int_t Interrupt);
EN_int__error_t EXI_Disable (EN_int_t Interrupt);
EN_int__error_t EXI_Trigger(EN_int_t Interrupt,EN_trig trigger);
void EXI_SetCallBack(EN_int_t Interrupt,void(*ptrf)(void));

#endif /* INTERRUPT_H_ */
