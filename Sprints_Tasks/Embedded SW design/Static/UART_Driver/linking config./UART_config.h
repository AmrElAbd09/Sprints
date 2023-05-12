/*
 * CFile1.c
 *
 * Created: 11-May-23 2:15:57 AM
 *  Author: Amr
 */ 

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

//*******************************************************************************************************
 /* configure enable modes
 // Transmit_Enable    
    Receive_Enable
    Transmit_Receive_Enable
*/
#define  Enable_config 		Transmit_Receive_Enable

//*******************************************************************************************************
 /* configure speed modes
 // speed modes
  normal_speed     
  double_speed          
*/
#define Speed_config		normal_speed

 /* configure parity modes
 // parity modes
 NO_PARITY    
 EVEN_PARITY  
 ODD_PARITY   
*/
#define Parity_config		NO_PARITY   

 /* configure sync modes
 // sync modes
 SYNCH  
 ASYNCH 
*/
#define Synch_config		ASYNCH 

 /* configure number of stop bits 
 // number of stop bits
 ONE_STOP_BIT   
 TWO_STOP_BIT   
*/
#define StopBits_config		ONE_STOP_BIT   

 /* configure number of data bits
  // number of data bits
  _5_DATA_BITS    
  _6_DATA_BITS    
  _7_DATA_BITS    
  _8_DATA_BITS    
  _9_DATA_BITS    
*/
 
 
#define DataSize_config		_8_DATA_BITS    


/* configure Baud rate
  // Baud rate
	BAUD_2400
	BAUD_4800
	BAUD_9600
	BAUD_14400
	BAUD_19200
	BAUD_28800  
*/
#define BaudRate_config		BAUD_9600   
//***************************************************************************************************************

#endif /* UART_LCFG_H_ */
 
