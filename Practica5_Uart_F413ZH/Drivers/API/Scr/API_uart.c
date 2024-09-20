/*
 * API_uart.c
 *
 *  Created on: Jul 27, 2023
 *      Author: quique
 */

/*Includes -------------------------------------------------------------------*/
#include "main.h"
#include "API_uart.h"
#include "API_delay.h"

/*Defines --------------------------------------------------------------------*/
#define TIME_OUT 0xFFFF
#define SIZE 1
#define LENGTH 100 //Longitud de cadena de caracteres pstring


/*Declaracion de variables ---------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart3;
static bool_t statusInitUART = false;
//uint8_t pstring[LENGTH];

/*Define functions -----------------------------------------------------------*/
//Inicializa la UART, si la inicialización fur existosa devuelve "true" y
//muestra en pantalla los valores de configuracion de la misma
bool_t uartInit(void)
{
  /*##-1- Configure the UART peripheral ######################################*/
  /* Put the USART peripheral in the Asynchronous mode (UART Mode) */
  /* UART configured as follows:
	- Word Length = 8 Bits (7 data bit + 1 parity bit) :
	                BE CAREFUL : Program 7 data bits + 1 parity bit in PC HyperTerminal
	- Stop Bit    = One Stop bit
	- Parity      = NONE parity
	- BaudRate    = 115200 baud
	- Hardware flow control disabled (RTS and CTS signals) */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
    statusInitUART = false;
  }
  /* USER CODE BEGIN USART3_Init 2 */
  else
  {
	statusInitUART = true;
	showConfigUART();//No esta automatizada, debe actualizarse si cambia la configuracion
  }
  /* USER CODE END USART3_Init 2 */
  return statusInitUART;
}

//Envia una cadena de caracteres hasta que encuentra fin de string de caracteres ´\0'
void uartSendString(uint8_t *pstring)
{
	uint16_t length = 0;
	while (pstring[length] != '\0')
	{
		HAL_UART_Transmit(&huart3, &pstring[length], SIZE, TIME_OUT);
		length = length + 1;
	}
}

//Envia una cadena de caracteres de a uno hasta una cantidad determinada por "size"
void uartSendStringSize(uint8_t *pstring, uint16_t size)
{
	uint16_t length = 0;
	while (length < size)
	{
		HAL_UART_Transmit(&huart3, &pstring[length], SIZE, TIME_OUT);
		length++;
	}
}

//Recibe una cadena de caracteres de a uno hasta una cantidad determinada por "size"
void uartReceiveStringSize(uint8_t *pstring, uint16_t size)
{
	uint16_t length = 0;
	while (length <= size)
	{
		HAL_UART_Receive(&huart3, &pstring[length], SIZE, TIME_OUT);
		length++;
	}
}

//Muestra la configuración de le UART, no esta automatizada, debe modificarse si cambia
//la configuración de la UART
void showConfigUART(void)
{
	uartSendString((uint8_t *)"Configuracion UART\n\r");
	uartSendString((uint8_t *)"Modulo = USART3\n\r");
	uartSendString((uint8_t *)"Baud Rate = 115200 Bps\n\r");
	uartSendString((uint8_t *)"Word Length = 8B (7 Data Bits + 1 Stop Bit)\n\r");
	uartSendString((uint8_t *)"Parity = NONE\n\r");
	uartSendString((uint8_t *)"Mode = FULL DUPPLEX\n\r");
	uartSendString((uint8_t *)"Flow Control = NONE\n\r");
	uartSendString((uint8_t *)"Over Sampling = OVER SAMPLING 16\n\r");
}

