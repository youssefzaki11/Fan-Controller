/*************************************************************************************************************
 * Module: PWM
 * File Name: pwm.c
 * Description: PWM Driver Source File
 * Author: Youssef Ahmed Zaki
 *************************************************************************************************************/
#include <avr/io.h>
#include "gpio.h"
#include "pwm.h"
/*
 * DESCRIPTION:
 * The function responsible for trigger the Timer0 with the PWM Mode.
 * Setup the PWM mode with Non-Inverting.
 * Setup the pre-scaler with F_CPU/8.
 * Setup the compare value based on the required input duty cycle
 * Setup the direction for OC0 as output pin through the GPIO driver.
 * The generated PWM signal frequency will be 500Hz to control the DC Motor speed.
 */

/*
 * CONFIGURATION:
 * Generate a PWM signal with frequency 500Hz -> Wave Generation Mode (Fast PWM): WGM00 = 1, WGM01 = 1
 * Timer0 will be used with pre-scaler F_CPU/8 -> In TCCR0 Control Register: CS00 = 0, CS01 = 1, CS02 = 0
 * Setup the PWM mode with Non-Inverting Mode -> In TCCR0 Control Register: COM01 = 1, COM00 = 0
 */
void PWM_Timer0_Start(uint8 duty_cycle)
{
	TCNT0 = 0; /* Set Timer Initial Value to 0 */

	OCR0 = (uint16)(duty_cycle*255)/100; /* Setup the compare value based on the required input duty cycle */

	GPIO_setupPinDirection(PORTB_ID,PIN3_ID,PIN_OUTPUT); /* Setup the direction for OC0 as output pin through the GPIO driver */

	TCCR0 |= (1<<WGM00) | (1<<WGM01) | (1<<CS01) | (1<<COM01);
}
