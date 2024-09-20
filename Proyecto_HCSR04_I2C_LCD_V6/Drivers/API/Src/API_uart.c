/*
 * API_uart.c
 *
 *  Created on: 11 ago. 2023
 *      Author: quique
 */

/* Includes ************************************************************************/
#include "main.h"
#include "API_Headers.h"

UART_HandleTypeDef huart3;

/*Declaration of variables ********************************************************/


/*** Function definition **********************************************************/
/*** imprimir el valor en el puerto serial usart3 ***/
void API_uart_Send(distance_t distancia)
{
	char dato[40] = "";

	sprintf(dato, "Distancia = %d cm \r\n", distancia);
	HAL_UART_Transmit(&huart3, (uint8_t *)dato, sizeof(dato), 1000);
}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
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
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

