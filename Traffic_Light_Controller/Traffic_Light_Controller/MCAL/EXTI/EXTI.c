/*
 * EXTI.c
 *
 * Created: 8/11/2022 8:33:17 PM
 *  Author: Abdallah
 */ 

#include "EXTI.h"


Error INT0_Enable_EXTI(void)
{
	GICR |= (1<<INT0);
}

Error INT0_Enable_Rising_Edge_Sense()
{
	MCUCR |= (1<<ISC00) | (1<<ISC01);
}