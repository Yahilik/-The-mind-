#ifndef MAZO_H
#define MAZO_H

#include "Carta.h"
#include <vector>

using namespace std;

class Mazo {
private:
    vector<Carta> cartas;
public:
    void Barajar(int numeroCartas);
    vector<vector<Carta>> Repartir(int numeroJugadores, int nivelActual);
};

#endif
