#include <iostream>
using namespace std;

int calc[9][4] = { 
	{2, 3, 4, 7},
	{1, 3, 5, 8},
	{1, 2, 6, 9},
	{1, 5, 6, 7},
	{2, 4, 6, 8},
	{3, 4, 5, 9},
	{1, 4, 8, 9},
	{2, 5, 7, 9},
	{3, 6, 7, 8} };

bool calculadora(int total, int ant);

int main() {
	int total, ant;
	int numCasos;
	cin >> numCasos;

	for (; numCasos > 0; --numCasos) {

		cin >> total >> ant;

		if (calculadora(total, ant))
			cout << "GANA" << endl;
		else
			cout << "PIERDE" << endl;
	}

	return 0;
}


bool calculadora(int total, int ant) {

	//Caso base
	if (total == 31) return true;

	//Caso recursivo
	
	bool ganaRival = true;
	//Busco todos los n�meros que permitan continuar las partida
	int i = 0;
	while (i < 4 && ganaRival) {
		// Si es prometedor
		if (total + calc[ant - 1][i] < 31) {
			ganaRival &= calculadora(total + calc[ant - 1][i], calc[ant - 1][i]);
		}
		++i;
	}

	return !ganaRival;
}