/*
 * API_ReadShowData.h
 *
 *  Created on: 12 ago. 2023
 *      Author: quique
 */

#ifndef API_INC_API_READSHOWDATA_H_
#define API_INC_API_READSHOWDATA_H_

/* Exported types ------------------------------------------------------------*/
typedef char char_t; //Para cadena dist[6] que se usará en conversion de int a char

/* Exported functions prototypes ---------------------------------------------*/
void API_ReadShowData_init(void); //Inicializa todos los elemnetos a usar por la MEF

distance_t API_ReadShowData_ReadData(void);

void API_ReadShowData_ShowInit(void); //Muestra en LCD mensaje de inicializacion

void API_ReadShowData_ShowMeasuring(void);//Muestra en LCD mesaje de estado lectura datos

void API_ReadShowData_ShowData(distance_t distance); //Muestra medicion en LCD


#endif /* API_INC_API_READSHOWDATA_H_ */
