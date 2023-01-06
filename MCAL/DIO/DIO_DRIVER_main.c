/*
 * DIO_DRIVER_main.c
 *
 *  Created on: Dec 29, 2022
 *      Author: moham
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_CALC.h"
#include "DIO_DRIVER_Interface.h"
#include <avr/delay.h>
void main()
{
	DIO_StautsSetPinDirection(PORTB,PIN0,OUTPUT);
	while(1)
	{
		DIO_StautsTogglePinValue(PORTB,PIN0);
		_delay_ms(1000);

	}



}
