/*
 * interrupt.h
 *
 * Created: 8/11/2022 8:46:30 PM
 *  Author: Abdallah
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#define ISR(VECTOR_NUMBER) void VECTOR_NUMBER (void) __attribute__((signal));\
void VECTOR_NUMBER (void)

#define INT0_Vect	__vector_1



#endif /* INTERRUPT_H_ */