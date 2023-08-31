/*************************************************************************************************************
 * [File]: FanControllerApplication.c
 * [Date]: 19/8/2023
 * [Objective]: Application for Control the fan speed based on the LM35 Temperature Sensor Reading.
 * [Drivers]: GPIO - Timer0 PWM Mode - ADC - DC_Motor - LM35 Temperature Sensor - LCD
 * [Author]: Youssef Ahmed Zaki
 *************************************************************************************************************/
#include <avr/io.h>
#include <util/delay.h>

/* MCAL Layer */
#include "GPIO.h"
#include "TIMER0.h"
#include "ADC.h"

/* HAL Layer */
#include "LCD.h"
#include "LM35.h"
#include "DC_Motor.h"

int main (void)
{
	uint8 Temperature;

	/*
	 * Timer0 Driver Configuration:
	 * 1. Let the Register TCNT0 = 0 as an initial value of the timer.
	 * 2. The compare value is based on the required input duty cycle.
	 * 3. Let the Timer0 work based on Fast PWM Mode.
	 * 4. Pre_scaler = F_CPU/8 as mentioned in the requirements to generate 500Hz Signal to control DC Motor.
	 */
	TIMER0_ConfigType Timer0_config = {0, 0, Fast_PWM_3, Prescaler_8};

	/*
	 * ADC Driver Configuration:
	 * 1. Let the voltage reference is the internal VREF reference = 2.56V
	 * 2. Activate the ADC Channel two to connect it with the temperature sensor.
	 * 3. Pre_scaler = F_CPU/8 as mentioned in the requirements.
	 * 4. Let ADC in Free Running Mode.
	 * 5. ADC is operating in polling technique as mentioned in the requirements.
	 */
	ADC_ConfigType ADC_Config = {Internal_VREF, ADC2, CLK_8, Free_Running};

	/* MCAL Drivers Initialization */
	Timer0_PWM_Mode_Init(&Timer0_config);
	ADC_Init(&ADC_Config);

	/* HAL Drivers Initialization */
	LCD_Init();
	DcMotor_Init();

	while (1)
	{
		Temperature = LM35_GetTemperature();
		LCD_DisplayStringRowColumn(0,3,"Fan is ");
		LCD_DisplayStringRowColumn(1,3,"Temp = ");

		/* Display the Temperature on the LCD Screen */
		if (Temperature >= 100)
		{
			LCD_IntegerToString(Temperature);
		}
		else
		{
			LCD_IntegerToString(Temperature);

			/* Put space in next place when the number is one, two or three digits to prevent noises on LCD */
			LCD_DisplayCharacter(' ');
		}

		/* Move cursor to this location to write the fan state (ON or OFF)*/
		LCD_MoveCursor(0, 10);

		/* Check the temperature */
		if (Temperature < 30 )
		{
			LCD_DisplayString("OFF");
			LCD_DisplayCharacter(' ');
			DcMotor_Rotate(STOP, 0);
		}
		else if (Temperature >= 30 && (Temperature < 60))
		{
			LCD_DisplayString("ON");
			LCD_DisplayCharacter(' ');
			DcMotor_Rotate(CW, 25);
		}
		else if (Temperature >= 60 && Temperature < 90)
		{
			LCD_DisplayString("ON");
			LCD_DisplayCharacter(' ');
			DcMotor_Rotate(CW, 50);
		}
		else if (Temperature >= 90 && Temperature < 120)
		{
			LCD_DisplayString("ON");
			LCD_DisplayCharacter(' ');
			DcMotor_Rotate(CW, 75);
		}
		else if (Temperature >= 120)
		{
			LCD_DisplayString("ON");
			LCD_DisplayCharacter(' ');
			DcMotor_Rotate(CW, 100);
		}
	}
}
