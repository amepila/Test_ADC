/*
 * ADC.c
 *
 *  Created on: Oct 12, 2017
 *      Author: Andres Hernandez
 */

#include "ADC.h"

static void ADC_enable(ADC_ChannelType channel){
	switch(channel){
	case ADC_0:
        SIM->SCGC6 |= SIM_SCGC6_ADC0_MASK;
        break;
	case ADC_1:
		SIM->SCGC3 |= SIM_SCGC3_ADC1_MASK;
		break;
	default:
		break;
	}
}

static void ADC_clkDivide(ADC_ChannelType channel, ADC_ClkDivType clkdivide){
	switch(clkdivide){
	case ADC_CLK1:
		if(ADC_0 == channel){ADC0->CFG1 |= ADC_CFG1_ADIV(0);}
		if(ADC_1 == channel){ADC1->CFG1 |= ADC_CFG1_ADIV(0);}
		break;
	case ADC_CLK2:
		if(ADC_0 == channel){ADC0->CFG1 |= ADC_CFG1_ADIV(1);}
		if(ADC_1 == channel){ADC1->CFG1 |= ADC_CFG1_ADIV(1);}
		break;
	case ADC_CLK4:
		if(ADC_0 == channel){ADC0->CFG1 |= ADC_CFG1_ADIV(2);}
		if(ADC_1 == channel){ADC1->CFG1 |= ADC_CFG1_ADIV(2);}
		break;
	case ADC_CLK8:
		if(ADC_0 == channel){ADC0->CFG1 |= ADC_CFG1_ADIV(3);}
		if(ADC_1 == channel){ADC1->CFG1 |= ADC_CFG1_ADIV(3);}
		break;
	default:
		break;
	}
}

static void ADC_sampleTime(ADC_ChannelType channel, ADC_SampleTimeType sample){
	switch(channel){
	case ADC_0:
		if(ADC_SHORT == sample){ADC0->CFG1 &= ~(ADC_CFG1_ADLSMP_MASK);}
		if(ADC_LONG == sample){ADC0->CFG1 |= ADC_CFG1_ADLSMP_MASK;}
		break;
	case ADC_1:
		if(ADC_SHORT == sample){ADC1->CFG1 &= ~(ADC_CFG1_ADLSMP_MASK);}
		if(ADC_LONG == sample){ADC1->CFG1 |= ADC_CFG1_ADLSMP_MASK;}
		break;
	default:
		break;
	}
}

static void ADC_converstionMode(ADC_ChannelType channel, ADC_ConverModeType mode){
	switch(mode){
	case ADC_CONVER_8B:
		if(ADC_0 == channel){ADC0->CFG1 |= ADC_CFG1_MODE(0);}
		if(ADC_1 == channel){ADC1->CFG1 |= ADC_CFG1_MODE(0);}
		break;
	case ADC_CONVER_10B:
		if(ADC_0 == channel){ADC0->CFG1 |= ADC_CFG1_MODE(1);}
		if(ADC_1 == channel){ADC1->CFG1 |= ADC_CFG1_MODE(1);}
		break;
	case ADC_CONVER_12B:
		if(ADC_0 == channel){ADC0->CFG1 |= ADC_CFG1_MODE(2);}
		if(ADC_1 == channel){ADC1->CFG1 |= ADC_CFG1_MODE(2);}
		break;
	case ADC_CONVER_16B:
		if(ADC_0 == channel){ADC0->CFG1 |= ADC_CFG1_MODE(3);}
		if(ADC_1 == channel){ADC1->CFG1 |= ADC_CFG1_MODE(3);}
		break;
	default:
		break;
	}
}

static void ADC_inputClk(ADC_ChannelType channel, ADC_InputClkType clk){
	switch(clk){
	case ADC_BUS_CLK:
		if(ADC_0 == channel){ADC0->CFG1 |= ADC_CFG1_ADICLK(0);}
		if(ADC_1 == channel){ADC1->CFG1 |= ADC_CFG1_ADICLK(0);}
		break;
	case ADC_ALT_CLK2:
		if(ADC_0 == channel){ADC0->CFG1 |= ADC_CFG1_ADICLK(1);}
		if(ADC_1 == channel){ADC1->CFG1 |= ADC_CFG1_ADICLK(1);}
		break;
	case ADC_ATL_CLK1:
		if(ADC_0 == channel){ADC0->CFG1 |= ADC_CFG1_ADICLK(2);}
		if(ADC_1 == channel){ADC1->CFG1 |= ADC_CFG1_ADICLK(2);}
		break;
	case ADC_ADACK:
		if(ADC_0 == channel){ADC0->CFG1 |= ADC_CFG1_ADICLK(3);}
		if(ADC_1 == channel){ADC1->CFG1 |= ADC_CFG1_ADICLK(3);}
		break;
	default:
		break;
	}
}

static void ADC_hardwareAverage(ADC_ChannelType channel, ADC_HwAverageType hwAverage){
	switch(hwAverage){
	case ADC_HW_DISABLE:
		if(ADC_0 == channel){ADC0->SC3 &= ~(ADC_SC3_AVGE_MASK);}
		if(ADC_1 == channel){ADC1->SC3 &= ~(ADC_SC3_AVGE_MASK);}
		break;
	case ADC_HW_ENABLE:
		if(ADC_0 == channel){ADC0->SC3 |= ADC_SC3_AVGE_MASK;}
		if(ADC_1 == channel){ADC1->SC3 |= ADC_SC3_AVGE_MASK;}
		break;
	default:
		break;
	}
}

static void ADC_hardwareSelect(ADC_ChannelType channel, ADC_HwSelectType hwSelect){

}

static void ADC_inpuChannel(ADC_ChannelType channel, ADC_InputChannelType input){

}


void ADC_calculateResult(ADC_ChannelType channel){

}

void ADC_init(const ADC_ConfigType* ADC_Config){

}
