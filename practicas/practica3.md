## Objetivo
Modifical al programa init para que muestre un programa de bienvenida

## Herramientas
- git
- make
- gcc

## Conceptos

*Concepto de examen:*

1) Proceso
    + Instacncia de un pograma:
    + Tiene tres partes:
      - Stack: variables y llamdas a funciones
      - Heap: memoria dinámica
      - Código
    + Se crea mediante dos llamadas a sistema:
      - Fork se clona
      - Exec cambia el código
    + Tiene un estado:
      - Corriendo
      - Durmiendo
      - Espera
      - Completado
      - Zombie
      
2) Programa init:
    + Es el programa creado por el SO  para dejarlo listo para usarse
    + Es el única proceso que crea el SO
   

## ¿Qué aprendí?
- El programa init is el primer programa creado por el SO
- Todas las funciones que se inserten en este programa sucederan automaticamente al principio ya que el SO lo inicia

## URL del commit:
https://github.com/emamex98/os2019/commit/528c9664e25be162322d9f8ec8a922d7166c6af1

## ¿Cómo se relaciona los conceptos anteriores?
- Funciones
- Procesos padres e hijos
