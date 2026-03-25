#include "Nivel.h"
#include <iostream>

using namespace std;

Nivel::Nivel(int n) : NumeroNivel(n) {
    recompensaVida = (n % 2 == 1 && n != 5) ? 1 : 0;
    recompensaShuriken = (n % 2 == 0) ? 1 : 0;
}

void Nivel::CompletarNivel() const { 
    cout << "\n*** ¡Nivel " << NumeroNivel << " completado con exito! ***\n"; 
}

void Nivel::DarRecompensa(int &vidas, int &shurikens) const {
    vidas += recompensaVida;
    shurikens += recompensaShuriken;
    if (recompensaVida > 0 || recompensaShuriken > 0) {
        cout << "Recompensas: ";
        if (recompensaVida) cout << "+1 Vida ";
        if (recompensaShuriken) cout << "+1 Shuriken ";
        cout << endl;
    }
}
