/*
 * ADC.h
 *
 *  Created on: Mar 18, 2024
 *      Author: nayaabahmedn
 */

#ifndef ADC_H_
#define ADC_H_

#include "stm32f767xx.h"
#include <stdint.h>
void pa1_adc_init(void );
void start_adc_conversion(void);
uint32_t adc_read(void);

#endif /* ADC_H_ */
