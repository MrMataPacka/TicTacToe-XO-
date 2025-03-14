#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TaTeTi.h"

using namespace std;

namespace TaTeTi_Game {

	void InicializarTablero(TaTeTi& t) {
		for (int i = 0; i < FILAS; i++) {
			for (int j = 0; j < COLUMNAS; j++) {
				t.ticTacToe[i][j] = CELDA_VACIA;
			}
		}

		for (int i = 0; i < FILAS; i++) {
			for (int j = 0; j < COLUMNAS; j++) {
				t.empty[i][j] = true;
			}
		}
		t.estado = INICIADO;
	}


	char JugadorActual(TaTeTi& t) {
		if (t.turno == JUGADOR_X)
		{
			return JUGADOR_O;
		}
		else {
			return JUGADOR_X;
		}
	}

	EstadoJuego EstadoActual(const TaTeTi& t) {
		switch (t.estado) {
		case INICIADO:
			return INICIADO;

		case FINALIZADO:
			return FINALIZADO;

		case EMPATE:
			return EMPATE;

		}
	}

	void ImprimirTablero(TaTeTi& t) {
		cout << "\n\t\t  " << 1 << " " << 2 << " " << 3 << " " << "\n";
		for (int i = 0; i < FILAS; i++) {
			cout << "\t\t" << i + 1;
			for (int j = 0; j < COLUMNAS; j++) {
				cout << " " << t.ticTacToe[i][j];
			}
			cout << "\n";
		}
	}

	bool EsCeldaValida(int fila, int columna, const TaTeTi& t) {

		if (!t.empty[fila][columna]) {
			cout << "\nERROR Ingrese una posicion vacia\n";
			return false;
		}

		if (fila < 0 || fila >= FILAS || columna < 0 || columna >= COLUMNAS)
		{
			cout << "\nERROR Ingrese una posicion valida\n";
			return false;
		}
		else {
			return true;
		}
	}

	bool HayMovimientosPosibles(const TaTeTi& t) {
		int contadorTablero = 0;
		for (int i = 0; i < FILAS; i++) {
			for (int j = 0; j < COLUMNAS; j++) {
				if (!t.empty[i][j]) contadorTablero++;

			}
		}
		if (contadorTablero == MAXIMOS_LUGARES) {
			return false;
		}
		else {
			return true;
		}
	};

	bool VerificarAlienacion(const TaTeTi& t) {
		for (int i = 0; i < FILAS; i++) {
			if (t.ticTacToe[i][0] == t.turno && t.ticTacToe[i][1] == t.turno && t.ticTacToe[i][2] == t.turno) {
				return true;
			}
		}

		for (int i = 0; i < COLUMNAS; i++) {
			if (t.ticTacToe[0][i] == t.turno && t.ticTacToe[1][i] == t.turno && t.ticTacToe[2][i] == t.turno) {
				return true;
			}
		}

		if (t.ticTacToe[0][0] == t.turno && t.ticTacToe[1][1] == t.turno && t.ticTacToe[2][2] == t.turno) {
			return true;
		}
		else if (t.ticTacToe[2][0] == t.turno && t.ticTacToe[1][1] == t.turno && t.ticTacToe[0][2] == t.turno) {
			return true;
		}

		return false;
	}

	void RealizarMovimiento(int fila, int columna, TaTeTi& t) {
		t.ticTacToe[fila][columna] = t.turno;
		t.empty[fila][columna] = false;

		if (VerificarAlienacion(t)) {
			t.estado = FINALIZADO;
		}
		else if (!HayMovimientosPosibles(t)) {
			t.estado = EMPATE;
		}
		else {
			t.turno = JugadorActual(t);
		}
	}
}