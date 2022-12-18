/*
 * Button_test.c
 *
 * Created: 8/11/2022 9:03:10 PM
 *  Author: Abdallah
 */ 

#include "../config.h"
#include "../HAL/Button/Button.h"

#if (BUTTON_TEST == 1)

vu8 x;

int main(void)
{
	Button_Init(3);
	
	Button_Init(5);
	
	x = DDRA;
}


#endif