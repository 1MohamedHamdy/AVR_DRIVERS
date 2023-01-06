/*
 * DIO_DRIVER_Config.h
 *
 *  Created on: Dec 29, 2022
 *      Author: moham
 */

#ifndef DIO_DRIVER_CONFIG_H_
#define DIO_DRIVER_CONFIG_H_

#define DRIVER_MODE	    1   //   For 1 Mode Only -> 0 , For 2 Mode -> 1

#if DRIVER_MODE == 0
#define DIO_MODE  	    0   //  For PIN MODE->0 , For PORT MODE-> 1
#endif


#endif /* DIO_DRIVER_CONFIG_H_ */
