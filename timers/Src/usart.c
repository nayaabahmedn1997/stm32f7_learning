/*
 * usart.c
 *
 *  Created on: Mar 18, 2024
 *      Author: nayaabahmedn
 */


#include "usart.h"

int __io__putchar(unsigned char ch)
{
	uart3_write(ch);
	return ch;
}

void uart3_Rx_init(void)
{
	/////////////////-------------

	/*	Configure the UART GPIO pins */
	//	1. Enable clock access to GPIOA
	RCC->AHB1ENR |= GPIOD_EN;


	//	2. Set PD9 mode as alternate function
	GPIOD->MODER  &=~(1U<<18);
	GPIOD->MODER  |= (1U<<19);

	//	3. Set PD9 alternate function type to UART_RX(AF7)
	GPIOD->AFR[1] |=(1U<<4);
	GPIOD->AFR[1] |=(1U<<5);
	GPIOD->AFR[1] |=(1U<<6);
	GPIOD->AFR[1] &=~(1U<<7);



	/*	Configure the USART module */
	//	1. Enable clock access to UART2
	RCC->APB1ENR |= USART3_EN;
	//	2. Configure the buadrate
	USART3->BRR    = 0x008B;
	//	3. Configure the transfer direction as Rx
	USART3->CR1 = (CR1_TE | CR1_RE);
	//	4. Enable the UART module.
	USART3->CR1 |= USART_UE;

}


void uart3_tx_init(void)
{
	/////////////////-------------

	/*	Configure the UART GPIO pins */
	//	1. Enable clock access to GPIOA
	RCC->AHB1ENR |= GPIOD_EN;
	//	2. Set PD8 mode as alternate function
	GPIOD->MODER  &=~(1U<<16);
	GPIOD->MODER  |= (1U<<17);
	//	3. Set PD8 alternate function type to UART_TX(AF7)
	GPIOD->AFR[1] |=(1U<<0);
	GPIOD->AFR[1] |=(1U<<1);
	GPIOD->AFR[1] |=(1U<<2);
	GPIOD->AFR[1] &=~(1U<<3);



	/*	Configure the USART module */
	//	1. Enable clock access to UART2
	RCC->APB1ENR |= USART3_EN;
	//	2. Configure the buadrate
	USART3->BRR    = 0x008B;
	//	3. Configure the transfer direction as Tx
	USART3->CR1 = (CR1_TE | CR1_RE);
	//	4. Enable the UART module.
	USART3->CR1 |= USART_UE;

}

unsigned char usart3_read(void){
//	Make sure the reeived data resister is not empty
	while(!((USART3->ISR)&USART_ISR_RXNE)){;};
//	Return the data
	return USART3->RDR;

}

void uart3_write(unsigned char x)
{

	USART3->TDR =(x);
	while(!((USART3->ISR)&USART_ISR_TC)){;};

}



