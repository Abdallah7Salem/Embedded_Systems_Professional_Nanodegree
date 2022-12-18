/*
 * Registers.h
 *
 *  Created on: Jul 22, 2022
 *      Author: Abdallah
 */

#ifndef UTILITIES_REGISTERS_H_
#define UTILITIES_REGISTERS_H_

#include "Typedefs.h"

/* ====================================
 * 	DIO Registers
 * ====================================
 */
/* DDR Register */
#define DDRA   (*(vu8*)0x3A)
#define DDRB   (*(vu8*)0x37)
#define DDRC   (*(vu8*)0x34)
#define DDRD   (*(vu8*)0x31)


/* PORT Register */
#define PORTA  (*(vu8*)0x3B)
#define PORTB  (*(vu8*)0x38)
#define PORTC  (*(vu8*)0x35)
#define PORTD  (*(vu8*)0x32)

/* PIN Register */
#define PINA   (*(vu8*)0x39)
#define PINB   (*(vu8*)0x36)
#define PINC   (*(vu8*)0x33)
#define PIND   (*(vu8*)0x30)

/* ====================================
 * 	External Interrupt Registers
 * ====================================
 */

/* SREG Register */
#define SREG   (*(vu8*)0x5F)

/* SREG Pins */
#define	C	0u
#define Z	1u
#define N	2u
#define V	3u
#define S	4u
#define H	5u
#define T	6u
#define I	7u

/* GICR Register */
#define GICR   (*(vu8*)0x5B)

/* GICR Pins  */
#define IVCE   0u
#define IVSEL  1u
#define INT2   5u
#define INT0   6u
#define INT1   7u

/* MCUCR Register */
#define MCUCR   (*(vu8*)0x55)

/* MCUCR Pins   */
#define ISC00   0u
#define ISC01	1u
#define ISC10 	2u
#define ISC11	3u
#define SM0		4u
#define SM1		5u
#define SM2		6u
#define SE		7u


/* ====================================
 * 	Timer Registers
 * ====================================
 */

/* TIMER0/TIMER1/TIMER2 TIMSK Register */
#define	TIMER0_TIMSK_TOIE0	0u
#define TIMER0_TIMSK_OCIE0	1u
#define TIMER1_TIMSK_TOIE1	2u
#define TIMER1_TIMSK_OCIE1B	3u
#define TIMER1_TIMSK_OCIE1A	4u
#define TIMER1_TIMSK_TICIE1	5u
#define TIMER2_TIMSK_TOIE2	6u
#define TIMER2_TIMSK_OCIE2	7u

/* TIMER0/TIMER1/TIMER2 TIFR Register */
#define TIMER0_TIFR_TOV0	0u
#define TIMER0_TIFR_OCF0	1u
#define TIMER1_TIFR_TOV1	2u
#define TIMER1_TIFR_OCF1B	3u
#define TIMER1_TIFR_OCF1A	4u
#define TIMER1_TIFR_ICF1	5u
#define TIMER2_TIFR_TOV2	6u
#define TIMER2_TIFR_OCF2	7u


/* TIMER 0 (8-bit) */
#define	TIMER0_OCR0		(*(vu8*)0x5c)
#define	TIMER0_TCCR0	(*(vu8*)0x53)
#define TIMER0_TCNT0	(*(vu8*)0x52)


/* TCCR0 */
#define CS00	0u
#define CS01	1u
#define CS02	2u
#define WGM01	3u
#define COM00	4u
#define COM01	5u
#define WGM00	6u
#define FOC0	7u

/* TIMER 1 (16-bit) */
/* I will postpone it for now ! 3shan 3ayez el awal agarab ay 7agah tshta8al b TIMER0 aw TIMER2*/
/* w kman 3shan da 16-bit fh7tag asta5dem vu16 msh vu8 ma3 el TCNT , msh 3aref b2a ma3 eih kman */
#define TIMER1_TCNT1	(*(vu16*)0x4C)
#define TIMER1_TCCR1A	(*(vu8*)0x4F)
#define TIMER1_TCCR1B	(*(vu8*)0x4E)
#define TIMER1_TIFR		(*(vu8*)0x58)
#define TIMER1_TIMSK	(*(vu8*)0x59)
#define TIMER1_OCR1AH	(*(vu8*)0x4B)
#define TIMER1_OCR1AL	(*(vu8*)0x4A)
#define TIMER1_OCR1BH	(*(vu8*)0x49)
#define TIMER1_OCR1BL	(*(vu8*)0x48)
#define TIMER1_ICR1H	(*(vu8*)0x47)
#define TIMER1_ICR1L	(*(vu8*)0x46)

/* TCCR1A Register */
#define	WGM10	0u
#define WGM11	1u
#define FOC1B	2u
#define FOC1A	3u
#define COM1B0	4u
#define COM1B1	5u
#define COM1A0	6u
#define COM1A1	7u

/* TCCR1B Register */
#define CS10	0u
#define CS11	1u
#define CS12	2u
#define WGM12	3u
#define WGM13	4u
#define ICESI	6u
#define ICNCI	7u



/* TIMER 2 (8-bit) */
#define	TIMER2_TCCR2	(*(vu8*)0x45)
#define TIMER2_TCNT2	(*(vu8*)0x44)
#define TIMER2_OCR2	(*(vu8*)0x43)


/* TCCR2 Register */
#define CS20	0u
#define CS21	1u
#define CS22	2u
#define WGM21	3u
#define COM20	4u
#define COM21	5u
#define WGM20	6u
#define FOC2	7u


/* -------------- Interrupt Registers for Timers --------------------- */

/* TIMSK Register */
#define TIMSK	(*(vu8*)0x59)

#define TOIE0	0u
#define OCIE0	1u
#define TOIE1	2u
#define OCIE1B	3u
#define OCIE1A	4u
#define TICIE1	5u
#define TOIE2	6u
#define OCIE2	7u


/* TIFR Register */
#define TIFR	(*(vu8*)0x58)

#define TOV0	0u
#define OCF0	1u
#define TOV1	2u
#define OCF1B	3u
#define OCF1A	4u
#define ICF1	5u
#define TOV2	6u
#define OCF2	7u


















#endif /* UTILITIES_REGISTERS_H_ */
