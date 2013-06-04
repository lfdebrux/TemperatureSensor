#ifndef temp_h
#define temp_h

#include "Energia.h"

// need cc430f5137 with 12-bit ADC
#if defined(__MSP430_HAS_ADC12_PLUS__)

int16_t temp;
int8_t gain;
int32_t offset;

int16_t readTemp(void);

#endif
#endif