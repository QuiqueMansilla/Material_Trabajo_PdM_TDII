/*
 * API_DWT_delay.h
 *
 *  Created on: Aug 9, 2023
 *      Author: quique
 */

#ifndef API_INC_API_DWT_DELAY_H_
#define API_INC_API_DWT_DELAY_H_

#include <stdint.h>

#ifndef INC_DWT_DELAY_H_
#define INC_DWT_DELAY_H_

#define DWT_DELAY_NEWBIE 0

void DWT_Init(void);
void DWT_Delay(uint32_t us);

#endif /* INC_DWT_DELAY_DWT_DELAY_H_ */

#endif /* API_INC_API_DWT_DELAY_H_ */
