/*
 * DIO_DRIVER_Program.c
 *
 *  Created on: Dec 29, 2022
 *      Author: moham
 */
#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_CALC.h"
#include "DIO_DRIVER_Private.h"
#include "DIO_DRIVER_Config.h"
#include "DIO_DRIVER_Interface.h"

#if GPIO_MODE == 0 || DRIVER_MODE == 1
Stauts DIO_StautsSetPinValue(DIO_PORT_ID Copy_u8PortID,DIO_PIN_ID Copy_u8PinID,DIO_PIN_VALUE Copy_u8PinValue)
{
	Stauts Local_Stauts = NOK;
	if((Copy_u8PortID>=PORTA) && (Copy_u8PortID<=PORTD))
	{
		if((Copy_u8PinID>=PIN0) && (Copy_u8PinID<=PIN7))
		{
			if((Copy_u8PinValue == LOW) || (Copy_u8PinValue == HIGH))
			{
				switch(Copy_u8PortID)
				{
				case PORTA: Assign_Bit(DIOA->PORT,Copy_u8PinID,Copy_u8PinValue);Local_Stauts=OK;break;
				case PORTB: Assign_Bit(DIOB->PORT,Copy_u8PinID,Copy_u8PinValue);Local_Stauts=OK;break;
				case PORTC: Assign_Bit(DIOC->PORT,Copy_u8PinID,Copy_u8PinValue);Local_Stauts=OK;break;
				case PORTD: Assign_Bit(DIOD->PORT,Copy_u8PinID,Copy_u8PinValue);Local_Stauts=OK;break;
				}

			}else{Local_Stauts = PIN_VAL_ERR;}
		}else{Local_Stauts = PIN_ID_ERR;}
	}else{Local_Stauts = PORT_ID_ERR;}
	return Local_Stauts;
}

Stauts DIO_StautsSetPinDirection(DIO_PORT_ID Copy_u8PortID,DIO_PIN_ID Copy_u8PinID,DIO_PIN_DIRECTION Copy_u8PinDirection)
{
	Stauts Local_Stauts = NOK;
	if((Copy_u8PortID>=PORTA) && (Copy_u8PortID<=PORTD))
	{
		if((Copy_u8PinID>=PIN0) && (Copy_u8PinID<=PIN7))
		{
			if((Copy_u8PinDirection == INPUT) || (Copy_u8PinDirection == OUTPUT))
			{
				switch(Copy_u8PortID)
				{
				case PORTA: Assign_Bit(DIOA->DDR,Copy_u8PinID,Copy_u8PinDirection);Local_Stauts=OK;break;
				case PORTB: Assign_Bit(DIOB->DDR,Copy_u8PinID,Copy_u8PinDirection);Local_Stauts=OK;break;
				case PORTC: Assign_Bit(DIOC->DDR,Copy_u8PinID,Copy_u8PinDirection);Local_Stauts=OK;break;
				case PORTD: Assign_Bit(DIOD->DDR,Copy_u8PinID,Copy_u8PinDirection);Local_Stauts=OK;break;
				}

			}else{Local_Stauts = PIN_DIR_ERR;}
		}else{Local_Stauts = PIN_ID_ERR;}
	}else{Local_Stauts = PORT_ID_ERR;}
	return Local_Stauts;
}


Stauts DIO_StautsGetPinValue(DIO_PORT_ID Copy_u8PortID,DIO_PIN_ID Copy_u8PinID,u8 *Copy_u8PinValue)
{
	Stauts Local_Stauts = NOK;
	if((Copy_u8PortID>=PORTA) && (Copy_u8PortID<=PORTD)){
		if((Copy_u8PinID>=PIN0) && (Copy_u8PinID<=PIN7)){
			switch(Copy_u8PortID)
			{
			case PORTA: *Copy_u8PinValue = Get_Bit(DIOA->PIN,Copy_u8PinID);Local_Stauts=OK;break;
			case PORTB: *Copy_u8PinValue = Get_Bit(DIOB->PIN,Copy_u8PinID);Local_Stauts=OK;break;
			case PORTC: *Copy_u8PinValue = Get_Bit(DIOC->PIN,Copy_u8PinID);Local_Stauts=OK;break;
			case PORTD: *Copy_u8PinValue = Get_Bit(DIOD->PIN,Copy_u8PinID);Local_Stauts=OK;break;
			}

		}else{Local_Stauts = PIN_ID_ERR;}
	}else{Local_Stauts = PORT_ID_ERR;}
	return Local_Stauts;
}
Stauts DIO_StautsTogglePinValue(DIO_PORT_ID Copy_u8PortID,DIO_PIN_ID Copy_u8PinID)
{
	Stauts Local_Stauts = NOK;
	if((Copy_u8PortID>=PORTA) && (Copy_u8PortID<=PORTD)){
		if((Copy_u8PinID>=PIN0) && (Copy_u8PinID<=PIN7)){
			switch(Copy_u8PortID)
			{
			case PORTA: Toggle_Bit(DIOA->PORT,Copy_u8PinID);Local_Stauts=OK;break;
			case PORTB: Toggle_Bit(DIOB->PORT,Copy_u8PinID);Local_Stauts=OK;break;
			case PORTC: Toggle_Bit(DIOC->PORT,Copy_u8PinID);Local_Stauts=OK;break;
			case PORTD: Toggle_Bit(DIOD->PORT,Copy_u8PinID);Local_Stauts=OK;break;
			}

		}else{Local_Stauts = PIN_ID_ERR;}
	}else{Local_Stauts = PORT_ID_ERR;}
	return Local_Stauts;
}
#endif

