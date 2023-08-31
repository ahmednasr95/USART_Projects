/*
 * DIO_Private.h
 *
 * Created: 8/31/2023 7:14:07 PM
 *  Author: Ahmed ElSayed
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

/*register definition*/
#define PORTA_DDR			(*(volatile UINT8_t*)0x3A)
#define PORTB_DDR			(*(volatile UINT8_t*)0x37)
#define PORTC_DDR			(*(volatile UINT8_t*)0x34)
#define PORTD_DDR			(*(volatile UINT8_t*)0x31)

#define PORTA_DATA			(*(volatile UINT8_t*)0x3B)
#define PORTB_DATA			(*(volatile UINT8_t*)0x38)
#define PORTC_DATA			(*(volatile UINT8_t*)0x35)
#define PORTD_DATA			(*(volatile UINT8_t*)0x32)

#define PORTA_PIN			(*(volatile UINT8_t*)0x39)
#define PORTB_PIN			(*(volatile UINT8_t*)0x36)
#define PORTC_PIN			(*(volatile UINT8_t*)0x33)
#define PORTD_PIN			(*(volatile UINT8_t*)0x30)

/*constants definition*/
#define MAX_REG_VAL 0xFF

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7

#define DIO_PORT_INPUT 0x00
#define DIO_PORT_OUTPUT 0xFF

#define DIO_PIN_INPUT 0
#define DIO_PIN_OUTPUT 1

#define DIO_PIN_HIGH 1
#define DIO_PIN_LOW 0

#define DIO_PORT_HIGH 0xFF
#define DIO_PORT_LOW 0x00

#endif /* DIO_PRIVATE_H_ */