/*******************************************************************************************************************
 * File Name: TIMER0.h
 * Date: 16/7/2023
 * Driver: ATmega32 Timer0 Driver Header File
 * Author: Youssef Zaki
 ******************************************************************************************************************/
#include "Standard_Types.h"

#ifndef TIMER0_H_
#define TIMER0_H_

/****************************************************************************************
 *                                      Types Declaration                               *
 ****************************************************************************************/

typedef enum
{
	Normal_0, PhaseCorrect_PWM_1, CTC_2, Fast_PWM_3
}WaveFormGenerationMode;

typedef enum
{
	No_Clock,
	Prescaler_1,
	Prescaler_8,
	Prescaler_64,
	Prescaler_256,
	Prescaler_1024,
	External_Clock_Falling_Edge,
	External_Clock_Rising_Edge
}TIMER0_Clock_Select;

typedef struct
{
	uint8 Initial_Value;
	uint8 Compare_Value;
	WaveFormGenerationMode Timer_Mode;
	TIMER0_Clock_Select Prescalar;
}TIMER0_ConfigType;


/****************************************************************************************
 *                                      Functions Prototypes                            *
 ****************************************************************************************/

/*
 * Description:
 * Initialization of Timer0 (Enable Timer0)
 * 1. Let the TCNT0 Register = The Start value of the timer.
 * 2. Enable FOC0 bit in the TCCR0 Register.
 * 3. Enable CS02:0 bits according to the required pre-scalar
 * 4. Configure the TCCR0 Register according to the Timer0 Mode.
 * 5. Configure the TIMSK Register (Interrupt Mask) according to Timer0 Mode.
 * 6. In CTC Mode Let OCR0 = the compare value (TOP Value)
 */
void Timer0_NonPWM_Mode_Init(const TIMER0_ConfigType* Config_Ptr);

/*
 * Description:
 * The function responsible for trigger the Timer0 with the PWM Mode.
 * 1. Let the TCNT0 Register = The Start value of the timer.
 * 2. Disable FOC0 bit in the TCCR0 Register (FOC0 = 0)
 * 3. Enable CS02:0 bits according to the required pre-scalar.
 * 4. Setup the direction for OC0 as output pin through the GPIO driver.
 * 5. Configuration the PWM Mode (Phase Correct or Fast)
 * 6. Setup the PWM mode with Non-Inverting.
 */
void Timer0_PWM_Mode_Init(const TIMER0_ConfigType* Config_Ptr);

/*
 * Description:
 * The Speed is passed to this function to calculate the duty cycle and hence get the OCR0 Value.
 */
void TIMER0_PWM_Start(uint8 Duty_Cycle);

/*
 * Description:
 * De-initialization of Timer0 (Disable)
 */
void Timer0_DeInit(void);

/*
 * Description:
 * Function to set the Call Back function address.
 */
void Timer0_SetCallBack(void(*a_ptr)(void));


#endif /* TIMER0_H_ */
