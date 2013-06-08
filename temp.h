/*
	temp.h - Library to read internal temperature sensor
	of cc430f5137 in the Kicksat Sprite. Based on Energia wiring_analog.c
	Written by Laurence de Bruxelles, June 2013
	Released into the public domain
*/

#ifndef temp_h
#define temp_h

#include "Energia.h"

// need cc430f5137 with 12-bit ADC
#if defined(__MSP430_HAS_ADC12_PLUS__)

#ifdef __cplusplus
extern "C" {
#endif

// global variables
extern int8_t gain;
extern int32_t offset;

// visible interface
int16_t temp;
int16_t readTemp(void);
void calibrateTemp(void);

#ifdef __cplusplus
}
#endif

#endif
#endif