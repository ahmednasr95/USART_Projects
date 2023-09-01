/*
 * main.c
 *
 * Created: 8/31/2023 9:37:01 AM
 *  Author: Ahmed ElSayed
 */ 
#include "TEST_UART_Interface.h"

int main(void)
{
	Init();
	
    while(1)
    {
        Test_UART();//TODO:: Please write your application code 
    }
}