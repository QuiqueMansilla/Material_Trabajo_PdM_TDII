Asignatura: Programación de Microcontorladores
Carrera: CESE - Coorte 20
Autor: Mansilla Rubén Darío

Esta carpeta contiene la practica 4 punto 1
Esta aplicacion implementa 4 funciones que manejaran el tema del rebote mecánico
al utilizar pulsadores de este tipo.
Las funcion son las siguientes: 
* debounceFSM_init
* debounceFSM_update
* buttonPressed
* buttonReleased

buttonReleased: La consigna presupeone una entrada por pulsador que es activa baja.
Sin embargo el pulsador utilizado en la placa de desarrollo F413ZH que es la que utilizo
tiene un uldador activo alto. Por tal motivo los dos primeros estados BUTTON_UP y 
BUTTON_FALLING se evalúan considerando estado "true" para la variable buttonRead y los 
otros dos estados BUTTON_DOWN Y BUTTON_RISING se evaluan considerando estado "false" para 
la variable buttonRead.
En caso de utilizar un pulsador relamente activo bajo se deben invertir estas condiciones
de evaluación en los correspocndientes 4 estados de nuestra maquina de estados.

La aplicacion toglea el led LD1 cuando se presiona el pulsador de usuario de la placa y 
toglea el led LD3 cuando se suelta el pulsador de usuario.
Si alguna función detecta un error de parametros se enciende el led LD2 y se detiene la 
misma, permaneciendo el LD2 encendido hasta que se resetee la placa.

