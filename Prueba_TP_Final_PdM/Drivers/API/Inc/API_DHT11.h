/*
 * API_DHT11.h
 *
 *  Created on: Aug 4, 2023
 *      Author: quique
 */

#ifndef API_INC_API_DHT11_H_
#define API_INC_API_DHT11_H_

typedef struct
{
	float Temperature;
	float Humidity;
}DHT_DataTypedef;


void DHT_GetData (DHT_DataTypedef *DHT_Data);

#endif /* API_INC_API_DHT11_H_ */
