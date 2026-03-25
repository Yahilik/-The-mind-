#include "Juego.h"
#include "Utils.h"
#include <iostream>
#include <fstream> // Librería para archivos

using namespace std;

Juego::Juego() : NivelActual(1), Vidas(2), Shurikens(1), EstadoJuego("En curso") {}

void Juego::guardarPartida() {
    ofstream archivo("partida.txt");
    if (archivo.is_open()) {
        archivo << NivelActual << " " << Vidas << " " << Shurikens;
        archivo.close();
        cout << "\n[!] Partida guardada automáticamente.\n";
    }
}

void Juego::cargarPartida() {
    ifstream archivo("partida.txt");
    if (archivo.is_open()) {
        archivo >> NivelActual >> Vidas >> Shurikens;
        archivo.close();
        cout << "\n[!] Partida cargada. Retomando en Nivel " << NivelActual << ".\n";
    } else {
        cout << "\n[!] No se encontró partida guardada. Iniciando desde cero.\n";
    }
}

void Juego::PerderVida() {
    if (Vidas > 0) {
        Vidas--;
        cout << "\n>>> ¡ERROR DE SINCRONIZACION! Alguien tenia una carta menor." << endl;
        cout << ">>> Se pierde una vida. Vidas restantes: " << Vidas << "\n" << endl;
    }
    if (Vidas <= 0) EstadoJuego = "Perdido";
}

void Juego::iniciarJuego() {
    equipo.agregarJugador(Jugador(1));
    equipo.agregarJugador(Jugador(2));

    cout << "Bienvenido a THE MIND\n";
    
    if (confirmarAccion("¿Deseas cargar una partida guardada?")) {
        cargarPartida();
    }

    pausarYLimpiar();

    while (EstadoJuego == "En curso" && NivelActual <= 5) {
        // Guardamos al inicio de cada nivel
        guardarPartida();

        mazo.Barajar(100);
        auto manos = mazo.Repartir(2, NivelActual);
        equipo.getJugadores()[0].setMano(manos[0]);
        equipo.getJugadores()[1].setMano(manos[1]);

        for (int i = 0; i < 2; i++) {
            cout << "--- TURNO DE MEMORIZACION ---" << endl;
            cout << "Que solo el JUGADOR " << (i+1) << " mire la pantalla." << endl;
            equipo.getJugadores()[i].mostrarManoSecreta();
            pausarYLimpiar();
        }

        int ultimaCartaMesa = 0;
        bool errorEnNivel = false;

        while (equipo.getJugadores()[0].tieneCartas() || equipo.getJugadores()[1].tieneCartas()) {
            cout << "========================================";
            cout << "\n NIVEL " << NivelActual << " | VIDAS: " << Vidas << " | SHURIKENS: " << Shurikens;
            cout << "\n========================================\n";
            cout << "Ultima carta jugada en la mesa: " << (ultimaCartaMesa == 0 ? "Ninguna" : to_string(ultimaCartaMesa)) << "\n\n";
            
            cout << "Ingrese 1 (Jugador 1) | Ingrese 2 (Jugador 2): ";
            
            string input;
            cin >> input;

            if (input != "1" && input != "2") continue;

            int index = stoi(input) - 1;
            int indexOtro = (index == 0) ? 1 : 0;

            if (!equipo.getJugadores()[index].tieneCartas()) {
                cout << "\nEl Jugador " << (index + 1) << " ya no tiene cartas.\n";
                continue;
            }

            int cartaJugada = equipo.getJugadores()[index].verSiguienteCarta();
            int otraCarta = equipo.getJugadores()[indexOtro].verSiguienteCarta();

            cout << "\n-> El Jugador " << (index + 1) << " lanza: " << cartaJugada << "\n";
            equipo.getJugadores()[index].JugarCarta();
            ultimaCartaMesa = cartaJugada;

            if (cartaJugada > otraCarta && otraCarta != 999) {
                PerderVida();
                errorEnNivel = true;
                break; 
            }
        }

        if (EstadoJuego == "Perdido") break;

        if (!errorEnNivel) {
            Nivel nivelObj(NivelActual);
            nivelObj.CompletarNivel();
            nivelObj.DarRecompensa(Vidas, Shurikens);
            NivelActual++;
            pausarYLimpiar();
        }
    }

    limpiarPantalla();
    if (EstadoJuego == "Perdido") {
        cout << "GAME OVER\n";
        remove("partida.txt");
    } else {
        cout << "¡VICTORIA!\n";
        remove("partida.txt");
    }
}
