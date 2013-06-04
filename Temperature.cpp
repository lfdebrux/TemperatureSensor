/*
	Temperature.cpp - Library for reading temperature sensor of cc430f5137
	Based on Energia wiring_analog.c
	Created by Laurence de Bruxelles, 2013
	Released under WTFPL
*/

#include "Energia.h"
#include "Temperature.h"

Temperature::Temperature() : gain(40), offset(83591)
{
	// make reading to allow ADC to settle
	readSensor();
}

// TODO
// void Temperature::calibrate()
// {
// 	// Use internal calibration points to derive gain and offset.
// 	// Accuracy seems to be dubious.
// }

int16_t Temperature::read()
{
	temp = ((uint32_t)readTemp()*gain - offset) >> 8;
	return temp;
}

uint16_t Temperature::readSensor()
{
	ADC12CTL0 &= ~ADC12ENC;
	ADC12CTL1 = ADC12SSEL_0 | ADC12DIV_4 | ADC12SHP;
	ADC12CTL2 |= ADC12RES_2; // 12-bit reading

	while(REFCTL0 & REFGENBUSY); // wait until free
	REFCTL0 |= REFON | REFVSEL_0; // use internal 1V5 ref
	ADC12MCTL0 = TEMPSENSOR | ADC12SREF_1;
	ADC12CTL0 = ADC12ON | ADC12SHT0_4; // sample time 64 * clock

	// setup interrupts
	ADC12IFG = 0;
	ADC12IE |= ADC12IE0;

	__delay_cycles(128);
	ADC12CTL0 |= ADC12ENC | ADC12SC;
	while (ADC12CTL1 & ADC12BUSY) {
		// wait in LPM0 until read & converted
		__bis_SR_register(CPUOFF + GIE);
	}

	// after return to active mode from ISR

	// power off modules
	ADC12CTL0 &= ~ADC12ON;
	REFCTL0 &= ~REFON;
}

__attribute__((interupt(ADC12_VECTOR)))
void Temperature::ADC12_ISR()
{
		switch(ADC12IV,36) {
		case 0: break; // No interrupt
		case 2: break; // conversion result overflow
		case 4: break; // conversion time overflow
		case 6:
				// reading ready, return to active mode
				 __bic_SR_register_on_exit(CPUOFF);
				 break; // Clear CPUOFF bit from 0(SR)                         
		default: break;
	}

	ADC12IFG = 0; // Clear Flags
}