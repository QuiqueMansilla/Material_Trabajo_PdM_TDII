/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body Proyecto_HCSR04_I2C_LCD_V6
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "API_HCSR04.h"
#include "API_uart.h"
#include "API_I2C_LCD.h"
#include "API_ReadShowData.h"
#include "API_delay.h"
#include "API_GPIO.h"
#include <stdio.h>

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef enum{	//Define los estados de la MEF primcipal de Read-Show-Data
	INITIAL,
	READ_DATA,
	SHOW_DATA,
	} ReadShowDataState_t;

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define TIME_VIEW 400
#define TIME_INITIAL 2000
#define TIME_READ_DATA 2000
#define TIME_SHOW_DATA 2000
#define LED1 LD1_Pin //GREEN LED
#define LED2 LD2_Pin //BLUE LED
#define LED3 LD3_Pin //RED LED
#define TIME_LED1 100
#define TIME_LED2 200
#define TIME_LED3 300
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ReadShowDataState_t	actualState;
distance_t distance1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
//static void MX_GPIO_Init(void);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
  delay_t delay_TIME_VIEW; //Para visualizacion de datos
  delay_t delay_INITIAL;
  delay_t delay_READ_DATA;
  delay_t delay_SHOW_DATA;
  delay_t delay_TIME_LED1;
  delay_t delay_TIME_LED2;
  delay_t delay_TIME_LED3;
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
  delayInit(&delay_TIME_VIEW, TIME_VIEW);
  delayInit(&delay_INITIAL, TIME_INITIAL);
  delayInit(&delay_READ_DATA, TIME_READ_DATA);
  delayInit(&delay_SHOW_DATA, TIME_SHOW_DATA);
  delayInit(&delay_TIME_LED1, TIME_LED1);
  delayInit(&delay_TIME_LED2, TIME_LED2);
  delayInit(&delay_TIME_LED3, TIME_LED3);
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
//  MX_GPIO_Init();
//  MX_USART3_UART_Init();
//  MX_I2C1_Init();
//  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */
//  lcd_init();
  API_ReadShowData_init();
  actualState = INITIAL;
  delayRead(&delay_TIME_VIEW);
  delayRead(&delay_INITIAL); //Inicia conteo del delay la primera vez que se ejecuta
  delayRead(&delay_READ_DATA);
  delayRead(&delay_SHOW_DATA);
  delayRead(&delay_TIME_LED1);
  delayRead(&delay_TIME_LED2);
  delayRead(&delay_TIME_LED3);
  /* USER CODE END 2 */
  /* Infinite loop */
   while (1) /* USER CODE BEGIN WHILE */
  {
	switch (actualState)
	{
	  case INITIAL: //Estado inicial solo muestra mensaje y pasa una vez al inicio
		  if(delayRead(&delay_INITIAL)) //Cuando se cumple el tiempo estabelcido
		  {
			  actualState = READ_DATA; //Pasa al siguiente estado
			  writeLedOff_GPIO(LED1);
		  }
		  if(delayRead(&delay_TIME_VIEW))
		  {
			  API_ReadShowData_ShowInit();
		  }
		  if(delayRead(&delay_TIME_LED1))
		  {
			  toggleLed_GPIO(LED1);
		  }
	  break;

	  case READ_DATA://Estado de lectura de datos
		  if(delayRead(&delay_READ_DATA))
		  {
			  actualState = SHOW_DATA; //Pasa al estado siguiente
			  writeLedOff_GPIO(LED2);
		  }
		  if(delayRead(&delay_TIME_VIEW))
		  {
			  API_ReadShowData_ShowMeasuring();
			  distance1 = API_ReadShowData_ReadData();
		  }
		  if(delayRead(&delay_TIME_LED2))
		  {
		  	  toggleLed_GPIO(LED2);
		  }
	  break;


	  case SHOW_DATA://Estado de lectura de datos
		  if(delayRead(&delay_SHOW_DATA))
	  	  {
	  		actualState = READ_DATA; //Pasa al estado anterior
	  		writeLedOff_GPIO(LED3);
	  	  }
		  if(delayRead(&delay_TIME_VIEW))
		  {
			  API_ReadShowData_ShowData(distance1);
		  }
		  if(delayRead(&delay_TIME_LED3))
		  {
		  	  toggleLed_GPIO(LED3);
		  }
	  break;

	  default:
		  Error_Handler();
	  break;
	}

	/* USER CODE END WHILE */
	/* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 384;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 8;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/*static void MX_I2C1_Init(void) place origiginaly here*/

/*static void MX_TIM1_Init(void) place origiginaly here*/

/*static void MX_USART3_UART_Init(void) place originaly here*/

/*static void MX_GPIO_Init(void) place originaly here*/


/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
