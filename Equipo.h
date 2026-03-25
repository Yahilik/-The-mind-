#ifndef EQUIPO_H
#define EQUIPO_H

#include "Jugador.h"
#include <vector>

using namespace std;

class Equipo {
private:
    vector<Jugador> jugadores;
public:
    void agregarJugador(const Jugador& j);
    vector<Jugador>& getJugadores();
};

#endif
