#include <iostream>

using namespace std;

const int calc[9][4] = { {2, 3, 4, 7},
						 {1, 3, 5, 8},
						 {1, 2, 6, 9},
						 {5, 6, 1, 7},
						 {4, 6, 2, 8},
						 {4, 5, 3, 9},
						 {8, 9, 1, 4},
						 {7, 9, 2, 5},
						 {7, 8, 3, 6} };

bool calculadora(int total, int ant, bool miTurno);

int main() {

	int c, total, ant;
	cin >> c;

	for (c; c > 0; --c) {

		cin >> total >> ant;

		if (calculadora(total, ant, true))
			cout << "GANA" << endl;
		else
			cout << "PIERDE" << endl;
	}

	return 0;
}


//ant <= total
bool calculadora(int total, int ant, bool miTurno) {
	
	//Caso base: total >= 31
	if (total >= 31) {
		return miTurno;
		//Si en mi turno y total ya es mayor o igual a 31
		//es que el otro tipo perdió
	}

	//Caso recursivo: todavía se puede jugar
	bool ret, hayJugada = false;

	//Yo gano si para alguna de mis posibles jugadas, todas las suyas pierden

	//Busco todos los números que permitan continuar las partida
	for (int i = 0; i < 4; ++i) {

		if (total + calc[ant - 1][i] < 31) {
			hayJugada = true;
			ret = calculadora(total + calc[ant - 1][i], calc[ant - 1][i], !miTurno);
		}
	}

	//Yo gano si en mi turno, tengo una jugada y el otro no
	// o no es mi turno pero el otro no tiene jugadas

	return (miTurno && hayJugada && ret) || (!miTurno && !hayJugada);
}