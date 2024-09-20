/*
 * API_uart.h
 *
 *  Created on: 11 ago. 2023
 *      Author: quique
 */

#ifndef API_INC_API_UART_H_
#define API_INC_API_UART_H_

/* Exported types ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/
void MX_USART3_UART_Init(void);
void API_uart_Send(distance_t distancia);

#endif /* API_INC_API_UART_H_ */
