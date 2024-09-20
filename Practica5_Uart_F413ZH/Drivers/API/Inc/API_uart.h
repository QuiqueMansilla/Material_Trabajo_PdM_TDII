/*
 * API_uart.h
 *
 *  Created on: Jul 27, 2023
 *      Author: quique
 */

#ifndef API_INC_API_UART_H_
#define API_INC_API_UART_H_

/*Includes -------------------------------------------------------------------*/
#include "main.h"

/* Exported types ------------------------------------------------------------*/

/*Declaracion de prototipo de funciones --------------------------------------*/
//void MX_USART3_UART_Init(void);
void showConfigUART(void);
bool uartInit(void);
void uartSendString(uint8_t *pstring);
void uartSendStringSize(uint8_t * pstring, uint16_t size);
void uartReceiveStringSize(uint8_t * pstring, uint16_t size);


#endif /* API_INC_API_UART_H_ */
