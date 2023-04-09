/*
 * app.c
 *
 * Created: 06-Apr-23 3:02:19 AM
 *  Author: Zerconium
 */ 

/*****************************************************************************************************************************************************************
*																		Includes																				 *
******************************************************************************************************************************************************************/
#include "app.h"
#include "util/delay.h"
/*****************************************************************************************************************************************************************
*																		Functions definitions 																	 *
******************************************************************************************************************************************************************/
void APP_init()
{
	LED_init(porta, pin0);
	LED_init(porta, pin1);
	LED_init(porta, pin2);
	LED_init(porta, pin3);
	button_init(portc, pin0);

}
void APP_start()
{
	EN_state buttonSTATE;
	uint8_t counter=0;
	while(1){
		button_read(portc,pin0,&buttonSTATE);
		if(buttonSTATE == HIGH)
		{
			
			if(counter ==0){
				LED_on(porta,pin0);
				_delay_ms(300);
				counter++;
			}
			else if(counter ==1){
				LED_on(porta,pin1);
				_delay_ms(300);
				counter++;
			}
			else if(counter ==2){
				LED_on(porta,pin2);
				_delay_ms(300);
				counter++;
			}
			else if(counter ==3){
				LED_on(porta,pin3);
				_delay_ms(300);
				counter++;
			}
			else if(counter ==4){
				LED_off(porta,pin0);
				_delay_ms(300);
				counter++;
			}
			else if(counter ==5){
				LED_off(porta,pin1);
				_delay_ms(300);
				counter++;
			}
			else if(counter ==6){
				LED_off(porta,pin2);
				_delay_ms(300);
				counter++;
			}
			else if(counter ==7){
				LED_off(porta,pin3);
				_delay_ms(300);
				counter =0;
			}
		}
		
	
		
	}
}


