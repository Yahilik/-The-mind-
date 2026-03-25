#include "Mazo.h"
#include <algorithm>
#include <random>

void Mazo::Barajar(int numeroCartas) {
    cartas.clear();
    for (int i = 1; i <= numeroCartas; i++) cartas.push_back(Carta(i));
    random_device rd;
    mt19937 g(rd());
    shuffle(cartas.begin(), cartas.end(), g);
}

vector<vector<Carta>> Mazo::Repartir(int numeroJugadores, int nivelActual) {
    vector<vector<Carta>> manos(numeroJugadores);
    for (int i = 0; i < numeroJugadores; i++) {
        for (int j = 0; j < nivelActual; j++) {
            if (!cartas.empty()) {
                manos[i].push_back(cartas.back());
                cartas.pop_back();
            }
        }
    }
    for (auto &mano : manos) {
        sort(mano.begin(), mano.end(), [](const Carta& a, const Carta& b) {
            return a.getNumero() < b.getNumero();
        });
    }
    return manos;
}
