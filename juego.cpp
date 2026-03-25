#include "Juego.h"
#include "Utils.h"
#include <iostream>

Juego::Juego() : NivelActual(1), Vidas(2), Shurikens(1), EstadoJuego("En curso") {}

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
    cout << "Regla principal: No pueden hablar. Sientan el paso del tiempo.\n";
    pausarYLimpiar();

    while (EstadoJuego == "En curso" && NivelActual <= 5) {
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
            
            cout << "Jugadores, concentrense. Quien sienta que tiene la carta mas baja, actue.\n";
            cout << "Ingrese 1 si lanza el Jugador 1 | Ingrese 2 si lanza el Jugador 2: ";
            
            string input;
            cin >> input;

            if (input != "1" && input != "2") {
                cout << "Entrada invalida. Intente de nuevo.\n";
                continue;
            }

            int index = stoi(input) - 1;
            int indexOtro = (index == 0) ? 1 : 0;

            if (!equipo.getJugadores()[index].tieneCartas()) {
                cout << "\nEl Jugador " << (index + 1) << " ya no tiene cartas. Debe jugar el otro.\n\n";
                continue;
            }

            int cartaJugada = equipo.getJugadores()[index].verSiguienteCarta();
            int otraCarta = equipo.getJugadores()[indexOtro].verSiguienteCarta();

            cout << "\n-> El Jugador " << (index + 1) << " decide lanzar un: " << cartaJugada << "\n";
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
    cout << "\n========================================\n";
    if (EstadoJuego == "Perdido") {
        cout << "              GAME OVER\n";
        cout << " Se ha roto la conexion. Sin vidas.\n";
    } else {
        cout << "              ¡VICTORIA!\n";
        cout << " Mentes sincronizadas a la perfeccion.\n";
    }
    cout << "========================================\n";
}
