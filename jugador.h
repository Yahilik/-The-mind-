#ifndef JUGADOR_H
#define JUGADOR_H

#include "Carta.h"
#include <vector>

using namespace std;

class Jugador {
private:
    int IdJugador;
    vector<Carta> Mano;
public:
    Jugador(int id = 0);
    int getId() const;
    void setMano(const vector<Carta>& nuevaMano);
    bool tieneCartas() const;
    int verSiguienteCarta() const;
    void mostrarManoSecreta() const;
    int JugarCarta();
};

#endif
