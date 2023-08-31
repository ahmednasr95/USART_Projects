#ifndef _ATMEG32_REGISTERS_H_
#define _ATMEGA32_REGISTERS_H_

#define F_CPU 16000000

#include <util/delay.h>
#include "STD_TYPES.h"

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

#define STATUS_REG			(*(volatile UINT8_t*)0x5F)
#define MCUCR_REG			(*(volatile UINT8_t*)0x55)
#define MCUCSR_REG			(*(volatile UINT8_t*)0x54)
#define GICR_REG			(*(volatile UINT8_t*)0x5B)
#define GIFR_REG			(*(volatile UINT8_t*)0x5A)

#define TIMER0_CONTROL_R	(*(volatile UINT8_t*)0x53)
#define TIMER0_ACC_R		(*(volatile UINT8_t*)0x52)
#define TIMER0_COMP_R		(*(volatile UINT8_t*)0x5C)
#define TIMER_I_MASK_R		(*(volatile UINT8_t*)0x59)
#define TIMER_I_FLAG_R		(*(volatile UINT8_t*)0x58)

#define ADC_CONTROL_R		(*(volatile UINT8_t*)0x26)
#define ADC_MULTIPLEXER_R	(*(volatile UINT8_t*)0x27)
#define ADC_HIGH_BYTE_R		(*(volatile UINT8_t*)0x25)
#define ADC_LOW_BYTE_R		(*(volatile UINT8_t*)0x24)
#define ADC_R				(*(volatile UINT16_t*)0x24)

#define SPECIAL_FUNC_R		(*(volatile UINT8_t*)0x50)

#endif