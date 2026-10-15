# Manual del Usuario — Juego de Naves con Programación Orientada a Objetos

**Autor:** Aramis Demaria  
**Institución:** E.E.S.T. N.º 1 "Eduardo Ader" – Vicente López  
**Curso:** Laboratorio de Programación (LPR) – 5.º Año 3.º A-B  
**Profesor:** Prof. Mansilla Muñoz York Elías  
**Versión:** 1.0.0 — Actividad 8 — 2026  
**Formato:** Normas APA 7.ª edición

---

## Resumen

Este manual del usuario guía el uso del simulador de naves de la Actividad 8. Describe requisitos, controles e interpretación de la interfaz y el puntaje. Se redacta conforme a la séptima edición del *Publication Manual of the American Psychological Association* (APA, 2020).

**Palabras clave:** manual del usuario, juego de naves, controles

---

## 1. Introducción

Este manual está dirigido al usuario final que ejecuta el simulador sin necesidad de modificar el código. Describe los requisitos del sistema y el procedimiento de uso.

## 2. Requisitos del Sistema

Se requiere Windows 10 u 11 con compilador GCC y bibliotecas `windows.h` y `conio.h`. En equipos del laboratorio sin permisos de administrador se emplea OnlineGDB con captura de ejecución. No se requiere instalación adicional.

## 3. Instalación

No hay instalador. El ejecutable se genera compilando el código fuente:

```powershell
g++ -std=c++11 src/main.cpp -o src/juegodenaves.exe
.\src\juegodenaves.exe
```

El programa solicita el nombre del piloto, que se muestra en la interfaz superior para cumplir la regla antiplagio.

## 4. Controles e Interfaz

| Tecla | Acción |
|---|---|
| W | Mover arriba |
| A | Mover izquierda |
| S | Mover abajo |
| D | Mover derecha |
| Espacio | Disparar |

*Nota.* Controles del simulador.

La interfaz superior muestra PILOTO, VIDAS, SCORE y NIVEL. El objetivo es destruir asteroides (O) sin colisionar con ellos, sumando diez puntos por destrucción. Cada 50 puntos se incrementa el nivel. La partida inicia con tres vidas y finaliza al agotarse.

## 5. Solución de Problemas

Si el compilador informa `windows.h: No such file`, el sistema no es Windows; usar un equipo con Windows o reemplazar las dependencias. Si la ventana no responde, verificar que la terminal tenga foco para capturar `WASD` y espacio.

## Referencias

American Psychological Association. (2020). *Publication manual of the American Psychological Association* (7th ed.). https://doi.org/10.1037/0000165-000
