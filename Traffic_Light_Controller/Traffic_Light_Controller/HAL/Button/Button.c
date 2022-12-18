/*
 * Button.c
 *
 * Created: 8/9/2022 1:18:06 AM
 *  Author: Abdallah
 */ 

#include "../../Utilities/Typedefs.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../Utilities/Registers.h"

Error Button_Init(u8 pinNumber)
{
	DIO_Pin_Init(pinNumber, INPUT);
	return NO_ERROR;
}


Error Button_Read(u8 pinNumber, u8 *value)
{
	DIO_Pin_Read(pinNumber, value);
	return NO_ERROR;
}