/*
 * USART_Private.h
 *
 * Created: 8/31/2023 9:42:48 AM
 *  Author: Ahmed ElSayed
 */
#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "GIE_Interface.h"

/*Register addresses*/
#define		UDR		(*(volatile UINT16_t *) 0x2C)
#define		UCSRA	(*(volatile UINT8_t *) 0x2B)
#define		UCSRB	(*(volatile UINT8_t *) 0x2A)
#define		UCSRC	(*(volatile UINT8_t *) 0x40)
#define		UBRRL	(*(volatile UINT8_t *) 0x29)
#define		UBRRH	(*(volatile UINT8_t *) 0x40)	

/*UCSRA Pins*/
#define UCSRA_MPCM		0
#define UCSRA_U2X		1
#define UCSRA_PE		2
#define UCSRA_DOF		3
#define UCSRA_FE		4
#define UCSRA_UDRE		5
#define UCSRA_TXC		6
#define UCSRA_RXC		7

/*UCSRB Pins*/
#define UCSRB_TXB8		0
#define UCSRB_RXB8		1
#define UCSRB_UCSZ2		2
#define UCSRB_TXEN		3
#define UCSRB_RXEN		4
#define UCSRB_UDRIE		5
#define UCSRB_TXCIE		6
#define UCSRB_RXCIE		7

/*UCSRC Pins*/
#define UCSRC_UCPOL		0
#define UCSRC_UCSZ0		1
#define UCSRC_UCSZ1		2
#define UCSRC_USBS		3
#define UCSRC_UPM0		4
#define UCSRC_UPM1		5
#define UCSRC_UMSEL		6
#define UCSRC_URSEL		7

/*UBRRH Pins*/
#define UBRRH_URSEL		7

/*USART Modes*/
#define USART_ASYNC	0
#define	USART_SYNC	1

/*Parity Mode*/
#define USART_NO_PARITY		0
#define USART_EVEN_PARITY	2
#define USART_ODD_PARITY	3

/*Stop Bit Mode*/
#define USART_1_STOP_BIT	0
#define USART_2_STOP_BITS	1

/*Character Size*/
#define USART_5_BIT_CHR	0
#define USART_6_BIT_CHR	1
#define USART_7_BIT_CHR	2
#define USART_8_BIT_CHR	3
#define USART_9_BIT_CHR	7

/*Clock Parity*/
#define USART_TX_RISING_EDGE	0
#define USART_TX_FALLING_EDGE	1

/*Double baudrate*/
#define USART_DDR_DS	0
#define USART_DDR_EN	1

/*RX interrupt control*/
#define USART_RX_INT_DS		0
#define USART_RX_INT_EN		1

/*TX interrupt control*/
#define USART_TX_INT_DS		0
#define USART_TX_INT_EN		1

/*RX control*/
#define USART_RX_DS		0
#define USART_RX_EN		1

/*TX control*/
#define USART_TX_DS		0
#define USART_TX_EN		1

/*empty data register interrupt control*/
#define USART_DRE_INT_DS	0
#define USART_DRE_INT_EN	1

/*multi-processor mode control*/
#define USART_MULTI_ECU_DS		0
#define USART_MULTI_ECU_EN		1

#endif /* USART_PRIVATE_H_ */