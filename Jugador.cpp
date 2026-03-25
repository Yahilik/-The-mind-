#include "Jugador.h"
#include <iostream>

Jugador::Jugador(int id) : IdJugador(id) {}

int Jugador::getId() const { 
    return IdJugador; 
}

void Jugador::setMano(const vector<Carta>& nuevaMano) { 
    Mano = nuevaMano; 
}

bool Jugador::tieneCartas() const { 
    return !Mano.empty(); 
}

int Jugador::verSiguienteCarta() const {
    if (!Mano.empty()) return Mano.front().getNumero();
    return 999; 
}

void Jugador::mostrarManoSecreta() const {
    cout << "Tus cartas son: [ ";
    for (const auto& c : Mano) cout << c.getNumero() << " ";
    cout << "]" << endl;
}

int Jugador::JugarCarta() {
    if (!Mano.empty()) {
        int cartaJugada = Mano.front().getNumero();
        Mano.erase(Mano.begin());
        return cartaJugada;
    }
    return -1;
}
