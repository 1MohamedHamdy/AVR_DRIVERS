/*
 * DIO_DRIVER_Interface.h
 *
 *  Created on: Dec 29, 2022
 *      Author: moham
 */

#ifndef DIO_DRIVER_INTERFACE_H_
#define DIO_DRIVER_INTERFACE_H_

typedef enum
{
	NOK,
	OK,
	OUT_OF_RANGE,
	PORT_ID_ERR,
	PORT_VAL_ERR,
	PORT_DIR_ERR,
	PIN_ID_ERR,
	PIN_VAL_ERR,
	PIN_DIR_ERR
}Stauts;


typedef enum
{
	PORTA,PORTB,PORTC,PORTD

}DIO_PORT_ID;

typedef enum
{
	LOW , HIGH

}DIO_PIN_VALUE;
typedef enum
{
	INPUT , OUTPUT

}DIO_PIN_DIRECTION;
#if DIO_MODE == 0 || DRIVER_MODE == 1
typedef enum
{
	PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7

}DIO_PIN_ID;
Stauts DIO_StautsSetPinValue(DIO_PORT_ID Copy_u8PortID,DIO_PIN_ID Copy_u8PinID,DIO_PIN_VALUE Copy_u8PinValue);
Stauts DIO_StautsSetPinDirection(DIO_PORT_ID Copy_u8PortID,DIO_PIN_ID Copy_u8PinID,DIO_PIN_DIRECTION Copy_u8PinDirection);
Stauts DIO_StautsGetPinValue(DIO_PORT_ID Copy_u8PortID,DIO_PIN_ID Copy_u8PinID,u8 *Copy_u8PinValue);
Stauts DIO_StautsTogglePinValue(DIO_PORT_ID Copy_u8PortID,DIO_PIN_ID Copy_u8PinID);

#endif

#if DIO_MODE == 1 || DRIVER_MODE == 1

Stauts DIO_StautsSetPortValue(DIO_PORT_ID Copy_u8PortID,u8 Copy_u8PortValue);
Stauts DIO_StautsSetPortDirection(DIO_PORT_ID Copy_u8PortID,u8 Copy_u8PortDirection);
Stauts DIO_StautsGetPortValue(DIO_PORT_ID Copy_u8PortID,u8 *Copy_u8PortValue);

#define LOW_PORT      0x00
#define HIGH_PORT     0xFF

#define INPUT_PORT    0x00
#define OUTPUT_PORT   0xFF


#endif

#endif /* DIO_DRIVER_INTERFACE_H_ */
