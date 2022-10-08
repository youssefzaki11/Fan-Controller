/*************************************************************************************************************
 * Module: ADC
 * File Name: adc.c
 * Description: ADC Driver source file
 * Author: Youssef Ahmed Zaki
 ************************************************************************************************************/
#include "common_macros.h"
#include <avr/io.h>
#include "adc.h"

/*
 * DESCRIPTION:
 * This function is to initialize the ADC channels for conversion
 */

 void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	/*
	 * ADMUX Register Configuration:
	 * 1. Using INTERNAL = 2.56v as a reference voltage -> REFS0 = 1, REFS1 = 1
	 * 2.  ADLAR = 0 right adjusted
	 * 3. MUX4:0 = 00010 to choose channel 2 as initialization
	 */
	ADMUX = (1<<REFS0) | (1<<REFS1) | (1<<1);

	/*
	 * ADCSRA Register Configuration:
	 * ADEN = 1 -> Enable the ADC
	 * ADPS2:0 = 011 to choose ADC_Clock = F_CPU/8 = 1Mhz/8 = 125Khz --> ADC must operate in range 50-200Khz
	 * ADC frequency range = 50kHZ : 200kHZ
	 */
	ADCSRA = (1<<ADEN) | (1<<ADPS1) | (1<<ADPS0);
}

/*
 * DESCRIPTION:
 * The Function responsible for read analog data from a certain ADC channel and convert it to digital using
 * the ADC driver.
 */

uint16 ADC_readChannel(uint8 channel_num)
{
	channel_num &= 0x07;             /* Input channel must be from 0 ---> 7 */
	ADMUX &= 0xE0;                  /* clear first 5 bits in ADMUX Register to set the new channel */
	ADMUX |= channel_num;      /* Choose the correct channel by setting the channel number in MUX4:0 bits */
	SET_BIT(ADCSRA,ADSC);            /* Start conversion write '1' to ADSC */
	while(BIT_IS_SET(ADCSRA,ADIF));  /* wait for the ADIF becomes 1 when the conversion is complete */
	SET_BIT(ADCSRA,ADIF);            /* Clear Bit by write logic one to it */
	return ADC;                      /* Read the ADC value from the Data register */
}
