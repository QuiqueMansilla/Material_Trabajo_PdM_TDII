/*
 * API_GPIO.h
 *
 *  Created on: Aug 4, 2023
 *      Author: quique
 */

#ifndef API_INC_API_GPIO_H_
#define API_INC_API_GPIO_H_

/* Exported types ------------------------------------------------------------*/
typedef uint16_t led_t;/*Importante que el tipo sea uint16_t, si no, no funciona LD3_Pin*/


/* Exported functions prototypes ---------------------------------------------*/
void MX_GPIO_Init(void);
void writeLedOn_GPIO(led_t LDx);
void writeLedOff_GPIO(led_t LDx);
void toggleLed_GPIO(led_t LDx);

#endif /* API_INC_API_GPIO_H_ */
