#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TaTeTi.h"

using namespace std;
using namespace TaTeTi_Game;

bool LeerCoordenadas(int &fila, int &columna) {
	char inputFilas;
	char inputColumnas;
	cout << "\nCoordenadas: ";
	cin >> inputFilas;
	cin >> inputColumnas;

	if ((int(inputFilas - '1') < 0 || int(inputFilas - '1') > 9)
		&& (int(inputColumnas - '1') < 0 || int(inputColumnas - '1') > 9)) {
		cout << "\nERROR Ingrese coordenadas validas\n ";
		return false;

	}

	fila = int(inputFilas - '1');
	columna = int(inputColumnas - '1');
	return true;
}


char JugadorInicial(char JUGADOR_X, char JUGADOR_O) {
	srand(time(NULL));

	int quienVaPrimero = rand() % 2;

	if (quienVaPrimero == 0)
	{
		return JUGADOR_X;
	}
	else {
		return JUGADOR_O;
	}
}



int main() {
	TaTeTi tictactoe;
	int filas;
	int columnas;

	

	InicializarTablero(tictactoe);

	tictactoe.turno = JugadorInicial(JUGADOR_X, JUGADOR_O);


	while (tictactoe.estado==INICIADO)
	{
		cout << "Turno del jugador " << tictactoe.turno << ":";
		
		
		while (true) {
			ImprimirTablero(tictactoe);
			while (!LeerCoordenadas(filas, columnas)) ImprimirTablero(tictactoe);

			if (!EsCeldaValida(filas, columnas, tictactoe)) {
				continue;
			}
			break;
		}

		RealizarMovimiento(filas, columnas, tictactoe);

	}

	ImprimirTablero(tictactoe);

	if (tictactoe.estado==FINALIZADO) {
		cout << "FIN DE LA PARTIDA. El ganador es: " << tictactoe.turno;
	}

	else if (tictactoe.estado == EMPATE) {
		cout << "TABLERO LLENO.... NADIE GANA";
	}



}