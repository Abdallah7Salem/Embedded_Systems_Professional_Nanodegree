/*
 * LED.c
 *
 * Created: 8/9/2022 2:02:53 AM
 *  Author: Abdallah
 */ 

#include "LED.h"
#include "../../MCAL/Timer/Timer.h"

Error LED_init (u8 pin_Number)
{
	DIO_Pin_Init(pin_Number, OUTPUT);
}

Error LED_on (u8 pinNumber)
{
	DIO_Pin_Write(pinNumber, HIGH);
}
Error LED_off (u8 pinNumber)
{
	DIO_Pin_Write(pinNumber, LOW);
}
Error LED_toggle (u8 pinNumber)
{
	DIO_Pin_Toggle(pinNumber);
}


Error LED_blink (u8 pinNumber)
{
	//TIMER1_TCNT1 = 46006;
	TIMER1_TCNT1 = 62006;
	
	TIMER1_TCCR1B &= (0 << CS10) | (0 << CS11);
	TIMER1_TCCR1B |= (1 << CS12);
	
	while ((TIFR&(1<<TOV1)) == 0)
	{
		DIO_Pin_Write(pinNumber, HIGH);
		Timer2_Delay_262ms();
		DIO_Pin_Write(pinNumber, LOW);
		Timer2_Delay_262ms(); 
	}
	
	TIMER1_TCCR1B = 0;
	TIFR |= (1<<TOV1);
	
	return NO_ERROR;
}