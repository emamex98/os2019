## Objetivo
Crear dos llamadas a sistema: una para apagar y otra para reiniciar, así como crear sus respectivos programas.

## Herramientas
- git
- make
- gcc 

## Conceptos
**1) Llamadas al sistema:** 
+ La formal que el kernel (SO) de acceso al HW
+ Se implemente mediante interrupciones de software (trap), ie: la aplicación se interrumpe para que el kernel se ejecute.

**2) Modo kernel:**
+ Es el bit/registro que activa el CPU para acceder al HW
+ Solo hay un programa que se ejecuta con este bit, es el kernel

**3) Interrupciones**
+ Es la forma que el HW interactua con el CPU

## ¿Qué aprendí?
+ Crear llamadas a sistema con sus respectivos programas y declaraciones en el header
+ Las llamadas que implementamos son para apagar y reiniciar la máquina virtual.

## URL del commit:
https://github.com/emamex98/os2019/commit/c15358010db858a963867c48430de142ea071120
https://github.com/emamex98/os2019/commit/bd49ff2ec90b29d7f99c06297631c9a39f0e6f43
