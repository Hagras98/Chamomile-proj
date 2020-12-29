/*
 * interrupt.h
 *
 * Created: 15-Sep-20 1:25:36 PM
 *  Author: khaled
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_
#include "reg.h"

#define LOW_LEVEL (u8)0x00
#define ANY_CHANGE (u8)0x01
#define FALLING_EDGE (u8)0x02
#define RISING_EDGE (u8)0x03
#define INT1_ENABLE 7
#define INT0_ENABLE 6
#define INT2_ENABLE 5


#define ISR(vector, ...) \
void vector(void) __attribute__ ((signal,used,externally_visible)) __VA_ARGS__;\
void vector(void)

void interruptsInit(); //Enable All Interrupts
void INT0_init(u8 edge);
void INT1_init(u8 edge);
void INT2_init(u8 edge);



/*Interrupts Vector Table*/

#define INT0 __vector_1 //External Interrupt Request 0
#define INT1 __vector_2 //External Interrupt Request 1
#define INT2 __vector_3 //External Interrupt Request 2
#define TIMER2_COMP __vector_4 //Timer/Counter2 Compare Match
#define TIMER2_OVF __vector_5 //Timer/Counter2 Overflow
#define TIMER1_CAPT __vector_6 //Timer/Counter1 Capture Event
#define TIMER1_COMPA __vector_7 //Timer/Counter1 Compare Match A
#define TIMER1_COMPB __vector_8 //Timer/Counter1 Compare Match B
#define TIMER1_OVF __vector_9 //Timer/Counter1 Overflow
#define TIMER0_COMP __vector_10 //Timer/Counter0 Compare Match
#define TIMER0_OVF __vector_11 //Timer/Counter0 Overflow
#define SPI_STC __vector_12 //SPI Serial Transfer Complete
#define USART_RXC __vector_13 //USART, Rx Complete
#define USART_UDRE __vector_14 //USART Data Register Empty
#define USART_TXC __vector_15 //USART, Tx Complete
#define ADC __vector_16 //ADC Conversion Complete
#define EE_RDY __vector_17 //EEPROM Ready
#define ANA_COMP __vector_18 //Analog Comparator
#define TWI __vector_19 //Two-wire Serial Interface
#define SPM_RDY __vector_20 //Store Program Memory Ready


#endif /* INTERRUPT_H_ */