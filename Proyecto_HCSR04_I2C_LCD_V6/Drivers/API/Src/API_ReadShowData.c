/*
 * API_ReadShowData.c
 *
 *  Created on: 12 ago. 2023
 *      Author: quique
 */

/* Includes ************************************************************************/
#include "main.h"
#include "API_Headers.h"

/* Private variables ---------------------------------------------------------*/
distance_t distance; //asignar Variable int devuelta por funcion medicion HCSR04
static char_t dist[6]; //para convertir valor entero "distancia" a una cadena

/*Declaration of variables ********************************************************/
void API_ReadShowData_init(void)
{
/* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART3_UART_Init();
  MX_I2C1_Init();
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */
  lcd_init();
}

/*** Reel la distancia y devuelve su valor en formato cadena tipo char***/
distance_t API_ReadShowData_ReadData(void)
{
  distance = API_HCSR04_Measure(); //Hace la medicion con el HCSR04 y guarda en "distance"
  return distance;
}

/***Muestra en LCD mensaje de estado de Inicializacion de la App***/
void API_ReadShowData_ShowInit(void)
{
	/*** Mostrar en lcd ***/
	lcd_clear();
	lcd_put_cur(0, 0);
	lcd_send_string(" Inicializando ");
	lcd_put_cur(1, 0);
	lcd_send_string("Medidor Ultrason");
}

void API_ReadShowData_ShowMeasuring(void)
{
	/*** Mostrar en lcd ***/
	lcd_clear();
	lcd_put_cur(0, 0);
	lcd_send_string("    HC-SR04     ");
	lcd_put_cur(1, 0);
	lcd_send_string("    Midiendo    ");
}

void API_ReadShowData_ShowData(distance_t distance)
{	/* Convierte entero a cadena char para mostrar valor en LCD */
	sprintf(dist, "%d", distance);
	/*** Mostrar en lcd ***/
	lcd_clear();
	lcd_put_cur(0, 0);
	lcd_send_string("    HC-SR04     ");
	lcd_put_cur(1, 0);
	lcd_send_string("Distancia: ");
	lcd_send_string(dist);
	lcd_send_string("cm");
}

