/*
 * USART_Program.c
 *
 * Created: 8/31/2023 9:45:05 AM
 *  Author: Ahmed ElSayed
 */ 

#include "USART_Config.h"
#include "USART_Interface.h"
#include "USART_Private.h"

void USART_Init(){
	UINT8_t val = 0;
	
	val |= ()
	
	SET_BIT(val, UCSRC_URSEL);
	
	#if USART_MODE == USART_ASYNC
	
	CLEAR_BIT(val, UCSRC_UMSEL);
	
	#elif USART_MODE == USART_SYNC
	
	SET_BIT(val, UCSRC_UMSEL);
	#endif
	
	/**********/
	
	#if USART_PARITY_MODE == USART_EVEN_PARITY
	
	CLEAR_BIT(val, UCSRC_UPM0);
	SET_BIT(val, UCSRC_UPM1);
	
	#elif USART_PARITY_MODE == USART_ODD_PARITY
	
	SET_BIT(val, UCSRC_UPM0);
	SET_BIT(val, UCSRC_UPM1);
	
	#endif
	
	UCSRC |= val;
	
	
}
 
void _vector_13(void) __attribute__(signal);