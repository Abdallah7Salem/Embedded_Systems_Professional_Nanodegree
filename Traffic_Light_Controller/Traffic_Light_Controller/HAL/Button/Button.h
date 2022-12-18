/*
 * Button.h
 *
 * Created: 8/9/2022 1:17:58 AM
 *  Author: Abdallah
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO/DIO.h"

/*====================================================================*/
/*Description: Button Initialization
 * Input     : u8 pinNumber
 * Output    : None
 * Return	 : Error Status
 **/
/*====================================================================*/
Error Button_Init(u8 pinNumber);

/*====================================================================*/
/*Description: Reads the state of the button
 * Input     : u8 pinNumber, u8 *value
 * Output    : None
 * Return	 : Error Status 
 **/
/*====================================================================*/
Error Button_Read(u8 pinNumber, u8 *value);



#endif /* BUTTON_H_ */