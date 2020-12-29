/*
 * GPIO.c
 *
 * Created: 31-Aug-20 2:45:26 PM
 *  Author: Khaled Hagras
 */ 
#include "GPIO.h"
void directionPin(u8 port, state_t state,u8 pin)
{
	if (state==OUTPUT)
{*(DDRA-base(port))|=(1<<pin);}
	else if (state==INPUT)
{*(DDRA-base(port))&=~(1<<pin);}
}
void writePin(u8 port, power_t power, u8 pin)
{
	if (power==HIGH)
{*(PORTA-base(port))|=(1<<pin);}
	else if (power==LOW)
{*(PORTA-base(port))&=~(1<<pin);}
}
power_t readPin (u8 port,u8 pin)
{
	u8 val=0;
	val=(*(PINA-base(port))>>pin)&1;
	return val;
}
void directionPort(u8 port, state_t state)
{
	if (state==OUTPUT)
{*(DDRA-base(port))=PORTOUTPUT;}
	else if (state==INPUT)
{*(DDRA-base(port))=PORTINPUT;}
}

void writePort (u8 port, u8 power)
{
	*(PORTA-base(port))=power;
}

void toggle(u8 port,u8 pin)
{*(PORTA-base(port))^=(1<<pin);}