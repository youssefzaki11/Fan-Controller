 /************************************************************************************************************
 * Module: ADC
 * File Name: adc.h
 * Description: AVR ADC driver Header File
 * Author: Youssef Ahmed Zaki
 *************************************************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define ADC_BITS_RESULTION 1023
#define MAX_VREF_VOLTAGE 2.56

typedef enum
{
	AREF,AVCC,RESERVED,INTERNAL

}ADC_ReferenceVoltage;

typedef enum
{
	PRESCALER_2,PRESCALER_22,PRESCALER_4,PRESCALER_8,PRECALER_16,PRESCALER_32,PRESCALER_64,PRESCALER_128

}ADC_Prescaler;

 typedef struct{
	 ADC_ReferenceVoltage ref_volt;
	 ADC_Prescaler prescaler;
 }ADC_ConfigType;


 /*******************************************************************************
  *                              Functions Prototypes                           *
  *******************************************************************************/

/*
 * DESCRIPTION:
 * This function is to initialize the ADC channels for conversion
 */

 void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * DESCRIPTION:
 * The Function responsible for read analog data from a certain ADC channel and convert it to digital using
 * the ADC driver.
 */

uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
