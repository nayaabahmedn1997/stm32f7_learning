/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
#include <stdio.h>
#include "usart.h"


#define GPIOBEN  (1U<<1)
#define GPIOB_7  (1U<<7)
#define blue_led  GPIOB_7

void blue_led_setup(void);


char key;



int main(void)
{
	uart3_tx_init();
	uart3_Rx_init();
	blue_led_setup();
	while (1)
	{
		key = usart3_read();
		if(key == '1')
		{
			GPIOB->ODR |= blue_led;
		}
		else
		{
			GPIOB->ODR &=~blue_led;
		}
		uart3_write(key);
	}
}

void blue_led_setup(void)
{

//	Enable clock ascess to AHb1 inorder to enable GPIOB
	RCC->AHB1ENR |= GPIOBEN;
//	Set the pin mode as output pins
	GPIOB->MODER |=(1U<<14);
	GPIOB->MODER &=~(1U<<15);

}

