/*
 * APP.c
 *
 *  Created on: Oct 15, 2024
 *      Author: Abdelrahman
 */
#include "../HAL/LCD/lcd.h"
#include "../HAL/BUZZER/buzzer.h"
#include "../HAL/LED/led.h"
#include "../HAL/ULTRASONIC/ultrasonic.h"
#include "util/delay.h"
int main()
{
	uint8 distance = 0;

	LCD_init();
	Ultrasonic_init();
	Buzzer_init();
	LEDS_init();

	LCD_displayString("distance=   cm");

	while(1)
	{
		distance = Ultrasonic_readDistance();

		LCD_moveCursor(0,9);
		LCD_intgerToString(distance);

		if(distance > 20)
		{
			Buzzer_off();
			LED_OFF(red);
			LED_OFF(green);
			LED_OFF(blue);

			if(distance < 100)
			{
				LCD_moveCursor(0,11);
				LCD_displayString(" ");
			}

		}
		else if(distance <=20 && distance>=16)
		{
			Buzzer_off();
			LED_ON(red);
			LED_OFF(green);
			LED_OFF(blue);

			LCD_moveCursor(0,11);
			LCD_displayString(" ");

		}
		else if(distance <=15 && distance>=11)
		{
			Buzzer_off();
			LED_ON(red);
			LED_ON(green);
			LED_OFF(blue);

			LCD_moveCursor(0,11);
			LCD_displayString(" ");

		}
		else if(distance <=10 && distance>=6)
		{
			Buzzer_off();
			LED_ON(red);
			LED_ON(green);
			LED_ON(blue);

			if(distance >= 10)
			{
				LCD_moveCursor(0,11);
				LCD_displayString(" ");
			}
			else
			{
				LCD_moveCursor(0,10);
				LCD_displayString("  ");
				LCD_displayStringRowColumn(1,0,"          ");/*to clear stop*/
			}
		}
		else if(distance <= 5)
		{
			LCD_moveCursor(0,10);
			LCD_displayString("  ");
			LCD_displayStringRowColumn(1,6,"STOP");

			Buzzer_on();
			LED_ON(red);
			LED_ON(green);
			LED_ON(blue);
			_delay_ms(150);
			LED_OFF(red);
			LED_OFF(green);
			LED_OFF(blue);
			Buzzer_off();
			_delay_ms(150);

		}


	}
}
