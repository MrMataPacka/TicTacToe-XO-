#pragma once
#ifndef TaTeTi.h

const char JUGADOR_O = 'O';
const char JUGADOR_X = 'X';
const char CELDA_VACIA = '.';
const int FILAS = 3;
const int COLUMNAS = 3;
const int MAXIMOS_LUGARES = FILAS * COLUMNAS;

namespace TaTeTi_Game {
	

	enum EstadoJuego { INICIADO, FINALIZADO, EMPATE };

	struct TaTeTi {
		char ticTacToe[FILAS][COLUMNAS];
		bool empty[FILAS][COLUMNAS];
		char turno;
		EstadoJuego estado;
	};

	void InicializarTablero(TaTeTi& t);

	char JugadorActual(TaTeTi& t);

	EstadoJuego EstadoActual(const TaTeTi& t);

	void ImprimirTablero(TaTeTi& t);

	bool EsCeldaValida(int fila, int columna, const TaTeTi& t);

	bool HayMovimientosPosibles(const TaTeTi& t);

	bool VerificarAlienacion(const TaTeTi& t);

	void RealizarMovimiento(int fila, int columna, TaTeTi& t);
}
#endif