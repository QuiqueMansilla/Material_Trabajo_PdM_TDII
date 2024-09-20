/*
 * API_delay.c
 *
 *  Created on: Jul 7, 2023
 *      Author: quique
 */

/*Includes*/
#include "main.h"


void delayInit( delay_t *delay, tick_t duration )
{
	if(delay == NULL || duration <= 0)
	{
		Error_Handler();
	}

	delay->startTime = HAL_GetTick(); /*Toma el valor del Tick de partida*/
	delay->duration = duration;
	delay->running = false;

}

bool_t delayRead( delay_t *delay )
{
	bool_t returnVal = false;

	if(delay == NULL)
	{
		Error_Handler();
	}

	if(delay->running == false)
	{
		/*Captura el valor inicial de la cuenta del tick*/
		delay->startTime = HAL_GetTick();
		delay->running = true;
	}

	/*Condicion: si marca de tiempo actual - marca de tiempo inicial >= duracion*/
	if ( (HAL_GetTick() - delay->startTime) >= delay->duration )
	{
		/*Se cumplio el tiempo de retardo a medir*/
		delay->running = false;
		returnVal = true;
	}
	return returnVal;
}

/*delayWrite() cambia el valor de la duracion del periodo de tiempo a cumplir*/
void delayWrite( delay_t *delay, tick_t duration )
{
	if(delay == NULL || duration <= 0)
	{
		Error_Handler();
	}

	delay->duration = duration;
}
/* USER CODE END 4 */
