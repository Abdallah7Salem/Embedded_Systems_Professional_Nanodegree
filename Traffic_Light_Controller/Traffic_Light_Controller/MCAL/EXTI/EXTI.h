/*
 * EXTI.h
 *
 * Created: 8/11/2022 8:33:27 PM
 *  Author: Abdallah
 */ 

#include "../../Utilities/Typedefs.h"
#include "../../Utilities/Registers.h"

#ifndef EXTI_H_
#define EXTI_H_


#define EXTI_INT0	0u
#define EXTI_INT1	1u
#define EXTI_INT2	2u

Error INT0_Enable_EXTI(void);
Error INT0_Enable_Rising_Edge_Sense(void);

#endif /* EXTI_H_ */