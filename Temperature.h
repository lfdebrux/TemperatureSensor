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

// these defines contradict Energia.h so as
// to use REF module rather than legacy bits
#define INTERNAL1V5 ADC12SREF_1 + REFON + REFVSEL_0
#define INTERNAL2V5 ADC12SREF_1 + REFON + REFVSEL_2

#define REF_MASK 0x31
#define REFV_MASK 0x70

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