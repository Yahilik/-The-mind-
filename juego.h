#ifndef JUEGO_H
#define JUEGO_H

#include "Mazo.h"
#include "Equipo.h"
#include "Nivel.h"
#include <string>

using namespace std;

class Juego {
private:
    int NivelActual;
    int Vidas;
    int Shurikens;
    string EstadoJuego;
    Mazo mazo;
    Equipo equipo;

    void PerderVida();

public:
    Juego();
    void iniciarJuego();
};

#endif
