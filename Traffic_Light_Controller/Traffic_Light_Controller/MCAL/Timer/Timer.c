#include "../../Utilities/Registers.h"
#include "Timer.h"
#include "../../Utilities/Common_Macros.h"

Error Timer1_Delay_5sec(void)
{
	
	/* This value will make a delay of 5 sec until it reaches overflow */
	TIMER1_TCNT1 = 46006;	// Pre-scaler = 256, CPU_Frequency = 1MHz 
	
	//TIMER1_TCNT1 = 60000;		// This value is just for debugging
	
	/* Initialize the timer with pre-scaler 256 */
	TIMER1_TCCR1B &= (0 << CS10) | (0 << CS11);
	TIMER1_TCCR1B |= (1 << CS12);
	
	while ((TIFR&(1<<TOV1)) == 0);
	
	TIMER1_TCCR1B = 0;
	TIFR |= (1<<TOV1);
	
	return NO_ERROR;
}

Error Timer2_Delay_262ms(void)
{
	TIMER2_TCNT2 = 0;
	
	TIMER2_TCCR2 |= (1 << CS20) | (1 << CS21) | (1<<CS22);
	
	while ((TIFR&(1<<TOV2)) == 0);
	
	TIMER2_TCCR2 = 0;
	TIFR |= (1<<TOV2);
	
	return NO_ERROR;
}



