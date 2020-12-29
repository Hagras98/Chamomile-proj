/*
 * stepper.c
 *
 * Created: 07-Nov-20 5:21:41 AM
 *  Author: khaled
 */ 


#include "stepper.h"
u16 loops1;
u16 loops2;
u16 loops3;
void stepper_init(stepperPins* pins)
{
	directionPin(pins->port,OUTPUT,pins->pulse);
	directionPin(pins->port,OUTPUT,pins->direction);
}

/*
void moveCW(stepperPins* pins,u8 i)
{
	if (i%8==0)
	{
		writePin(pins->port,LOW,pins->aPos);
		writePin(pins->port,HIGH,pins->aNeg);
		writePin(pins->port,LOW,pins->bPos);
		writePin(pins->port,HIGH,pins->bNeg);
	}
	else if (i%8==1)
	{
		writePin(pins->port,LOW,pins->aPos);
		writePin(pins->port,HIGH,pins->aNeg);
		writePin(pins->port,LOW,pins->bPos);
		writePin(pins->port,LOW,pins->bNeg);
	}
	else if (i%8==2)
	{
		writePin(pins->port,LOW,pins->aPos);
		writePin(pins->port,HIGH,pins->aNeg);
		writePin(pins->port,HIGH,pins->bPos);
		writePin(pins->port,LOW,pins->bNeg);
	}
	else if (i%8==3)
	{
		writePin(pins->port,LOW,pins->aPos);
		writePin(pins->port,LOW,pins->aNeg);
		writePin(pins->port,HIGH,pins->bPos);
		writePin(pins->port,LOW,pins->bNeg);
	}
	else if (i%8==4)
	{
		writePin(pins->port,HIGH,pins->aPos);
		writePin(pins->port,LOW,pins->aNeg);
		writePin(pins->port,HIGH,pins->bPos);
		writePin(pins->port,LOW,pins->bNeg);
	}
	else if (i%8==5)
	{
		writePin(pins->port,HIGH,pins->aPos);
		writePin(pins->port,LOW,pins->aNeg);
		writePin(pins->port,LOW,pins->bPos);
		writePin(pins->port,LOW,pins->bNeg);
	}
	else if (i%8==6)
	{
		writePin(pins->port,HIGH,pins->aPos);
		writePin(pins->port,LOW,pins->aNeg);
		writePin(pins->port,LOW,pins->bPos);
		writePin(pins->port,HIGH,pins->bNeg);
	}	
	else if (i%8==7)
	{
		writePin(pins->port,LOW,pins->aPos);
		writePin(pins->port,LOW,pins->aNeg);
		writePin(pins->port,LOW,pins->bPos);
		writePin(pins->port,HIGH,pins->bNeg);
	}
}

void moveCCW(stepperPins* pins,u8 i)
{
	if (i%8==0)
	{
		writePin(pins->port,HIGH,pins->aPos);
		writePin(pins->port,LOW,pins->aNeg);
		writePin(pins->port,LOW,pins->bPos);
		writePin(pins->port,HIGH,pins->bNeg);
	}
	else if (i%8==1)
	{
		writePin(pins->port,HIGH,pins->aPos);
		writePin(pins->port,LOW,pins->aNeg);
		writePin(pins->port,LOW,pins->bPos);
		writePin(pins->port,LOW,pins->bNeg);
	}
	else if (i%8==2)
	{
		writePin(pins->port,HIGH,pins->aPos);
		writePin(pins->port,LOW,pins->aNeg);
		writePin(pins->port,HIGH,pins->bPos);
		writePin(pins->port,LOW,pins->bNeg);
	}
	else if (i%8==3)
	{
		writePin(pins->port,LOW,pins->aPos);
		writePin(pins->port,LOW,pins->aNeg);
		writePin(pins->port,HIGH,pins->bPos);
		writePin(pins->port,LOW,pins->bNeg);
	}
	else if (i%8==4)
	{
		writePin(pins->port,LOW,pins->aPos);
		writePin(pins->port,HIGH,pins->aNeg);
		writePin(pins->port,HIGH,pins->bPos);
		writePin(pins->port,LOW,pins->bNeg);
	}
	else if (i%8==5)
	{
		writePin(pins->port,LOW,pins->aPos);
		writePin(pins->port,HIGH,pins->aNeg);
		writePin(pins->port,LOW,pins->bPos);
		writePin(pins->port,LOW,pins->bNeg);
	}
	else if (i%8==6)
	{
		writePin(pins->port,LOW,pins->aPos);
		writePin(pins->port,HIGH,pins->aNeg);
		writePin(pins->port,LOW,pins->bPos);
		writePin(pins->port,HIGH,pins->bNeg);
	}
	else if (i%8==7)
	{
		writePin(pins->port,LOW,pins->aPos);
		writePin(pins->port,LOW,pins->aNeg);
		writePin(pins->port,LOW,pins->bPos);
		writePin(pins->port,HIGH,pins->bNeg);
	}
}
*/


void move1Step(stepperPins* pins, u8 direct)
{
	writePin(pins->port,HIGH,pins->direction);
	toggle(pins->port,pins->pulse);
}

void moveDelta(stepperPins* m1, stepperPins* m2, stepperPins* m3, s16 deg1, s16 deg2, s16 deg3)
{
	deg1/=(STEP_SIZE);
	deg2/=(STEP_SIZE);
	deg3/=(STEP_SIZE);
	u16 stepCount1=0,stepCount2=0,stepCount3=0;
	TMR2Init(ON);	
	while(stepCount1<deg1||stepCount2<deg2||stepCount3<deg3)
	{
		if (loops1>=LIMIT&&stepCount1<deg1)
		{
			move1Step(m1,stepCount1);
			stepCount1++;
			loops1=0;
		}
		if (loops2>=LIMIT&&stepCount2<deg2)
		{
			move1Step(m2,stepCount2);
			stepCount2++;
			loops2=0;
		}
		if (loops3>=LIMIT&&stepCount3<deg3)
		{
			move1Step(m3,stepCount3);
			stepCount3++;
			loops3=0;
		}
	}
	TMR2Stop();
	loops1=0;
	loops2=0;
	loops3=0;
}