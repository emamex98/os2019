## Objetivo
- Hacer un planificador de procesos.
- El procesp con mayor prioridad se ejecuta primero.
- Si hay dos o más con prioridades iguales, se ejecuta el primero de la lista.

## Herramientas
- git
- make
- gcc

## Conceptos
1) Procesos (PREGUNTA DE EXAMEN)
2) Planificación de procesos:
    - Es el mecanismo que el SO tiene para asignar el CPU a un proceso.
3) Estados de un proceso
4) Cambio de contexto:
    - Ocurre cuando el CPU deja de ejecutar un proceso para ejecutar otro.
    - Guarda el PC (program counter) y la dirección del Stack al proceso sctusl.
    - Restaura el PC y la dirección del nuevo proceso.

## ¿Qué aprendí?
- Como funciona un planificador de procesos
- Implementar funciones para cambiar y consultar prioridades de procesos

## URL del commit:
https://github.com/emamex98/os2019/commit/61b6032138d4b111295019f84d1da2d37267a47c

## ¿Cómo se relaciona los conceptos anteriores?
- Llamadas a sistema
- Procesos
