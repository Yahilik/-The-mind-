#include "Equipo.h"

void Equipo::agregarJugador(const Jugador& j) { 
    jugadores.push_back(j); 
}

vector<Jugador>& Equipo::getJugadores() { 
    return jugadores; 
}
