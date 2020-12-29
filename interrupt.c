/*
 * interrupt.c
 *
 * Created: 20-Sep-20 2:25:17 PM
 *  Author: khaled
 */ 
#include "interrupt.h"
#include "reg.h"
void interruptsInit()
{
	*SREG|=1<<7;
}
void INT0_init(u8 edge)
{
	*MCUCR&= ~3;
	*MCUCR|= edge;
	*GICR|=1<<INT0_ENABLE;
}
void INT1_init(u8 edge)
{
	*MCUCR&= ~(3<<2);
	*MCUCR|= (edge<<2);
	*GICR|=1<<INT1_ENABLE;
}
void INT2_init(u8 edge)
{
	edge-=2;
	if (edge)
	{
		*MCUCSR&= ~(1<<6);
	}
	else
	{
		*MCUCSR|= (1<<6);
	}
	*GICR|=1<<INT2_ENABLE;
}