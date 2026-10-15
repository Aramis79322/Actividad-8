# Manual del Programador — Juego de Naves v1.0.0

**Autor:** Aramis Demaria

## Clases
- Nave: private x,y,vidas,puntaje; public constructor, getters, pintar/borrar/mover, sumarPuntos, getNivel.
- Asteroide/Bala: encapsuladas con mover y colisiones.

## Funcionalidad Extra
SCORE +10 por colisión bala-asteroide; NIVEL = SCORE/50+1; HUD en gotoxy(2,3).

## Colisiones
AABB para nave-asteroide, coord exacta para bala-asteroide.
