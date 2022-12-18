/*
 * LED_test.c
 *
 * Created: 8/11/2022 9:02:58 PM
 *  Author: Abdallah
 */ 

#include "../config.h"
#include "../HAL/LED/LED.h"

#if (LED_TEST == 1)

int main(void)
{
	LED_init(3);
	LED_on(3);
	LED_off(3);
	LED_toggle(3);
}



#endif