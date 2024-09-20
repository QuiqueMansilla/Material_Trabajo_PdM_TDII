/*
 * API_HCSR04.c
 *
 *  Created on: 11 ago. 2023
 *      Author: quique
 */

/* Includes ************************************************************************/
#include "main.h"
#include "API_Headers.h"

TIM_HandleTypeDef htim1;

/*Declaration of variables ********************************************************/
static uint32_t valor1, valor2, periodo; //valor1 =Tiempo subida, valor2 = tiempo bajada
static uint8_t es_pv = 0; //flag: si el primer valor es capturado, el segundo, etc...
distance_t distancia;


/*** Function definition **********************************************************/
/*** Funcion para calcular el ancho de pulso del eco ***/
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim) //Rutina de servicio de interrupcion
{														//que canal fue el que lo disparó
	if(htim -> Channel == HAL_TIM_ACTIVE_CHANNEL_1)
	{
		if(es_pv == 0) //Identifica la primera lectura
		{
			valor1 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1);//Captura el primer tiempo subida
			es_pv = 1; //Una vez identificado momento de subida, ahora el siguente tiempo que calcula es el de bajada
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_FALLING); //Cambiamos polaridad
		}
		else if(es_pv == 1)
		{
			valor2 = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_1); //calculo momento de bajada
			__HAL_TIM_SET_COUNTER(htim, 0); //una macro que reinicia el contador

			if(valor2 > valor1)
			{
				periodo = valor2 - valor1; //valor en microsegundos
			}
			es_pv = 0; //vuelve a cero para hacer otras lecturas
			__HAL_TIM_SET_CAPTUREPOLARITY(htim, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_RISING); //Cambiamos polaridad
		}
	}
}

/* Mide la distancia al objeto usando los parametros preconfigurados GPIO y TIM1 seleccionado***/
distance_t API_HCSR04_Measure(void)
{
	/*** Comienzo de la rutina de medicion ***/
	HAL_GPIO_WritePin(TRIGGER_GPIO_Port, TRIGGER_Pin, GPIO_PIN_SET);
	HAL_Delay(10); //10 us de espera
	HAL_GPIO_WritePin(TRIGGER_GPIO_Port, TRIGGER_Pin, GPIO_PIN_RESET);

	/*** Iniciar Timer y medir ancgo de pulso ***/
	HAL_TIM_IC_Start_IT(&htim1, TIM_CHANNEL_1);

	distancia = periodo/58; //Distancia en cm
	return distancia;
}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_IC_InitTypeDef sConfigIC = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 96-1;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 65535;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_IC_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigIC.ICPolarity = TIM_INPUTCHANNELPOLARITY_RISING;
  sConfigIC.ICSelection = TIM_ICSELECTION_DIRECTTI;
  sConfigIC.ICPrescaler = TIM_ICPSC_DIV1;
  sConfigIC.ICFilter = 4;
  if (HAL_TIM_IC_ConfigChannel(&htim1, &sConfigIC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

}

