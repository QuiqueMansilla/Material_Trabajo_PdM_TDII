Asignatura: Programación de Microcontorladores 
Carrera: CESE - Coorte 20 
Autor: Mansilla Rubén Darío
Placa utilizada: STM-NUCLEO-F413ZH

Esta carpeta contiene la práctica 5 y desarrolla los puntos 1 y 2 en una sola
aplicación. Toma como base todas las funciones implemantadas en las practicas 
anteriores en los drivers API_delay, API_debounce.
Implementa las funciones para manejo de la uart3 que conecta con el puerto USB
en la placa de desarrollo utilizada. Dichas funciones se encuentran el el 
driver API_uart

Descripcion de la Aplicación:
Se utiliza una funcion edgeKey() ubicada en el dirver API_debounce que devuelve
el estado del flanco en caso de presionarse una tecla.
Esta función devuelve tres valores enteros que son asociados a una 
enumeracion definida como tipo de variable edgeState_t que contempla los 3 
valores posibles que puede devolver edgeKey(). Esta enumeración de encuentra
definida en main.h
El programa principal utiliza una variable edgeStatus del tipo edgeState_t que
almacena el valor devuelto por edgeKey().
Lee el valor del pulsador de usuario, lo filtra mediante la MEF antirebote
debonceFMS_update() que pasa informacion a la fucnion edgeKey() cuyo valor se
guarda en la variable edgeStatus.
Este valor es tomado por la funcion switch que mostrará en pantalla el estado 
del flanco sólo si se pulsó el boton de usuario de la placa de desarrollo. 

NOTA
Se agrega modificación en ultimo commit del 04/08/23 11:10 hs con modificaciones
 que solucionan warnisngs que daba el compilador. Solucion: se realizó casteo
en las cadenas de caracteres que se envian a la uart mediante la aplicacion de
la funcion uartSendingString() como se ve en ejemplo en main.c 
121   uartSendString((uint8_t *)"Flanco Decreciente\n\r"); 
Y en todas las lineas en las que se utiliza la funcion uartSendingString() 
