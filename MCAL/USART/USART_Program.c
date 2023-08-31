/*
 * USART_Program.c
 *
 * Created: 8/31/2023 9:45:05 AM
 *  Author: Ahmed ElSayed
 */ 

#include "USART_Private.h"
#include "USART_Interface.h"
#include "USART_Config.h"

void USART_Init(){
	
	UINT8_t UCSRA_setting = 0;
	UINT8_t UCSRB_setting = 0;
	UINT8_t UCSRC_setting = 0;
	
	/*=============================*/
	/*		  UCSRC Setting		   */
	/*=============================*/
	/*select UCSRC register*/
	SET_BIT(UCSRC_setting, UCSRC_URSEL);
	/*set USART mode*/
	#if USART_MODE == USART_ASYNC
	
	CLEAR_BIT(UCSRC_setting, UCSRC_UMSEL);
	
	#elif USART_MODE == USART_SYNC
	
	SET_BIT(UCSRC_setting, UCSRC_UMSEL);
	
	#else
	#error
	#endif /*USART_MODE*/
	
	/*set parity*/
	#if USART_PARITY_MODE == USART_NO_PARITY
	
	CLEAR_BIT(UCSRC_setting, UCSRC_UPM0);
	CLEAR_BIT(UCSRC_setting, UCSRC_UPM1);
	
	#elif USART_PARITY_MODE == USART_EVEN_PARITY
	
	CLEAR_BIT(UCSRC_setting, UCSRC_UPM0);
	SET_BIT(UCSRC_setting, UCSRC_UPM1);
	
	#elif USART_PARITY_MODE == USART_ODD_PARITY
	
	SET_BIT(UCSRC_setting, UCSRC_UPM0);
	SET_BIT(UCSRC_setting, UCSRC_UPM1);
	
	#else
	#error
	#endif /*USART_PARITY_MODE*/
	
	/*set number of stop bits*/
	#if USART_STOP_BIT == USART_1_STOP_BIT
	
	CLEAR_BIT(UCSRC_setting, UCSRC_USBS);
	
	#elif USART_STOP_BIT == USART_2_STOP_BITS
	
	SET_BIT(UCSRC_setting, UCSRC_USBS)
	
	#else
	#error
	#endif /*USART_STOP_BIT*/
	
	/*set character size*/
	#if USART_CHR_SIZE == USART_5_BIT_CHR
	
	CLEAR_BIT(UCSRC_setting, UCSRC_UCSZ0);
	CLEAR_BIT(UCSRC_setting, UCSRC_UCSZ1);
	CLEAR_BIT(UCSRB_setting, UCSRB_UCSZ2);
	
	#elif USART_CHR_SIZE == USART_6_BIT_CHR
		
	SET_BIT(UCSRC_setting, UCSRC_UCSZ0);
	CLEAR_BIT(UCSRC_setting, UCSRC_UCSZ1);
	CLEAR_BIT(UCSRB_setting, UCSRB_UCSZ2);

	#elif USART_CHR_SIZE == USART_7_BIT_CHR
	
	CLEAR_BIT(UCSRC_setting, UCSRC_UCSZ0);
	SET_BIT(UCSRC_setting, UCSRC_UCSZ1);
	CLEAR_BIT(UCSRB_setting, UCSRB_UCSZ2);

	#elif USART_CHR_SIZE == USART_8_BIT_CHR
	
	SET_BIT(UCSRC_setting, UCSRC_UCSZ0);
	SET_BIT(UCSRC_setting, UCSRC_UCSZ1);
	CLEAR_BIT(UCSRB_setting, UCSRB_UCSZ2);

	#elif USART_CHR_SIZE == USART_9_BIT_CHR
	
	SET_BIT(UCSRC_setting, UCSRC_UCSZ0);
	SET_BIT(UCSRC_setting, UCSRC_UCSZ1);
	SET_BIT(UCSRB_setting, UCSRB_UCSZ2);

	#else
	#error
	#endif /*USART_CHR_SIZE*/
	
	/*set clock polarity*/
	#if USART_CLK_PARITY == USART_TX_RISING_EDGE
	
	CLEAR_BIT(UCSRC_setting, UCSRC_UCPOL);
	
	#elif USART_CLK_PARITY == USART_TX_FALLING_EDGE
	
	SET_BIT(UCSRC_setting, UCSRC_UCPOL);
	
	#else
	#error
	#endif /*USART_CLK_PARITY*/
	
	/*=============================*/
	/*		  UCSRB Setting		   */
	/*=============================*/
	/*receiver control*/
	#if	USART_RX_MODE == USART_RX_DS
	
	CLEAR_BIT(UCSRB_setting, UCSRB_RXEN);
	
	#elif USART_RX_MODE == USART_RX_EN
	
	SET_BIT(UCSRB_setting, UCSRB_RXEN);
	
	#else
	#error
	#endif /*USART_RX_MODE*/
	
	/*receiver interrupt control*/
	#if	USART_RX_INT_MODE == USART_RX_INT_DS
	
	CLEAR_BIT(UCSRB_setting, UCSRB_RXCIE);
	
	#elif USART_RX_INT_MODE == USART_RX_INT_EN
	
	SET_BIT(UCSRB_setting, UCSRB_RXCIE);
	GIE_Enable();
	
	#else
	#error
	#endif /*USART_RX_INT_MODE*/
	
	/*transmitter control*/
	#if	USART_TX_MODE == USART_TX_DS
	
	CLEAR_BIT(UCSRB_setting, UCSRB_TXEN);
	
	#elif USART_TX_MODE == USART_TX_EN
	
	SET_BIT(UCSRB_setting, UCSRB_TXEN);
	
	#else
	#error
	#endif /*USART_TX_MODE*/
	
	/*transmitter interrupt control*/
	#if	USART_TX_INT_MODE == USART_TX_INT_DS
	
	CLEAR_BIT(UCSRB_setting, UCSRB_TXCIE);
	
	#elif USART_TX_INT_MODE == USART_TX_INT_EN
	
	SET_BIT(UCSRB_setting, UCSRB_TXCIE);
	GIE_Enable();
	
	#else
	#error
	#endif	/*USART_TX_INT_MODE*/
	
	/*data register empty interrupt control*/
	#if	USART_DRE_INT_MODE == USART_DRE_INT_DS
	
	CLEAR_BIT(UCSRB_setting, UCSRB_UDRIE);
	
	#elif USART_DRE_INT_MODE == USART_DRE_INT_EN
	
	SET_BIT(UCSRB_setting, UCSRB_UDRIE);
	GIE_Enable();
	
	#else
	#error
	#endif /*USART_DRE_INT_MODE*/

	/*=============================*/
	/*		  UCSRA Setting		   */
	/*=============================*/
	/*data register empty interrupt control*/
	#if	USART_DDR_MODE == USART_DDR_DS || USART_MODE == USART_SYNC
	
	CLEAR_BIT(UCSRA_setting, UCSRA_U2X);
	
	#elif USART_RX_MODE == USART_DDR_EN && USART_MODE == USART_ASYNC
	
	SET_BIT(UCSRA_setting, UCSRA_U2X);
	GIE_Enable();
	
	#else
	#error
	#endif /*USART_DDR_MODE*/
	
	/*data register empty interrupt control*/
	#if	USART_MULTI_ECU_MODE == USART_MULTI_ECU_DS
	
	CLEAR_BIT(UCSRB_setting, UCSRB_UDRIE);
	
	#elif USART_MULTI_ECU_MODE == USART_MULTI_ECU_EN
	
	SET_BIT(UCSRB_setting, UCSRB_UDRIE);
	GIE_Enable();
	
	#else
	#error
	#endif /*USART_MULTI_ECU_MODE*/
	
	/*Write to registers*/
	UCSRC = UCSRC_setting;
	UCSRB = UCSRB_setting;
	UCSRA = UCSRA_setting;
}


