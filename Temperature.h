/*
	Temperature.h - Library for reading temperature sensor of cc430f5137
	Created by Laurence de Bruxelles, 2013
	Released under WTFPL
*/

#ifndef Temperature_h
#define Temperature_h

#include "Energia.h"

// need cc430f5137 with 12-bit ADC
#if defined(__MSP430_HAS_ADC12_PLUS__)

class Temperature
{
	public:
		Temperature();
		int16_t read();
	private:
		int16_t temp;
		int8_t gain;
		int32_t offset;
		// void calibrate();
		uint16_t readSensor();
		void ADC12_ISR(void);
};

#endif

#endif