/*************************************************************************************************************
 * Module: LM35 Temperature Sensor
 * File Name: lm35_sensor.c
 * Description: LM35 Temperature Sensor Driver Source File
 * Author: Youssef Ahmed Zaki
 *************************************************************************************************************/
#include "lm35_sensor.h"
#include "adc.h"

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */

uint8 LM35_GetTemperature(void)
{
    uint8 temp_value = 0;
	uint16 adc_value = 0;

	/* Read ADC Channel where LM35 Temperature Sensor is Connected */
	adc_value = ADC_readChannel(SENSOR_CHANNEL_ID);

	/* Calculate the Temperature from the ADC Value */
	temp_value = (uint8)( ((uint32)adc_value*SENSOR_MAX_TEMPERATURE_VALUE*MAX_VREF_VOLTAGE)/ (SENSOR_MAX_VOLTAGE_VALUE*ADC_BITS_RESULTION) );

	return temp_value;
}