void USART_Set_Baudrate(UINT32_t baudrate){
	UINT32_t reg_val = 0;
	
	#if USART_MODE == USART_ASYNC
	
	#if USART_DDR_MODE == USART_DDR_DS
	
	reg_val = (F_CPU / (16 * baudrate)) - 1;
	
	#elif USART_DDR_MODE == USART_DDR_EN
	
	reg_val = (F_CPU / (8 * baudrate)) - 1;
	
	#endif /*USART_DDR_MODE*/
	
	#elif USART_MODE == USART_SYNC
	
	reg_val = (F_CPU / (2 * baudrate)) - 1;
	
	#endif /*USART_MODE*/
	
	UBRRL = (UINT8_t)reg_val;
	UBRRH = (UINT8_t)(reg_val >> 8);
	
}
 
UINT8_t USART_RecieveCharacter(){
	UINT8_t buffer = 0;
	
	while(!READ_BIT(UCSRA, UCSRA_RXC));
	
	return UDR;	 
}

void USART_SendCharacter(UINT8_t chr){
	UINT16_t timeout = 0;
	
	while(!READ_BIT(UCSRA, UCSRA_TXC) || timeout == 5000){
		timeout++;
	}
	
	UDR = chr;
}
void _vector_13(void) __attribute__((signal));

void _vector_13(){
	
}

