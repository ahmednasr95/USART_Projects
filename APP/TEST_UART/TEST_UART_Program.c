/*
* TEST_UART_Program.c
*
* Created: 8/31/2023 9:29:19 PM
*  Author: Ahmed ElSayed
*/
#include "TEST_UART_Interface.h"
#include <util/delay.h>
#include "DIO_Interface.h"
#include "DIO_Private.h"

void Init(){
	USART_Init();
	USART_Set_Baudrate(9600);
	
	DIO_SetPinDir(DIO_PORTA, DIO_PIN7, DIO_PIN_OUTPUT);
	//USART_SendCharacter('H');
	//USART_SendCharacter('e');
	//USART_SendCharacter('l');
	//USART_SendCharacter('l');
	//USART_SendCharacter('o');
}

void Test_UART(){
	UINT8_t x = 0;
	x = USART_RecieveCharacter();
	//USART_SendCharacter('k');
	
	if(x == 'A'){
		DIO_TogglePin(DIO_PORTA, DIO_PIN7);
		
		USART_SendCharacter('b');
		_delay_ms(1000);
	}
}