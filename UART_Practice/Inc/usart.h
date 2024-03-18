/*
 * usart.h
 *
 *  Created on: Mar 18, 2024
 *      Author: nayaabahmedn
 */

#ifndef USART_H_
#define USART_H_

#include "stm32f767xx.h"
#include <stdint.h>


void uart3_tx_init(void);
void uart3_write(unsigned char x);
#define GPIOA_EN         (1U<<0)
#define GPIOD_EN         (1U<<3)
#define USART_EN         (1U<<17)
#define CR1_TE			 (1U<<3)
#define USART_UE         (1U<<0)
#define USART__ISR__TXE    (1U<<7)

///--------
#define USART3_EN         (1U<<18)
//--------


#endif /* USART_H_ */
