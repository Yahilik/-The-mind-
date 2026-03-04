# -The-mind-

Conceptualización 

Clases 
Juego
Atributos
-Int NivelActual
-Int Vidas
-Int shurikens
-String EstadoJuego
Métodos 
+Void iniciarjuego()
+String PerderVida(Número de vidas)
+Void UsarShuriken(número de shuriken, sincronización)
+Void AplicarRecompensa(Nivel actual)
+void VerificarOrdenCartas(mano, numero de cartas por jugador)

Nivel 
Atributos
-int NumeroNivel
-Int CartasPorJugador
-Int recompensavida
-Int RecompensaShuriken
Método
+Void CompletarNivel(nivel actual)
+String DarRecompensa(nivel actual, recompensa en vida, recompensa Shuriken)

Mazo
Atributos
-Int Carta*
Método
+Void Barajar(numero de cartas)
+String Repartir(numero de jugadores, nivel actual)

Carta
Atributo 
-Int numero de cartas
Método 
+string mostrar(numero de cartas por jugador, mano)

Jugador
Atributos
-Int IdJugador
-Mano: Carta*
-levantarMano
Método 
+Void JugarCarta(numero de cartas por jugador, carta*)
+Void LevantarMano(número shuriken, sincronización)

Equipo
Atributos
-jugador: jugador*
-bool Sincronizar
Método
+bool Sincronizar(sincronizar, jugador*)

Inicio del juego: el juego iniciará con 2 vidas y 1 shuriken. 
Las vidas y los shuriken no pueden ser negativos. 
Numero de jugadores: 2 por defecto sin posibilidad de aumentar o disminuir. 
Las recompensas se intercalaran por nivel iniciando con una vida al completar el nivel 1 y obteniendo la ultima recompensa en el nivel 4 antes de jugar el ultimo nivel (5)
