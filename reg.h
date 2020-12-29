/*
 * reg.h
 *
 * Created: 30-Aug-20 3:44:35 PM
 *  Author: Khaled Hagras
 */ 


#ifndef REG_H_
#define REG_H_
#include "types.h"
#define F_CPU 8000000ul
/*GPIO*/
#define PORTA  ((volatile u8 *const)0x3B)
#define DDRA   ((volatile u8 *const)0x3A)
#define PINA   ((volatile u8 *const)0x39)
#define PORTB  ((volatile u8 *const)0x38)
#define DDRB   ((volatile u8 *const)0x37)
#define PINB   ((volatile u8 *const)0x36)
#define PORTC  ((volatile u8 *const)0x35)
#define DDRC   ((volatile u8 *const)0x34)
#define PINC   ((volatile u8 *const)0x33)
#define PORTD  ((volatile u8 *const)0x32)
#define DDRD   ((volatile u8 *const)0x31)
#define PIND   ((volatile u8 *const)0x30)
#define SFIOR  ((volatile u8 *const)0x50)

/*Interrupts*/
#define SREG   ((volatile u8 *const)0x5F)
#define GICR   ((volatile u8 *const)0x5B)
#define GIFR   ((volatile u8 *const)0x5A)
#define MCUCR  ((volatile u8 *const)0x55)
#define MCUCSR ((volatile u8 *const)0x54)

/*Timers*/
#define TIMSK  ((volatile u8 *const)0x59)
#define TIMFR  ((volatile u8 *const)0x58)
#define OCR0   ((volatile u8 *const)0x5C)
#define TCCR0  ((volatile u8 *const)0x53)
#define TCNT0  ((volatile u8 *const)0x52)
#define TCCR1A ((volatile u8 *const)0x4F)
#define TCCR1B ((volatile u8 *const)0x4E)
#define TCNT1H ((volatile u8 *const)0x4D)
#define TCNT1L ((volatile u8 *const)0x5C)
#define OCR1AH ((volatile u8 *const)0x4B)
#define OCR1AL ((volatile u8 *const)0x4A)
#define OCR1BH ((volatile u8 *const)0x49)
#define OCR1BL ((volatile u8 *const)0x48)
#define ICR1H  ((volatile u8 *const)0x47)
#define ICR1L  ((volatile u8 *const)0x46)
#define TCCR2  ((volatile u8 *const)0x45)
#define TCNT2  ((volatile u8 *const)0x44)
#define OCR2   ((volatile u8 *const)0x43)

/*UART*/
#define UDR    ((volatile u8 *const)0x2C)
#define UCSRA  ((volatile u8 *const)0x2B)
#define UCSRB  ((volatile u8 *const)0x2A)
#define UBRRL  ((volatile u8 *const)0x29)
#define UCSRC  ((volatile u8 *const)0x40)
#define UBRRH  ((volatile u8 *const)0x40)

/*SPI*/
#define SPDR   ((volatile u8 *const)0x2F)
#define SPSR   ((volatile u8 *const)0x2E)
#define SPCR   ((volatile u8 *const)0x2D)

/*TWI*/
#define TWCR   ((volatile u8 *const)0x56)
#define TWDR   ((volatile u8 *const)0x23)
#define TWAR   ((volatile u8 *const)0x22)
#define TWSR   ((volatile u8 *const)0x21)
#define TWBR   ((volatile u8 *const)0x20)

#endif /* REG_H_ */