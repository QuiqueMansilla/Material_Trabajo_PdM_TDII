/*
 * API_delay.h
 *
 *  Created on: Jul 7, 2023
 *      Author: quique
 */

#ifndef API_INC_API_DELAY_H_
#define API_INC_API_DELAY_H_

/*Includes*/
#include "main.h"
#include "API_Headers.h"

/* Exported types ------------------------------------------------------------*/
typedef uint32_t tick_t;

typedef bool bool_t;

typedef struct{
		tick_t startTime;
		tick_t duration;
		bool_t running;
		} delay_t;

/* Exported functions prototypes ---------------------------------------------*/
/*void Error_Handler(void);*/

/* USER CODE BEGIN EFP */
void delayInit( delay_t *delay, tick_t duration );
bool_t delayRead( delay_t *delay );
void delayWrite( delay_t *delay, tick_t duration );
/* USER CODE END EFP */

#endif /* API_INC_API_DELAY_H_ */
