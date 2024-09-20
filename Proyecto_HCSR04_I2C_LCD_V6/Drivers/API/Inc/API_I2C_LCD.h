/*
 * API_I2C_LCD.h
 *
 *  Created on: 11 ago. 2023
 *      Author: quique
 */

#ifndef INC_API_I2C_LCD_H_
#define INC_API_I2C_LCD_H_

#include "main.h"
/* Exported types ------------------------------------------------------------*/

/* Exported functions prototypes ---------------------------------------------*/

void lcd_init (void);   // initialize lcd
void lcd_send_cmd (char cmd);  // send command to the lcd
void lcd_send_data (char data);  // send data to the lcd
void lcd_send_string (char *str);  // send string to the lcd
void lcd_put_cur(int row, int col);  // put cursor at the entered position row (0 or 1), col (0-15);
void lcd_clear (void);
void enteroCad(int n, char cad[]);
void MX_I2C1_Init(void);

#endif /* INC_API_I2C_LCD_H_ */
