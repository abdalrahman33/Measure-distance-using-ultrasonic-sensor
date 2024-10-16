/*
 * ultrasonic.c
 *
 *  Created on: Oct 15, 2024
 *      Author: Abdelrahman
 */
#include "../../MCAL/ICU/icu.h"
#include "ultrasonic.h"
#include "util/delay.h"
#include "avr/io.h"

uint8 edgeCount = 0;
uint16 Timer_Value = 0;
uint16 distance = 0;

/* This is the initialization function */
void Ultrasonic_init(void)
{
	SREG |= (1<<7);
	ICU_ConfigType ICU_Configurations = {F_CPU_8, RAISING};
	ICU_init(&ICU_Configurations);
	ICU_setCallBack(ULTRASONIC_edgeProcessing);
	GPIO_setupPinDirection(ULTRASONIC_TRIGGER_PORT, ULTRASONIC_TRIGGER_PIN, PIN_OUTPUT);
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT, ULTRASONIC_TRIGGER_PIN, LOGIC_LOW);
}

/*This is the trigger function */
void Ultrasonic_Trigger(void)
{
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT, ULTRASONIC_TRIGGER_PIN, LOGIC_HIGH);
	_delay_ms(1);
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT, ULTRASONIC_TRIGGER_PIN, LOGIC_LOW);
}


/* This is the call-back function */
void ULTRASONIC_edgeProcessing(void)
{
	edgeCount++;
	if(edgeCount == 1)
	{
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(FALLING);
	}

	else if(edgeCount == 2)
	{

		Timer_Value = ICU_getInputCaptureValue();

		ICU_setEdgeDetectionType(RAISING);
		edgeCount = 0;
	}

}

uint16 Ultrasonic_readDistance(void)
{

	Ultrasonic_Trigger();
	distance = (Timer_Value / 117.6)+2;

	return distance;
}

