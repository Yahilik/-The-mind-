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
    cout << "\nPresiona ENTER para continuar...";
    cin.ignore();
    cin.get();
    limpiarPantalla();
}

bool confirmarAccion(const char* mensaje) {
    char respuesta;
    cout << mensaje << " (s/n): ";
    cin >> respuesta;
    return (respuesta == 's' || respuesta == 'S');
}
