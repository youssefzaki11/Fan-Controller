/*************************************************************************************************************
 * Module: DC Motor
 * File Name: dc_motor.c
 * Description: Fan Controller Project main file
 * Author: Youssef Ahmed Zaki
 *************************************************************************************************************/
#include <avr/io.h>
#include "gpio.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "adc.h"
#include "dc_motor.h"

int main(void)
{
	uint8 temp_value;

	/**************************************************************************************************************************
	 *                                                 Drivers Initialization                                                 *
	 **************************************************************************************************************************/
	/* Initialize the LCD */
	LCD_init();

	/* Initialize the ADC */
	ADC_ConfigType config = {INTERNAL,PRESCALER_8};
	ADC_init(&config);

	/* Initialize the DC Motor */
	DcMotor_Init();

	/**************************************************************************************************************************
	 *                  Display the Fan State on LCD and Configure its Speed & Direction in depend of Temperature             *
	 **************************************************************************************************************************/
	while (1)
	{
		temp_value = LM35_GetTemperature();   /* temperature value calculated from the temperature sensor */

		LCD_displayStringRowColumn(0,3,"Fan is ");
		LCD_displayStringRowColumn(1,3,"Temp is ");

		if (temp_value >= 100)
		{
			LCD_intgerToString(temp_value);
		}
		else
		{
			LCD_intgerToString(temp_value);

			/* if the digital value is two or one, so we print space after them */
			LCD_displayCharacter(' ');
		}

		LCD_moveCursor(0,10);

		if (temp_value < 30)
		{
			LCD_displayString("OFF");
			LCD_displayCharacter(' ');
			DcMotor_Rotate(STOP,0);
		}
		else if (temp_value >= 30 && temp_value < 60)
		{
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW,25);
		}
		else if (temp_value >= 60 && temp_value < 90)
		{
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW,50);
		}
		else if (temp_value >= 90 && temp_value < 120)
		{
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW,75);
		}
		else if (temp_value >= 120)
		{
			LCD_displayString("ON");
			LCD_displayCharacter(' ');
			DcMotor_Rotate(CW,100);
		}
	}

	return 0;
}
