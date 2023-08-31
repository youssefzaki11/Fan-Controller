/*****************************************************************************************************************
 * File Name: DC_Motor.h
 * Date: 4/8/2023
 * Driver: DC Motor Driver Header File
 * Author: Youssef Zaki
 ****************************************************************************************************************/
#include "Standard_Types.h"

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

typedef enum {
	STOP,CW,A_CW
}DcMotor_State;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * DESCRIPTION:
 * The Function responsible for setup the direction for the two motor pins through the GPIO driver.
 * Stop at the DC-Motor at the beginning through the GPIO driver.
 */
void DcMotor_Init(void);

/*
 * DESCRIPTION:
 * The function responsible for rotate the DC Motor CW/ or A-CW or stop the motor based on the state input
 * state value.
 * Send the required duty cycle to the PWM driver based on the required speed value.
 */
void DcMotor_Rotate(DcMotor_State state, uint8 speed);

#endif /* DC_MOTOR_H_ */
