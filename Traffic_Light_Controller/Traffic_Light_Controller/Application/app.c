/*
 * app.c
 *
 * Created: 8/9/2022 1:44:24 AM
 *  Author: Abdallah
 */ 

#include "app.h"
#include "../MCAL/Timer/Timer.h"
#include "../Utilities/Registers.h"
#include "../HAL/LED/LED.h"
#include "../HAL/Button/Button.h"
#include "../MCAL/EXTI/EXTI.h"

u8 temp;	/* This variable is used to indicate which LED was On when the button was pressed */
u8 Red_interrupt_flag;	/* This variable is used to control the flow after the ISR gets executed */
u8 green_and_yellow_interrupt_flag;


void appStart(void)
{		
	
	
	    /* ===================== LCD/Button Initialization ========================== */
		
		/* Enable Global Interrupts */
		SREG |= (1<<I);
		
		
		/* INT0 --> PD2 which is number 26 */
		Button_Init(PEDESTRIAN_BUTTON);
		
	    /* Port A : pins 0, 1, 2 --> Output for Cars*/
	    LED_init(CARS_GREEN_LED);
	    LED_init(CARS_YELLOW_LED);
	    LED_init(CARS_RED_LED);
	    
	    /* Port B : pins 0, 1, 2 --> Output for Pedestrians*/
	    LED_init(PEDESTRIAN_GREEN_LED);
	    LED_init(PEDESTRIAN_YELLOW_LED);
	    LED_init(PEDESTRIAN_RED_LED);		
		
		/* Enable Interrupt for INT0 External Interrupt */
		INT0_Enable_EXTI();
		
		/* The rising edge of INT0 generates an interrupt request */
		INT0_Enable_Rising_Edge_Sense();
	
	while (1)
	{
			Red_interrupt_flag = 0;
			green_and_yellow_interrupt_flag = 0;
			LED_off(PEDESTRIAN_RED_LED);
		
			LED_on(CARS_GREEN_LED);
			temp = 2;
			
			
			if (green_and_yellow_interrupt_flag != 1)
			{
				Timer1_Delay_5sec();
				LED_off(CARS_GREEN_LED);
				
				LED_on(CARS_YELLOW_LED);
				temp = 2;
				
				if (green_and_yellow_interrupt_flag != 1)
				{
					Timer1_Delay_5sec();
					LED_off(CARS_YELLOW_LED);
				
					LED_on(CARS_RED_LED);
					temp = 1;
					
					if (Red_interrupt_flag != 1)
					{
						Timer1_Delay_5sec();
						LED_off(CARS_RED_LED);
						
						LED_on(CARS_YELLOW_LED);
						temp = 2;
						
						if (green_and_yellow_interrupt_flag != 1)
						{
							Timer1_Delay_5sec();
							LED_off(CARS_YELLOW_LED);
						}
					}

				}
				
	}
}		

	
	
	
	

	
	
	

	
	
	
}