/*
 * DIO_DRIVER_Private.h
 *
 *  Created on: Dec 29, 2022
 *      Author: moham
 */

#ifndef DIO_DRIVER_PRIVATE_H_
#define DIO_DRIVER_PRIVATE_H_

#define DIOD ((volatile DIO_t*)0x30)
#define DIOC ((volatile DIO_t*)0x33)
#define DIOB ((volatile DIO_t*)0x36)
#define DIOA ((volatile DIO_t*)0x39)

typedef struct
{
	volatile u8 PIN;
	volatile u8 DDR;
	volatile u8 PORT;
}DIO_t;


#define MIN_u8_PORT_VALUE      0
#define MAX_u8_PORT_VALUE      255

#define MIN_u8_PORT_DIRECTION      0
#define MAX_u8_PORT_DIRECTION      255


#endif /* DIO_DRIVER_PRIVATE_H_ */
