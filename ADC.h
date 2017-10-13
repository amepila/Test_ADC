/*
 * ADC.h
 *
 *  Created on: Oct 12, 2017
 *      Author: Andres Hernandez
 */

#ifndef ADC_H_
#define ADC_H_

#include "DataTypeDefinitions.h"
#include "MK64F12.h"

/*Type to define the ADC modules*/
typedef enum{ADC_0, ADC_1}ADC_ChannelType;

/*Type to define the ADC configuration*/
typedef struct{
	ADC_ChannelType ADC_Channel;

}ADC_ConfigType;

void initADC(ADC_ChannelType channel);


#endif /* ADC_H_ */
