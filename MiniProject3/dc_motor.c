/*************************************************************************************************************
 * Module: DC Motor
 * File Name: dc_motor.c
 * Description: DC Motor Driver Source File
 * Author: Youssef Ahmed Zaki
 *************************************************************************************************************/
#include "gpio.h"
#include "dc_motor.h"
#include "pwm.h"

/*
 * DESCRIPTION:
 * The Function responsible for setup the direction for the two motor pins through the GPIO driver.
 * Stop at the DC-Motor at the beginning through the GPIO driver.
 */

void DcMotor_Init(void)
{
	/* let the first 2 pins as output pins at PORTB */

	GPIO_setupPinDirection(PORTB_ID,PIN0_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN1_ID,PIN_OUTPUT);

	 /* Stop the Motor at the beginning */

	GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW);
	GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW);
}

/*
 * DESCRIPTION:
 * The function responsible for rotate the DC Motor CW/ or A-CW or stop the motor based on the state
 * input state value.
 * Send the required duty cycle to the PWM driver based on the required speed value.
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	if (state == STOP)
	{
		/* STOP MODE: A = LOW, B = LOW */
		GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW);
		GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW);
	}
	else if (state == CW)
	{
		/* CLOCk WISE MODE: A = LOW, B = HIGH */
		GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_LOW);
		GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_HIGH);
	}
	else if (state == A_CW)
	{
		/* Anti-CLOCk WISE MODE: A = HIGH, B = LOW */
		GPIO_writePin(PORTB_ID,PIN0_ID,LOGIC_HIGH);
		GPIO_writePin(PORTB_ID,PIN1_ID,LOGIC_LOW);
	}
	PWM_Timer0_Start(speed);
}
