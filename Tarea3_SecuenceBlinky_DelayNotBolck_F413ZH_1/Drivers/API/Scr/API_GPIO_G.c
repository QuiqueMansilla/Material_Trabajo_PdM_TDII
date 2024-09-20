/*
 * API_GPIO_G.c
 *
 *  Created on: Jul 7, 2023
 *      Author: quique
 */

#include "main.h"
#include "API_GPIO_Q.h"

bool GetStatus_GPIO_Pin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	bool outValue;
	/* get current Output Data Register value */
	outValue = (GPIOx->ODR)&(GPIO_Pin);
	return outValue;
}

