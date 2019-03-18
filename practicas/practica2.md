## Objetivo
Modificar al programa shell (sh.c) para regresar al comando anterior.

## Herramientas
- git
- make
- gcc

## Conceptos
1) Como se crean nuevos procesos:
    + Un programa padre (sh.c) ejecuta la llamada fork
    + La llamada a sistema fork clona al proceso padre
    + El proceso hijo manda a llamar a exec para ejecutar otro código

## ¿Qué aprendí?
- Leer caracteres del shell utilizando el buffer
- Interpretar una "p↵" para ejecutar el comando anterior
- Función de fork

## URL del commit:
https://github.com/emamex98/os2019/commit/698473fd26248505d70100f61800c9019535a85d

## ¿Cómo se relaciona los conceptos anteriores?
- Llamadas de sistema.
- Funciones.
