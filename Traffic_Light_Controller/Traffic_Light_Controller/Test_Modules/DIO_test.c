/*
 * DIO_test.c
 *
 * Created: 8/11/2022 9:03:22 PM
 *  Author: Abdallah
 */ 

#include "../config.h"
#include "../MCAL/DIO/DIO.h"

#if (DIO_TEST == 1)

int main(void)
{
	DIO_Pin_Init(3, OUTPUT);
	DIO_Pin_Write(3, HIGH);

	DIO_Pin_Init(2, OUTPUT);
	DIO_Pin_Write(2, LOW);

	DIO_Pin_Init(1, INPUT);

	DIO_Pin_Toggle(2);

	DIO_Port_Direction(PORTA, OUTPUT);

	DIO_Port_Write(PORTA, HIGH);

}



#endif