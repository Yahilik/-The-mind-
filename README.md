# -The-mind-

Clase: Juego

Atributos
• Int NivelActual
• Int Vidas
• Int Shurikens
• String EstadoJuego

Métodos
• Void iniciarJuego()
• String PerderVida(numeroDeVidas)
• Void UsarShuriken(numeroShuriken, sincronizacion)
• Void AplicarRecompensa(nivelActual)
• Void VerificarOrdenCartas(mano, numeroCartasPorJugador)

⸻

Clase: Nivel

Atributos
• Int NumeroNivel
• Int CartasPorJugador
• Int recompensaVida
• Int RecompensaShuriken

Métodos
• Void CompletarNivel(nivelActual)
• String DarRecompensa(nivelActual, recompensaVida, recompensaShuriken)

⸻

Clase: Mazo

Atributos
• Int Carta*

Métodos
• Void Barajar(numeroCartas)
• String Repartir(numeroJugadores, nivelActual)

⸻

Clase: Carta

Atributos
• Int numeroCarta

Métodos
• String mostrar(numeroCartasPorJugador, mano)

⸻

Clase: Jugador

Atributos
• Int IdJugador
• Mano : Carta*
• levantarMano

Métodos
• Void JugarCarta(numeroCartasPorJugador, carta*)
• Void LevantarMano(numeroShuriken, sincronizacion)

⸻

Clase: Equipo

Atributos
• jugador : Jugador*
• Bool Sincronizar

Métodos
• Bool Sincronizar(sincronizar, jugador*)

⸻

Inicio del Juego (Reglas)
• El juego inicia con 2 vidas y 1 shuriken.
• Las vidas y los shurikens no pueden ser negativos.
• Número de jugadores: 2 (fijo).

⸻

Recompensas por Nivel
• Nivel 1 → +1 Vida
• Nivel 2 → +1 Shuriken
• Nivel 3 → +1 Vida
• Nivel 4 → +1 Shuriken
• Nivel 5 → Nivel Final