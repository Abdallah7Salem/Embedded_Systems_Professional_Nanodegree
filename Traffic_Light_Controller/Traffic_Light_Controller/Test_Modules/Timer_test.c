/*
 * Timer_test.c
 *
 * Created: 8/11/2022 9:04:00 PM
 *  Author: Abdallah
 */ 

#include "../config.h"
#include "../MCAL/Timer/Timer.h"

#if (TIMER_TEST == 1)

int main(void)
{
	Timer1_Delay_5sec();
	
	Timer2_Delay_262ms();
}



#endif