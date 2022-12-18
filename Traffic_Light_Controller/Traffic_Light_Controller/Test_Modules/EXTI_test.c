/*
 * EXTI_test.c
 *
 * Created: 8/11/2022 9:04:19 PM
 *  Author: Abdallah
 */ 

#include "../config.h"
#include "../MCAL/EXTI/EXTI.h"

#if (EXTI_TEST == 1)

int main(void)
{
	INT0_Enable_EXTI();
	
	INT0_Enable_Rising_Edge_Sense();
		
}



#endif