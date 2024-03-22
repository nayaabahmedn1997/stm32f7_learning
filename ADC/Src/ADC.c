/*
 * ADC.C
 *
 *  Created on: Mar 18, 2024
 *      Author: nayaabahmedn
 */
#include "ADC.h"

#define ADC1_EN       (1U<<8)
#define GPIOA_EN      (1U<<0)
#define ADC_CH1       (1U<<0)
#define ADC_SEQ_LEN_1  0x00
#define CR2_ADON       (1U<<0)
#define CR2_SWSTART_ON (1U<<30)
#define SR_EOC          (1U<<1)



#define CH3 0x03

/*ADC configured with 3 channels
 * ch2, ch3, ch5
 * first = ch5
 * seconf  = ch2
 * third = ch3
 * */


void pa1_adc_init(void)
{

//	/* Enable clock access to GPIOA */
//	RCC->AHB1ENR |= GPIOA_EN;
////	set mode of PA1 to Analog mode
//	GPIOA->MODER |= (1U<<2);
//	GPIOA->MODER |= (1U<<3);
//
//	/* Configure the ADC module*/
////	Enable clock access to ADC
//	RCC->APB2ENR |= ADC1_EN;
///*	Configure ADC parameters */
//	/*Conversion sequence start*/
//	ADC1->SQR3 = ADC_CH1;
//	/*Conversion sequence length*/
//	ADC1->SQR1 = ADC_SEQ_LEN_1;
//	/* Enable ADC module*/
//	ADC1->CR2 |= CR2_ADON;
//


	RCC->AHB1ENR|=RCC_AHB1ENR_GPIOAEN;
	RCC->APB2ENR|=RCC_APB2ENR_ADC1EN;

	GPIOA->MODER|=GPIO_MODER_MODER3_0|GPIO_MODER_MODER3_1;
	ADC1->SQR1=0;
	ADC1->SQR3=(CH3<<0);
	ADC1->CR1|=ADC_CR1_EOCIE;
	NVIC_EnableIRQ(ADC_IRQn);
	ADC1->CR2 |= ADC_CR2_CONT;
	ADC1->CR2 |= ADC_CR2_ADON;
	ADC1->CR2 |= ADC_CR2_SWSTART;
}


void start_adc_conversion(void)
{
	/*Start the ADC conversion*/
	ADC1->CR2 |= CR2_SWSTART_ON;
}


uint32_t adc_read(void)
{
//	uint32_t result = 0x00;
////	Wait for the conversion to be complete
//	while(!(ADC1->SR & ADC_SR_EOC)){}
//
////	Read the converted result
//	result  = ADC1->DR;
//	return result;




/*Check if end-of-conversion interrupt occurred*/

		/*Check if end-of-conversion interrupt occurred*/

			if(ADC1->SR & ADC_SR_EOC)
			{
				/*Clear EOC flag*/
				ADC1->SR &=~ADC_SR_EOC;

				/*Do something*/
				return ADC1->DR;
			}

}
