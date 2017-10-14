/**
 * @file    Test_ADC.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "MK64F12.h"
#include "DataTypeDefinitions.h"
#include "ADC.h"

const ADC_ConfigType ADC_Config = {ADC_0,
								{ADC_CLK8,ADC_LONG,ADC_CONVER_8B,ADC_BUS_CLK},
								ADC_HW_ENABLE,
								ADC_SAMPLE32,
								ADC_INPUT_TEMPSENSOR};


int main(void) {
	volatile uint32 resultADC;

	ADC_init(&ADC_Config);

	while(1){

		resultADC = ADC_calculateResult(&ADC_Config);

	}
    return 0 ;
}
