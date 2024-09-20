Asignatura: Programación de Microcontorladores 
Carrera: CESE - Coorte 20 
Autor: Mansilla Rubén Darío

Esta carpeta contiene la practica 4 punto 2 
Esta aplicacion implementa, aparte de las 4 funciones que manejaran el tema del 
rebote mecanico al utilizar pulsadores de este tipo, otra función readKey() que
lee una variable interna, ubicada en el bloque de la funcion debounceFSM_update,
 que toma el valor true cuando se presionó una tecla (luego de dos lecturas 
espaciadas en un intervalo de tiempo de 40 ms.

Las funciones debounceXX y readKey() se encuentran en la carpeta de Drives/API
en los correspondientes archivos API_debounce.c y API_debounce.h

La aplicación evalua el valor que devuelve readyKey(), de devuelve el valor 
true si se precionó una tecla y false si la tecla no fue presionada.

Luego usa una variable bolleana "toggle" que invierte si valor cada vez que 
readKey() indica que se preionó la tecla de manera de cambiar la configuracion
 de la duración del parpadeo entre dos valores: 200 ms y 500 ms.

La aplicación utiliza las funciones de implementacio de retardos no 
bloqueantes de la libreria API_delay. 
