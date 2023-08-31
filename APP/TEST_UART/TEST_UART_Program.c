/*
 * TEST_UART_Program.c
 *
 * Created: 8/31/2023 9:29:19 PM
 *  Author: Ahmed ElSayed
 */ 
#include "TEST_UART_Interface.h"

void Init(){
	USART_Init();
	USART_Set_Baudrate(9600);
}

void Test_UART(){
	UINT8_t x = 0;
	
	USART_SendCharacter('H');
	USART_SendCharacter('e');
	USART_SendCharacter('l');
	USART_SendCharacter('l');
	USART_SendCharacter('o');
	
	x = USART_RecieveCharacter();
	USART_SendCharacter(x);
}