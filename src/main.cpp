/*
 ============================================================================
 Materia: Laboratorio de Programacion (LPR) — 5 Ano
 Institucion: E.E.S.T. N 999 "Osterreichische Schule der Nationalokonomie" — Vicente Lopez
 Archivo: src/main.cpp
 Actividad 8: Introduccion a POO - Motor de Juego de Naves (Clases, Objetos)
 Docente: Prof. Mansilla Muñoz York Elías
 Estudiante: Aramis Demaria
 Funcionalidad Extra: Sistema de Puntaje (SCORE) + LEVEL — +10 por destruccion
 ============================================================================
*/
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <ctime>
#include <cctype>
using namespace std;

void gotoxy(int x, int y) {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos; dwPos.X = x; dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}
void ocultarCursor() {
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci; cci.dwSize = 2; cci.bVisible = FALSE;
    SetConsoleCursorInfo(hCon, &cci);
}

// ===== CLASE NAVE (Jugador) =====
class Nave {
private:
    int x, y;
    int vidas;
    int puntaje; // FUNCIONALIDAD EXTRA: encapsulado
public:
    Nave(int _x, int _y, int _vidas) { x=_x; y=_y; vidas=_vidas; puntaje=0; }
    int getX() { return x; }
    int getY() { return y; }
    int getVidas() { return vidas; }
    int getPuntaje() { return puntaje; }
    int getNivel() { return (puntaje / 50) + 1; } // cada 50 pts sube nivel
    void sumarPuntos(int pts) { puntaje += pts; }
    void reducirVida() { vidas--; }
    void pintar() {
        gotoxy(x,y); cout << "  ^  ";
        gotoxy(x,y+1); cout << " (O) ";
        gotoxy(x,y+2); cout << "^^^^ ";
    }
    void borrar() {
        gotoxy(x,y); cout << "     ";
        gotoxy(x,y+1); cout << "     ";
        gotoxy(x,y+2); cout << "     ";
    }
    void mover(char tecla) {
        borrar();
        if (tecla=='a' && x>2) x--;
        if (tecla=='d' && x<70) x++;
        if (tecla=='w' && y>3) y--;
        if (tecla=='s' && y<20) y++;
        pintar();
    }
};

class Asteroide {
private: int x,y;
public:
    Asteroide(int _x,int _y){x=_x;y=_y;}
    int getX(){return x;} int getY(){return y;}
    void pintar(){gotoxy(x,y); cout << "O";}
    void borrar(){gotoxy(x,y); cout << " ";}
    void mover(){ borrar(); y++; if(y>23){y=4; x=(rand()%70)+2;} pintar(); }
};

class Bala {
private: int x,y;
public:
    Bala(int _x,int _y){x=_x;y=_y;}
    int getX(){return x;} int getY(){return y;}
    void mover(){ gotoxy(x,y); cout << " "; y--; gotoxy(x,y); cout << "|"; }
    bool fueraDeRango(){return y<4;}
};

int main() {
    srand(time(NULL));
    string nombrePiloto;
    cout << "Ingresa tu Nombre y Apellido (Se mostrara en la captura): ";
    getline(cin, nombrePiloto);
    if(nombrePiloto.empty()) nombrePiloto = "Aramis Demaria";
    system("cls");
    ocultarCursor();
    bool gameOver=false;
    Nave jugador(35,20,3);
    vector<Asteroide*> asteroides;
    vector<Bala*> balas;
    for(int i=0;i<5;i++) asteroides.push_back(new Asteroide((rand()%70)+2,(rand()%5)+4));
    jugador.pintar();
    while(!gameOver) {
        gotoxy(2,1); cout << "PILOTO: " << nombrePiloto << "    ";
        gotoxy(2,2); cout << "VIDAS: " << jugador.getVidas() << "    ";
        gotoxy(2,3); cout << "SCORE: " << jugador.getPuntaje() << "  NIVEL: " << jugador.getNivel() << "    ";
        if(_kbhit()) {
            char tecla=tolower(_getch());
            if(tecla==' ') balas.push_back(new Bala(jugador.getX()+2,jugador.getY()-1));
            else jugador.mover(tecla);
        }
        for(int i=0;i<(int)balas.size();i++) {
            balas[i]->mover();
            if(balas[i]->fueraDeRango()) {
                gotoxy(balas[i]->getX(),balas[i]->getY()); cout << " ";
                delete balas[i]; balas.erase(balas.begin()+i); i--;
            }
        }
        for(int i=0;i<(int)asteroides.size();i++) {
            asteroides[i]->mover();
            if((asteroides[i]->getX()>=jugador.getX() && asteroides[i]->getX()<=jugador.getX()+4) &&
               (asteroides[i]->getY()>=jugador.getY() && asteroides[i]->getY()<=jugador.getY()+2)) {
                jugador.borrar(); jugador.reducirVida();
                asteroides[i]->borrar(); delete asteroides[i];
                asteroides[i]=new Asteroide((rand()%70)+2,4);
                jugador.pintar();
                if(jugador.getVidas()==0) gameOver=true;
            }
            for(int j=0;j<(int)balas.size();j++) {
                if(asteroides[i]->getX()==balas[j]->getX() && (asteroides[i]->getY()==balas[j]->getY() || asteroides[i]->getY()+1==balas[j]->getY())) {
                    gotoxy(balas[j]->getX(),balas[j]->getY()); cout << " ";
                    delete balas[j]; balas.erase(balas.begin()+j);
                    asteroides[i]->borrar(); delete asteroides[i];
                    asteroides[i]=new Asteroide((rand()%70)+2,4);
                    jugador.sumarPuntos(10); // FUNCIONALIDAD EXTRA
                    break;
                }
            }
        }
        Sleep(30);
    }
    system("cls");
    gotoxy(30,10); cout << "G A M E  O V E R";
    gotoxy(30,12); cout << "Puntaje final: " << jugador.getPuntaje() << "  Nivel: " << jugador.getNivel();
    gotoxy(30,14); system("pause");
    for(auto a: asteroides) delete a;
    for(auto b: balas) delete b;
    return 0;
}
