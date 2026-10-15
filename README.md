# Juego de Naves — Actividad 8: POO en C++ (class Nave)

**Materia:** LPR — 5° Año 3° División A-B | **Prof.:** Prof. Mansilla Muñoz York Elías | **Est.:** Aramis Demaria

## Objetivo
Transición struct → class: encapsulamiento (private/public), métodos, constructor.

## Estructura
```
/juegodenaves/
├── .gitignore
├── LICENSE
├── README.md
├── docs/
│   ├── InformeEEST1_LPR2026_ACT08_G03_v1.0.0.pdf
│   ├── CHANGELOG.md
│   └── manuales/
│       ├── manual_programador_v1.0.0.pdf
│       └── manual_usuario_v1.0.0.pdf
├── src/main.cpp
└── capturas/combate_consola.png
```

## Controles
W/A/S/D mover, ESPACIO disparar, HUD con piloto y vidas.

## Compilación (Windows)
```powershell
g++ -std=c++11 src/main.cpp -o src/juegodenaves.exe
.\src\juegodenaves.exe
```
Requiere windows.h, conio.h (solo Windows). Funcionalidad extra: Sistema de Puntaje.

## Funcionalidad Extra Implementada
Sistema de Puntaje: +10 por asteroide destruido con bala, HUD con SCORE y LEVEL.
