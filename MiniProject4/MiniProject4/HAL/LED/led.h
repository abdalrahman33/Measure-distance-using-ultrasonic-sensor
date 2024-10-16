/*
 * led.h
 *
 *  Created on: Oct 9, 2024
 *      Author: Abdelrahman
 */
#ifndef led_h
#define led_h

#include "../../Libraries/std_types.h"
#include "../../MCAL/GPIO/gpio.h"

#define LOGIC POSTIVE_LOGIC

#define red 0
#define green 1
#define blue 2

#define Red_Led_Port PORTC_ID
#define Green_Led_Port PORTC_ID
#define Blue_Led_Port PORTC_ID


#define Red_Led_Pin PIN0_ID
#define Green_Led_Pin PIN1_ID
#define Blue_Led_Pin PIN2_ID

void LEDS_init(void);
void LED_ON(uint8 LED_ID);
void LED_OFF(uint8 LED_ID);



#endif
