/*
 * interrupt.c
 *
 * Created: 08-Apr-23 6:39:10 AM
 *  Author: Amr
 */ 

#include "interrupt.h"


static void (*ptrf_INT_0)(void)=NULL;
static void (*ptrf_INT_1)(void)=NULL;
static void (*ptrf_INT_2)(void)=NULL;



EN_int__error_t EXI_Enable (EN_int_t Interrupt)
{
	switch (Interrupt)
	{
		case EXT_INT_0:
		SET_BIT(GICR,INT0);
		break;
		case EXT_INT_1:
		SET_BIT(GICR,INT1);
		break;
		case EXT_INT_2:
		SET_BIT(GICR,INT2);
		break;
	}
}
EN_int__error_t EXI_Disable (EN_int_t Interrupt)
{
	switch (Interrupt)
	{
		case EXT_INT_0:
		RESET_BIT(GICR,INT0);
		break;
		case EXT_INT_1:
		RESET_BIT(GICR,INT1);
		break;
		case EXT_INT_2:
		RESET_BIT(GICR,INT2);
		break;
	}
}
EN_int__error_t EXI_Trigger(EN_int_t Interrupt,EN_trig trigger)
{
	
	switch(Interrupt)
	{
		case EXT_INT_0:
		switch(trigger)
		{
			case LOW_LEVEL:
			RESET_BIT(MCUCR,ISC00);
			RESET_BIT(MCUCR,ISC01);
			break;
			case ANY_LOGIC_CHANGE:
			SET_BIT(MCUCR,ISC00);
			RESET_BIT(MCUCR,ISC01);
			break;
			case FALLING_EDGE:
			RESET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
			case RISING_EDGE:
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
		}
		break;
		case EXT_INT_1:
		switch(trigger)
		{
			case LOW_LEVEL:
			RESET_BIT(MCUCR,ISC10);
			RESET_BIT(MCUCR,ISC11); break;
			case ANY_LOGIC_CHANGE:
			SET_BIT(MCUCR,ISC10);
			RESET_BIT(MCUCR,ISC11); break;
			case FALLING_EDGE:
			RESET_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11); break;
			case RISING_EDGE:
			SET_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11); break;
		}
		break;
		case EXT_INT_2:
		switch(trigger)
		{
			case FALLING_EDGE:
			RESET_BIT(MCUCSR,ISC2);
			break;
			case RISING_EDGE:
			SET_BIT(MCUCSR,ISC2);
			break;
		}
		break;
	}
}



void EXI_SetCallBack(EN_int_t Interrupt,void(*ptrf)(void))
{
	switch (Interrupt)
	{
		case EXT_INT_0:
		ptrf_INT_0 =ptrf;
		break;
		case EXT_INT_1:
		ptrf_INT_1 =ptrf;
		break;
		case EXT_INT_2:
		ptrf_INT_2 =ptrf;
		break;
	}
}


ISR (INT0_vect)
{
	if (ptrf_INT_0 != NULL)
	{
		ptrf_INT_0();
	}
}

ISR (INT1_vect)
{
	if (ptrf_INT_0 != NULL)
	{
		ptrf_INT_1();
	}
}

ISR (INT2_vect)
{
	if (ptrf_INT_0 != NULL)
	{
		ptrf_INT_2();
	}
}
