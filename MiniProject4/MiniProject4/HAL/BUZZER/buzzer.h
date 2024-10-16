/*
 * buzzer.h
 *
 *  Created on: Oct 9, 2024
 *      Author: Abdelrahman
 */

#ifndef buzzer_h_
#define buzzer_h_

#include "../../Libraries/std_types.h"
#include "../../MCAL/GPIO/gpio.h"

#define BUZZER_PORT PORTC_ID
#define BUZZER_PIN PIN5_ID

void Buzzer_init(void);
void Buzzer_on(void);
void Buzzer_off(void);


#endif
