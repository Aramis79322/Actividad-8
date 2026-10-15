# Manual del Programador — Juego de Naves con Programación Orientada a Objetos

**Autor:** Aramis Demaria  
**Institución:** E.E.S.T. N.º 1 "Eduardo Ader" – Vicente López  
**Curso:** Laboratorio de Programación (LPR) – 5.º Año 3.º A-B  
**Profesor:** Prof. Mansilla Muñoz York Elías  
**Versión:** 1.0.0 — Actividad 8 — 2026  
**Formato:** Normas APA 7.ª edición

---

## Resumen

Este manual del programador documenta el juego de naves con programación orientada a objetos de la Actividad 8. Describe la clase *Nave* con atributos privados y métodos públicos, las clases *Asteroide* y *Bala*, el ciclo principal con colisiones y la funcionalidad adicional de puntaje y nivel, con pautas para extensión. Se redacta conforme a la séptima edición del *Publication Manual of the American Psychological Association* (American Psychological Association [APA], 2020).

**Palabras clave:** manual del programador, POO, clase, encapsulamiento, juego de naves

### Abstract

This programmer's manual documents the object-oriented spaceship game. It describes the *Nave* class with private attributes and public methods, the *Asteroide* and *Bala* classes, the main loop with collisions, and the additional score and level feature.

**Keywords:** programmer manual, OOP, class, encapsulation, spaceship game

---

## 1. Introducción

Este manual está dirigido al programador que extiende el motor de juego. Su propósito es explicitar el diseño de clases, el encapsulamiento y la inserción de la funcionalidad de puntaje, bajo formato APA 7. El alcance comprende el diseño de clases y el ciclo de colisiones; la persistencia y la interfaz gráfica quedan para trabajos futuros.

## 2. Requisitos del Sistema

Se requiere compilador GCC (g++) con soporte C++11, sistema operativo Windows 10 u 11 por las bibliotecas `windows.h` y `conio.h`, y Visual Studio Code con extensión C/C++ de Microsoft. En equipos del laboratorio sin permisos de administrador se emplea OnlineGDB con captura de ejecución. No se requieren bibliotecas externas adicionales.

## 3. Arquitectura del Sistema

La clase *Nave* encapsula `private: int x, y, vidas, puntaje` y expone `public: Nave(_x,_y,_vidas), getX, getY, getVidas, getPuntaje, getNivel, reducirVida, sumarPuntos, pintar, borrar, mover`. El método `getNivel` calcula `puntaje / 50 + 1`. Las clases *Asteroide* y *Bala* encapsulan coordenadas y lógica de movimiento; los contenedores son `vector<Asteroide*>` y `vector<Bala*>` con gestión dinámica.

| Clase | Atributos privados | Métodos públicos clave |
|---|---|---|
| Nave | x, y, vidas, puntaje | Constructor, getters, pintar/borrar/mover, sumarPuntos |
| Asteroide | x, y | pintar, borrar, mover |
| Bala | x, y | mover, fueraDeRango |

*Nota.* Diseño de clases del motor.

El ciclo principal inicializa `Nave jugador(35,20,3)`, oculta el cursor, gestiona entrada con `_kbhit` y `_getch` con `tolower`, mueve balas y asteroides, detecta colisiones por caja (nave-asteroide) y coincidencia exacta (bala-asteroide) y suma diez puntos con `sumarPuntos(10)`. La interfaz muestra PILOTO, VIDAS, SCORE y NIVEL en `gotoxy(2, 1..3)` y pausa de treinta milisegundos.

## 4. Instalación y Compilación

```powershell
g++ -std=c++11 src/main.cpp -o src/juegodenaves.exe
.\src\juegodenaves.exe
```

Requiere Windows por las bibliotecas `windows.h` y `conio.h`. La compilación en Linux requiere reemplazo de estas dependencias. El archivo `.gitignore` excluye ejecutables y la carpeta `.vscode`.

## 5. Guía de Extensión

La funcionalidad de puntaje demuestra extensibilidad: agregar un atributo privado y dos métodos sin modificar el motor salvo en la línea de colisión. Como extensión futura se propone persistencia de puntaje máximo con `fstream` (Actividad 7) y niveles con velocidad creciente de asteroides. Cada cambio se documenta con mensajes descriptivos (`feat:`, `docs:`, `fix:`) y versionado `v1.0.0`.

## Referencias

American Psychological Association. (2020). *Publication manual of the American Psychological Association* (7th ed.). https://doi.org/10.1037/0000165-000

cplusplus.com. (2024). *Classes*. https://cplusplus.com/doc/tutorial/classes/

Stroustrup, B. (2013). *The C++ programming language* (4th ed.). Addison-Wesley.
