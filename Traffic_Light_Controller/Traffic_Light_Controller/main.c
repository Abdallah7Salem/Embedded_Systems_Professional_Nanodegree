/*
 * Traffic_Light_Controller.c
 *
 * Created: 8/9/2022 1:15:36 AM
 * Author : Abdallah
 */ 

#include "config.h"

#if (MAIN_PROGRAM == 1)


#include "Application/app.h"
#include "Utilities/interrupt.h"
#include "MCAL/Timer/Timer.h"
#include "HAL/LED/LED.h"

extern u8 temp;
extern u8 Red_interrupt_flag;
extern u8 green_and_yellow_interrupt_flag;

#define F_CPU	1000000UL

/*
ISR(TIMER1_OVF_vect)
{
	Timer_Stop(TIMER1);
	Timer_Reset(TIMER1);
}
*/ // We don't need this function since we now have the timer in the polling mode 

ISR(INT0_Vect)
{
	
	if (temp == 1)
	{
		LED_off(PEDESTRIAN_RED_LED);
		LED_on(PEDESTRIAN_GREEN_LED);
		
		Timer1_Delay_5sec();
		
		LED_off(CARS_RED_LED);
		LED_off(PEDESTRIAN_GREEN_LED);
		
		LED_on(CARS_YELLOW_LED);
		LED_on(PEDESTRIAN_YELLOW_LED);
		
		Timer1_Delay_5sec();
		
		LED_off(CARS_YELLOW_LED);
		LED_off(PEDESTRIAN_YELLOW_LED);
		
		LED_on(PEDESTRIAN_RED_LED);
		LED_on(CARS_GREEN_LED);
		
		Red_interrupt_flag = 1;
		
	}
	else if (temp == 2)
	{
		LED_on(PEDESTRIAN_RED_LED);
		
		Timer1_Delay_5sec();
		
		LED_off(PEDESTRIAN_RED_LED);
		LED_off(CARS_GREEN_LED);
		
		LED_on(PEDESTRIAN_YELLOW_LED);
		LED_on(CARS_YELLOW_LED);
		
		Timer1_Delay_5sec();
		
		LED_off(PEDESTRIAN_YELLOW_LED);
		LED_off(CARS_YELLOW_LED);
		
		LED_on(CARS_RED_LED);
		LED_on(PEDESTRIAN_GREEN_LED);
		
		Timer1_Delay_5sec();
		
		LED_off(CARS_RED_LED);
		LED_off(PEDESTRIAN_GREEN_LED);
		
		LED_on(CARS_YELLOW_LED);
		LED_on(PEDESTRIAN_YELLOW_LED);
		
		Timer1_Delay_5sec();
		
		LED_off(CARS_YELLOW_LED);
		LED_off(PEDESTRIAN_YELLOW_LED);
		
		LED_on(PEDESTRIAN_RED_LED);
		LED_on(CARS_GREEN_LED);
		
		green_and_yellow_interrupt_flag = 1;
		
	}
}

int main(void)
{
	appStart();
}


#endif