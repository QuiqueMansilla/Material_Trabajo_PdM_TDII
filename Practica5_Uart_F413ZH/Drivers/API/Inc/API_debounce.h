/*
 * API_debounce.h
 *
 *  Created on: 24 jul. 2023
 *      Author: quique
 */

#ifndef API_INC_API_DEBOUNCE_H_
#define API_INC_API_DEBOUNCE_H_

/*Includes -------------------------------------------------------------------*/
#include "main.h"

/* Exported types ------------------------------------------------------------*/
typedef enum{
	BUTTON_UP,
	BUTTON_FALLING,
	BUTTON_DOWN,
	BUTTON_RISING
	} debounceState_t;

/*Declaracion de prototipo de funciones -------------------------------------*/
uint8_t edgeKey(void);
bool readKey(void);
void debounceFSM_init(void);
void debounceFSM_update(bool buttonRead);
void buttonPressed(void);
void buttonReleased(void);

#endif /* API_INC_API_DEBOUNCE_H_ */
