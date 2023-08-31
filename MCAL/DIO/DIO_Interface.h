#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "STD_TYPES.h"

void DIO_SetPortDir(UINT8_t Port, UINT8_t Dir);
void DIO_SetPinDir(UINT8_t Port, UINT8_t Pin, UINT8_t Dir);

void DIO_SetPortVal(UINT8_t Port, UINT8_t Val);
void DIO_SetPinVal(UINT8_t Port, UINT8_t Pin, UINT8_t Val);

void DIO_ReadPort(UINT8_t Port, UINT8_t* Val);
void DIO_ReadPin(UINT8_t Port, UINT8_t Pin, UINT8_t* Val);

void DIO_TogglePin(UINT8_t Port,  UINT8_t Pin);
#endif	/* DIO_INTERFACE_H_ */


