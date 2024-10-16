/*
 * ultrasonic.h
 *
 *  Created on: Oct 15, 2024
 *      Author: Abdelrahman
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "../../Libraries/std_types.h"
#include "../../MCAL/GPIO/gpio.h"

#define ULTRASONIC_TRIGGER_PORT PORTD_ID
#define ULTRASONIC_TRIGGER_PIN PIN7_ID

void Ultrasonic_init(void);
uint16 Ultrasonic_readDistance(void);
void ULTRASONIC_edgeProcessing(void);


#endif
