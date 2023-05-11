/*
 * uart.h
 *
 * Created: 11/5/2023 10:34:00 AM
 *  Author: AMR
 */ 

#include "UART.h"

void USART_init(void)
{
	uint16_t baud;
//Speed config	
#if (speed_mode_selector == normal_speed)

				RESET_BIT(UCSRA, U2X);
				baud = ((cpu_freq_selector / (16*baud_rate_selector)) - 1);
				#elif speed_mode_selector == double_speed
				
				SET_BIT(UCSRA, U2X);
				baud = (cpu_freq_selector / (8*baud_rate_selector)) - 1;
#endif

UBRRL = (uint8_t)baud;
UBRRH = (uint8_t)(baud >> 8);

//Enable UART  receiver
SET_BIT(UCSRB,RXEN);
//Enable UART  transmitter 
SET_BIT(UCSRB,TXEN);
//Enable writing to UCSRC
SET_BIT(UCSRC,URSEL);
  
//PARITY config
#if parity_mode_selector == NO_PARITY
			
				RESET_BIT(UCSRC,UPM0);
				RESET_BIT(UCSRC,UPM1);
			

			#elif parity_mode_selector == EVEN_PARITY
			
				RESET_BIT(UCSRC,UPM0);
				SET_BIT(UCSRC,UPM1);
			

			#elif parity_mode_selector == ODD_PARITY
			
				SET_BIT(UCSRC,UPM0);
				SET_BIT(UCSRC,UPM1);
#endif
	
//Sync config
#if sync_mode_selector == SYNCH
			
				SET_BIT(UCSRC, UMSEL);
			
			#elif sync_mode_selector == ASYNCH
			
				RESET_BIT(UCSRC, UMSEL);
			

#endif

//Stop bits config
#if number_stopBits_selector == ONE_STOP_BIT
			
				RESET_BIT(UCSRC, USBS);
			
		#elif number_stopBits_selector == TWO_STOP_BIT
			
				SET_BIT(UCSRC, USBS);
			

#endif

//data bits config
#if number_dataBits_selector == _5_DATA_BITS
			
				RESET_BIT(UCSRC, UCSZ0);
				RESET_BIT(UCSRC, UCSZ1);
				RESET_BIT(UCSRB, UCSZ2);
			
			#elif number_dataBits_selector == _6_DATA_BITS
			
				SET_BIT(UCSRC, UCSZ0);
				RESET_BIT(UCSRC, UCSZ1);
				RESET_BIT(UCSRB, UCSZ2);
			
			#elif number_dataBits_selector == _7_DATA_BITS
			
				RESET_BIT(UCSRC, UCSZ0);
				SET_BIT(UCSRC, UCSZ1);
				RESET_BIT(UCSRB, UCSZ2);
			
			#elif number_dataBits_selector == _8_DATA_BITS
			
				SET_BIT(UCSRC, UCSZ0);
				SET_BIT(UCSRC, UCSZ1);
				RESET_BIT(UCSRB, UCSZ2);
			
			#elif number_dataBits_selector == _9_DATA_BITS
			
				SET_BIT(UCSRC, UCSZ0);
				SET_BIT(UCSRC, UCSZ1);
				SET_BIT(UCSRB, UCSZ2);		
#endif
}



// Data Transmission Sending Frames with 5 to 8 Data Bit
void USART_transmit( uint8_t data )
{
	// Wait for empty transmit buffer
	while(! (UCSRA & (1 << UDRE)));
	;
	// Put data into buffer, sends the data
	UDR = data;
}




// Receiving Frames with 5 to 8 Data Bits
uint8_t USART_receive( void )
{
	// Wait for data to be received
	while ( !(UCSRA & (1<<RXC)) )
	;
	// Get and return received data from buffer
	return UDR;
}




void USART_Transmit_string (char * str)
{
	uint8_t i =0 ;
	while(str[i]!=0)
	{ USART_transmit(str[i]); i++;}
	
}




char * USART_receive_string (uint8_t *string)  //Receive a character until carriage return or newline
{

	uint8_t  i=0,char_input=0;
	

	do

	{

		*(string+i)= USART_receive();

		char_input = *(string+i);

		i++;

	}while((char_input!='\n') && (char_input!='\r'));
	
	i++;
	*(string+i) = '\0';
		int u=0;
		while ((*(string+u)) !=0) u++;
		*(string+(u-1))=0;
	return string;

}
