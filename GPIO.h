/*
 * GPIO.h
 *
 * Created: 31-Aug-20 2:31:49 PM
 *  Author: Khaled Hagras
 */ 


#ifndef GPIO_H_
#define GPIO_H_
#include "types.h"
#include "reg.h"

#define base(P) (u8)((P-'A')*3)
#define PORTOUTPUT (u8)0xFF
#define PORTINPUT (u8)0x00
typedef enum
{
	INPUT,
	OUTPUT
}state_t;

typedef enum
{
	LOW,
	HIGH
}power_t;

void directionPort(u8 port, state_t state);
void writePort (u8 port, u8 power);
void directionPin(u8 port, state_t state,u8 pin);
void writePin (u8 port, power_t power, u8 pin);
void toggle(u8 port,u8 pin);
power_t readPin (u8 port,u8 pin);
#endif /* GPIO_H_ */