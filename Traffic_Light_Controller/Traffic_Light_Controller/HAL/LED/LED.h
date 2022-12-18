/*
 * LED.h
 *
 * Created: 8/9/2022 2:02:43 AM
 *  Author: Abdallah
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO/DIO.h"
#include "../../Utilities/Typedefs.h"
/*====================================================================*/
/*Description: Reads the state of the button
 * Input     : u8 pinNumber, u8 *value
 * Output    : None
 * Return	 : Error Status 
 **/
/*====================================================================*/
Error LED_init (u8 pin_Number);

/*====================================================================*/
/*Description: Reads the state of the button
 * Input     : u8 pinNumber, u8 *value
 * Output    : None
 * Return	 : Error Status 
 **/
/*====================================================================*/
Error LED_on (u8 pinNumber);

/*====================================================================*/
/*Description: Reads the state of the button
 * Input     : u8 pinNumber, u8 *value
 * Output    : None
 * Return	 : Error Status 
 **/
/*====================================================================*/
Error LED_off (u8 pinNumber);

/*====================================================================*/
/*Description: Reads the state of the button
 * Input     : u8 pinNumber, u8 *value
 * Output    : None
 * Return	 : Error Status 
 **/
/*====================================================================*/
Error LED_toggle (u8 pinNumber);

/*====================================================================*/
/*Description: Reads the state of the button
 * Input     : u8 pinNumber, u8 *value
 * Output    : None
 * Return	 : Error Status 
 **/
/*====================================================================*/
Error LED_blink (u8 pinNumber);



#endif /* LED_H_ */