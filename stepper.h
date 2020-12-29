/*
 * stepper.h
 *
 * Created: 07-Nov-20 5:28:44 AM
 *  Author: khaled
 */ 


#ifndef STEPPER_H_
#define STEPPER_H_
#include "reg.h"
#include "GPIO.h"
#include "timer2.h"
#include "interrupt.h"
#include "tiny-json.h"
#include <util/delay.h>

#define LIMIT (F_CPU*WIDTH)/255
#define WIDTH (3125/20000000)
#define CW HIGH
#define CCW LOW
#define STEP_SIZE 0.1125

typedef struct{
	u8 port;
	u8 pulse;
	u8 direction;
	}stepperPins;
	
void stepper_init(stepperPins* pins);
void moveDelta(stepperPins* m1, stepperPins* m2, stepperPins* m3, s16 deg1, s16 deg2, s16 deg3);
void move1Step(stepperPins* pins, u8 direct);







#endif /* STEPPER_H_ */