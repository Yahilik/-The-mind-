#include "Utils.h"
#include <iostream>

using namespace std;

void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pausarYLimpiar() {
    cout << "\nPresiona ENTER para ocultar la pantalla y continuar...";
    cin.ignore();
    cin.get();
    limpiarPantalla();
}
