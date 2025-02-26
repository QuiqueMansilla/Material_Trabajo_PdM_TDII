/*
 * API_debounce.c
 *
 *  Created on: 24 jul. 2023
 *      Author: quique
 */

/*Includes -------------------------------------------------------------------*/
#include "main.h"
#include "API_debounce.h"
#include "API_delay.h"

/*Defines --------------------------------------------------------------------*/
#define DEBOUNCE_DELAY 40 //solo aqui se puede modificar el tiempo de retardo entre
						  //lasdos lecturas para validar elvalor de la tecla

/*Declaracion de variables */
static debounceState_t actualState;
static bool_t keyPressed = false;
static bool_t fallingEdge = false;
static bool_t risingEdge = false;
static delay_t debounceDelay;
bool_t buttonRead = true;

/*Define functions -----------------------------------------------------------*/
//Funcion que detecta los flancos al presionar una tecla.
//Devuelve tres valores posibles:
//0 -> Si no hubo flancos (no se presiono la tecla)
//1 -> si hubo flaco decreciente
//2 -> si hubo flaco creciente
uint8_t edgeKey(void)
{
	uint8_t varReturn = 0;

	if(fallingEdge)
	{
		varReturn = 1; //Indica que hubo fanco decreciente
	}
	if(risingEdge)
	{
		varReturn = 2; //Indica que hubo fanco creciente
	}
	return varReturn;
}

//Devuelve true si la tecla fue presionada. Asume tecla activa alta como caso placa
//F413ZH que estamos usando
bool_t readKey(void)
{
	bool_t keyPress = false;
	fallingEdge = false;

	if(keyPressed)
	{
		keyPress = true;
	}
	return keyPress;
}

void debounceFSM_init(void)		// debe cargar el estado inicial
{
	actualState = BUTTON_UP;
	delayInit(&debounceDelay, DEBOUNCE_DELAY);
	//Actualizar salida del estado inicial Leds off
	HAL_GPIO_WritePin(GPIOB, LD1_Pin|LD3_Pin|LD2_Pin, GPIO_PIN_RESET);
	buttonRead = true; //USER_Btn_Pin no activado
}

void debounceFSM_update(bool buttonRead)
{
	switch (actualState)
	{
	case BUTTON_UP: //estado inicial 0
		//Actualizar salida del estado LEDs off
		//HAL_GPIO_WritePin(GPIOB, LD1_Pin|LD3_Pin|LD2_Pin, GPIO_PIN_RESET);
		//Chequear condicion de transición
		if(buttonRead == true) //se presionó USER_Btn_Pin
		{
			actualState = BUTTON_FALLING; //pasa al estado siguiente
			delayRead(&debounceDelay);   //arranca cuenta de DEBOUNCE_DELAY
		}
		fallingEdge = false; //asume que en este estado no hay flanco decreciente
		risingEdge = false;//asume que en este estado no hay flaco creciente
	break;

	case BUTTON_FALLING:
		//Chequea si paso el tiempo de 40 ms
		if(delayRead(&debounceDelay))
		{
			//Chequear condicion de transición
			if(buttonRead == true) //se presionó USER_Btn_Pin
			{
				buttonPressed(); //Dispara funcion buttonPresed()
				keyPressed = true; //Indica tecla presionada luego de 2 lecturas en 40 ms
				fallingEdge = true; //asume que en este estado hubo un flanco decreciente
				risingEdge = false;//asume que en este estado no hay flaco creciente
				actualState = BUTTON_DOWN; //pasa al estado siguiente
			}
			else
			{
				actualState = BUTTON_UP; // regresa al estado anterior
			}
		}
	break;

	case BUTTON_DOWN:
		//Chequear condicion de transición
		if(buttonRead == false) //se presionó USER_Btn_Pin
		{
			actualState = BUTTON_RISING; //pasa al estado siguiente
			delayRead(&debounceDelay);   //arranca cuenta de DEBOUNCE_DELAY
		}
		fallingEdge = false; //asume que en este estado no hay flanco decreciente
		risingEdge = false;//asume que en este estado no hay flaco creciente
	break;

	case BUTTON_RISING:
		//Chequea si paso el tiempo de 40 ms
		if(delayRead(&debounceDelay))
		{
			//Chequear condicion de transición
			if(buttonRead == false) //se USER_Btn_Pin regresó a estado inactivo
			{
				buttonReleased(); //Dispara funcion buttonRelaased()
				keyPressed = false; //Indica tecla presionada luego de 2 lecturas en 40 ms
				fallingEdge = false; //asume que en este estado no hay flanco decreciente
				risingEdge = true;//asume que en este estado hubo un flaco creciente
				actualState = BUTTON_UP; //pasa al estado siguiente, el inicial
			}
			else
			{
				actualState = BUTTON_DOWN; // regresa al estado anterior
			}
		}
	break;

	default:
		Error_Handler();
	break;
	}
}

void buttonPressed(void)
{
	HAL_GPIO_TogglePin(GPIOB, LD1_Pin); //Toggle LD1
}

void buttonReleased(void)
{
	HAL_GPIO_TogglePin(GPIOB, LD3_Pin); //Toggle LD3;
}

