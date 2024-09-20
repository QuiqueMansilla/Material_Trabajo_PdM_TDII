
#include "main.h"
#include "API_Headers.h"
extern I2C_HandleTypeDef hi2c1;  // change your handler here accordingly

#define SLAVE_ADDRESS_LCD 0x4E /* La direccion es de 7 bits segguida del bit R/W*
								* la direccion por defecto es 0x27 -> %010 0111
							    * si le agregamos un 0 en la posicion del LSB que
							    * corresponde a Write (W* = 0) se forma el valor
							    * 0100 1110 -> 0X4E Esto es para un driver PCF8574 */
/*NOTA si tenemos un driver PCF7584A, su direccion por defecto es 0x3F -> % 111 1111,
 * a la que si le agregamos un 0 en el LSB que corresponde a Write (W* = 0) tendremos
 * el valor % 1111 1110-> 0xFE */

void lcd_send_cmd (char cmd)
{
  char data_u, data_l;
	uint8_t data_t[4];
	data_u = (cmd&0xf0);
	data_l = ((cmd<<4)&0xf0);
	data_t[0] = data_u|0x0C;  //en=1, rs=0
	data_t[1] = data_u|0x08;  //en=0, rs=0
	data_t[2] = data_l|0x0C;  //en=1, rs=0
	data_t[3] = data_l|0x08;  //en=0, rs=0
	HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) data_t, 4, 100);
}

void lcd_send_data (char data)
{
	char data_u, data_l;
	uint8_t data_t[4];
	data_u = (data&0xf0);
	data_l = ((data<<4)&0xf0);
	data_t[0] = data_u|0x0D;  //en=1, rs=0
	data_t[1] = data_u|0x09;  //en=0, rs=0
	data_t[2] = data_l|0x0D;  //en=1, rs=0
	data_t[3] = data_l|0x09;  //en=0, rs=0
	HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) data_t, 4, 100);
}

void lcd_clear (void)
{
	lcd_send_cmd (0x80);
	for (int i=0; i<70; i++)
	{
		lcd_send_data (' ');
	}
}

void lcd_put_cur(int row, int col)
{
    switch (row)
    {
        case 0:
            col |= 0x80;
            break;
        case 1:
            col |= 0xC0;
            break;
    }

    lcd_send_cmd (col);
}


void lcd_init (void)
{
	// 4 bit initialisation
	HAL_Delay(50);  // wait for >40ms
	lcd_send_cmd (0x30);
	HAL_Delay(5);  // wait for >4.1ms
	lcd_send_cmd (0x30);
	HAL_Delay(1);  // wait for >100us
	lcd_send_cmd (0x30);
	HAL_Delay(10);
	lcd_send_cmd (0x20);  // 4bit mode
	HAL_Delay(10);

  // display initialisation
	lcd_send_cmd (0x28); // Function set --> DL=0 (4 bit mode), N = 1 (2 line display) F = 0 (5x8 characters)
	HAL_Delay(1);
	lcd_send_cmd (0x08); //Display on/off control --> D=0,C=0, B=0  ---> display off
	HAL_Delay(1);
	lcd_send_cmd (0x01);  // clear display
	HAL_Delay(1);
	HAL_Delay(1);
	lcd_send_cmd (0x06); //Entry mode set --> I/D = 1 (increment cursor) & S = 0 (no shift)
	HAL_Delay(1);
	lcd_send_cmd (0x0C); //Display on/off control --> D = 1, C and B = 0. (Cursor and blink, last two bits)
}

void lcd_send_string (char *str)
{
	while (*str) lcd_send_data (*str++);
}

/*Codigo sugerido a agregar
//Añadir función
void lcd_gotoxy(char sin firmar x, char sin firmar y)
{
  char sin firmar xy;
  si(y==0){xy=0x80;}
  si(y==1){xy=0xC0;}
  si(y==2){xy=0x94;}
  si(y==3){xy=0xD4 ;}
  xy=xy+x;
  lcd_enviar_cmd (xy);
}

//Hola, quiero sugerir el siguiente código para PC8574 con 9 pines (placa azul)
//Rs–>P0, RW–>P1, E–>P2, D4–>P4, D5–>P5, D6–>P6, D7–>P7
void lcd_send_cmd(char cmd)
{
uint8_t cmd_t[4];

cmd_t[0]=(cmd&0xf0)|(0x04); //cmd_u ,E=1, RS=0
cmd_t[1]=(cmd&0xf0); //E=0, RS=0
cmd_t[2]=((cmd<<4)&0xf0)|(0x04); //cmd_l E=1, RS=0
cmd_t[3]=((cmd<<4)&0xf0); //E=0, RS=0
HAL_I2C_Master_Transmit(&hi2c1, SLAVE_ADDRESS_LCD, (uint8_t *) cmd_t, 4, 200);
}
void lcd_send_data(char data)
{
uint8_t data_t[4];
datos_t[0]=(datos&0xf0)|(0x05); //datos_u , E=1, RS=1
datos_t[1]=(datos&0xf0)|(0x01); //E=0, RS=1
datos_t[2]=((datos<<4)&0xf0)|(0x05); //datos_l, E=1, RS=1
datos_t[3]=((datos<<4)&0xf0)|(0x01); //E=0, RS=1
HAL_I2C_Master_Transmit(&hi2c1, SLAVE_ADDRESS_LCD, (uint8_t *) data_t, 4, 200);
}*/
