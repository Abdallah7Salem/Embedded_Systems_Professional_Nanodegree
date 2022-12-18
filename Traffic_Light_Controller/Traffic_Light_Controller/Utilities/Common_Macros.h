/*
 * Common_Macros.h
 *
 *  Created on: Jul 22, 2022
 *      Author: Abdallah
 */

#ifndef UTILITIES_COMMON_MACROS_H_
#define UTILITIES_COMMON_MACROS_H_


#define SET_BIT(PORT, BIT_NUMBER)  (PORT |= (1<<BIT_NUMBER))

#define RESET_BIT(PORT, BIT_NUMBER) (PORT &= ~(1<<BIT_NUMBER))

#define READ_BIT(PORT, BIT_NUMBER) ((PORT & (1<<BIT_NUMBER))>>BIT_NUMBER)

#define TOGGLE_BIT(PORT, BIT_NUMBER) (PORT ^= (1<<BIT_NUMBER))

#endif /* UTILITIES_COMMON_MACROS_H_ */
