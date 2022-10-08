/************************************************************************************************************
 * Module: LM35 Temperature Sensor
 * File Name: lm35_sensor.h
 * Description: LM35 Temperature Sensor driver Header File
 * Author: Youssef Ahmed Zaki
 *************************************************************************************************************/

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "std_types.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define SENSOR_CHANNEL_ID                   2
#define SENSOR_MAX_VOLTAGE_VALUE            1.5
#define SENSOR_MAX_TEMPERATURE_VALUE        150


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/


/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */

uint8 LM35_GetTemperature(void);


#endif /* LM35_SENSOR_H_ */
