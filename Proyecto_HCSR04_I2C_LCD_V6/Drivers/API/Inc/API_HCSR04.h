/*
 * API_HCSR04.h
 *
 *  Created on: 11 ago. 2023
 *      Author: quique
 */

#ifndef API_INC_API_HCSR04_H_
#define API_INC_API_HCSR04_H_

/* Exported types ------------------------------------------------------------*/

typedef int distance_t; //para la variable distancia

/* Exported functions prototypes ---------------------------------------------*/
distance_t API_HCSR04_Measure(void);
void MX_TIM1_Init(void);

#endif /* API_INC_API_HCSR04_H_ */
