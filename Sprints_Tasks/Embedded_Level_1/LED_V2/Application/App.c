/*
 * app.c
 *
 * Created: 06-Apr-23 3:02:19 AM
 *  Author: Amr
 */ 

/*****************************************************************************************************************************************************************
*																		Includes																				 *
******************************************************************************************************************************************************************/
#include "app.h"
/*****************************************************************************************************************************************************************
*																		Global variables																				 *
******************************************************************************************************************************************************************/
volatile uint8_t LED_Number =0;
/*****************************************************************************************************************************************************************
*																		Functions definitions 																	 *
******************************************************************************************************************************************************************/
static void press (void){
	if(LED_Number < 7){
		LED_Number++;
	}
	else{
		LED_Number = 0 ;
	}
}

void APP_init()
{
	LED_init(porta, pin0);
	LED_init(porta, pin1);
	LED_init(porta, pin2);
	LED_init(porta, pin3);

	button_init(portd, pin2);


sei();
EXI_Enable (EXT_INT_0);
EXI_Trigger(EXT_INT_0,RISING_EDGE);
EXI_SetCallBack(EXT_INT_0,press);




}
void APP_start()
{

	while (1)
	{
		switch (LED_Number){
			case 0 :
			LED_off(porta, pin0);
			LED_off(porta, pin1);
			LED_off(porta, pin2);
			LED_off(porta, pin3);

			break;
			
			case 1 :
			LED_on(porta, pin0);
			break;
			
			case 2 :
			LED_on(porta, pin1);
			break;
			
			case 3 :
			LED_on(porta, pin2);
			break;
			
			case 4 :
			LED_on(porta, pin3);
			break;
			
			case 5 :
			LED_off(porta, pin0);
			break;
			
			case 6 :
			LED_off(porta, pin1);
			break;
			
			case 7 :
			LED_off(porta, pin2);
			break;
			
			default:
			break;
		}
	}
}


