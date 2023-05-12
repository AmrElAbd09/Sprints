/*
 * uart_config.h
 *
 * Created: 11/5/2023 10:34:27 AM
 *  Author: Amr
 */ 


#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_


typedef enum{
	normal_speed,
	double_speed
}EN_speed_mode_selector;



typedef enum{
	Transmit_Enable,
	Receive_Enable,	          
	Transmit_Receive_Enable		  
}EN_enable_selector;

typedef enum{
	NO_PARITY,
	EVEN_PARITY,
	ODD_PARITY
}EN_parity_mode_selector;


typedef enum{
	SYNCH,
	ASYNCH
}EN_sync_mode_selector;


typedef enum{
	ONE_STOP_BIT,
	TWO_STOP_BIT
}EN_number_stopBits_selector;


typedef enum{
	_5_DATA_BITS,
	_6_DATA_BITS,
	_7_DATA_BITS,
	_8_DATA_BITS,
	_9_DATA_BITS
}EN_number_dataBits_selector;



typedef enum{
	 BAUD_2400
	 BAUD_4800
	 BAUD_9600
	 BAUD_14400
	 BAUD_19200
	 BAUD_28800
}EN_baud_rate_selector;

typedef struct
{
	EN_speed_mode_selector			    Speed_config;
	EN_enable_selector					Enable_config;
	EN_parity_mode_selector			    Parity_config;
	EN_sync_mode_selector				Synch_config;
	EN_number_stopBits_selector		    StopBits_config;
	EN_number_dataBits_selector		    DataSize_config;
	EN_baud_rate_selector				BaudRate_config;

}ST_Config_Type;

#endif /* UART_LCFG_H_ */
 


