/*
 * USART_Interface.h
 *
 * Created: 8/31/2023 9:43:02 AM
 *  Author: Ahmed ElSayed
 */ 


#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

#include "STD_TYPES.h"

void USART_Init(void);

void USART_Set_Baudrate(UINT32_t baudrate);

UINT8_t USART_RecieveCharacter(void);
void USART_SendCharacter(UINT8_t chr);

//void callback_func(void (*fPtr)(UINT8_t));

#endif /* USART_INTERFACE_H_ */