#if GPIO_MODE == 1 || DRIVER_MODE == 1
Stauts DIO_StautsSetPortValue(DIO_PORT_ID Copy_u8PortID,u8 Copy_u8PortValue)
{
	Stauts Local_Stauts = NOK;
	if((Copy_u8PortID>=PORTA) && (Copy_u8PortID<=PORTD))
	{
		if((Copy_u8PortValue >= MIN_u8_PORT_VALUE) || (Copy_u8PortValue<= MAX_u8_PORT_VALUE))
		{
			switch(Copy_u8PortID)
			{
			case PORTA: Assign_Byte(DIOA->PORT,Copy_u8PortValue);Local_Stauts=OK;break;
			case PORTB: Assign_Byte(DIOB->PORT,Copy_u8PortValue);Local_Stauts=OK;break;
			case PORTC: Assign_Byte(DIOC->PORT,Copy_u8PortValue);Local_Stauts=OK;break;
			case PORTD: Assign_Byte(DIOD->PORT,Copy_u8PortValue);Local_Stauts=OK;break;
			}

		}else{Local_Stauts = PORT_VAL_ERR;}
	}else{Local_Stauts = PORT_ID_ERR;}
	return Local_Stauts;
}

Stauts DIO_StautsSetPortDirection(DIO_PORT_ID Copy_u8PortID,u8 Copy_u8PortDirection)
{
	Stauts Local_Stauts = NOK;
	if((Copy_u8PortID>=PORTA) && (Copy_u8PortID<=PORTD))
	{
		if((Copy_u8PortDirection >= MIN_u8_PORT_DIRECTION) || (Copy_u8PortDirection <= MAX_u8_PORT_DIRECTION))
		{
			switch(Copy_u8PortID)
			{
			case PORTA: Assign_Byte(DIOA->DDR ,Copy_u8PortDirection);Local_Stauts=OK;break;
			case PORTB: Assign_Byte(DIOB->DDR ,Copy_u8PortDirection);Local_Stauts=OK;break;
			case PORTC: Assign_Byte(DIOC->DDR ,Copy_u8PortDirection);Local_Stauts=OK;break;
			case PORTD: Assign_Byte(DIOD->DDR ,Copy_u8PortDirection);Local_Stauts=OK;break;
			}

		}else{Local_Stauts = PORT_DIR_ERR;}
	}else{Local_Stauts = PORT_ID_ERR;}
	return Local_Stauts;
}
Stauts DIO_StautsGetPortValue(DIO_PORT_ID Copy_u8PortID,u8 *Copy_u8PortValue)
{
	Stauts Local_Stauts = NOK;
	if((Copy_u8PortID>=PORTA) && (Copy_u8PortID<=PORTD)){
		switch(Copy_u8PortID)
		{
		case PORTA: *Copy_u8PortValue = DIOA->PIN;Local_Stauts=OK;break;
		case PORTB: *Copy_u8PortValue = DIOB->PIN;Local_Stauts=OK;break;
		case PORTC: *Copy_u8PortValue = DIOC->PIN;Local_Stauts=OK;break;
		case PORTD: *Copy_u8PortValue = DIOD->PIN;Local_Stauts=OK;break;
		}

	}else{Local_Stauts = PORT_ID_ERR;}
	return Local_Stauts;
}
#endif

