#ifndef MCAL_TIMER_TIMER_H_
#define MCAL_TIMER_TIMER_H_

#include "../../Utilities/Typedefs.h"

/******************************************************************/
/*                        MACROS                                  */
/******************************************************************/
#define NO_OF_CHANNELS 3

/******************************************************************/
/*                        TIMER_CHANNELS                          */
/******************************************************************/
#define TIMER0 0
#define TIMER1 1
#define TIMER2 2


/*====================================================================*/
/*Description: Timer1 Delay 5 seconds
 * Input     :  None
 * Output    : None
 * Return	 : Error Checking
 **/
/*====================================================================*/
Error Timer1_Delay_5sec(void);

/*====================================================================*/
/*Description: Timer2 Delay 262 milliseconds
 * Input     :  None
 * Output    : None
 * Return	 : Error Checking
 **/
/*====================================================================*/
Error Timer2_Delay_262ms(void);

#endif /* MCAL_TIMER_TIMER_H_ */
