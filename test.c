/*
 * test.c
 *
 * Created: 07-Nov-20 6:11:21 AM
 *  Author: khaled
 */ 
#include "stepper.h"

extern volatile u16 loops1;
extern volatile u16 loops2;
extern volatile u16 loops3;
void main()
{
	stepperPins motor1;
	motor1.port ='D';
	motor1.pulse = 6;
	motor1.direction = 7;
		
	stepperPins motor2;
	motor2.port ='B';
	motor2.pulse = 6;
	motor2.direction = 7;
	
	stepperPins motor3;
	motor3.port ='A';
	motor3.pulse = 6;
	motor3.direction = 7;
		
	interruptsInit();
	stepper_init(&motor1);
	stepper_init(&motor2);
	stepper_init(&motor3);
	moveDelta(&motor1,&motor2,&motor3,60,45,30);	
}
ISR(TIMER2_OVF)
{
	++loops1;
	++loops2;
	++loops3;
}
