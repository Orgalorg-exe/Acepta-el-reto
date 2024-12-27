#include <iostream>
#include <iomanip>
#include <fstream>

const int MAX = 24;


int resolver(
	//Datos del problema
	int maxPeso,
	int numUvas,
	int uvas[],

	//Sol Parcial
	int k,
	int i,

	//Marcaje
	int pesoAcum
) {
	//Caso base
	if (k == 12) {
		return 1;
	}

	//Caso recursivo
	int ret = 0;
	int j = i;
	while (j < numUvas && numUvas - j >= 12 - k) {
		if (pesoAcum + uvas[j] <= maxPeso)
			ret += resolver(maxPeso, numUvas, uvas, k + 1, j + 1, pesoAcum + uvas[j]);
		++j;
	}

	return ret;
}


bool resuelveCaso() {
	int maxPeso, numUvas;
	int uvas[24];

	std::cin >> maxPeso >> numUvas;

	if (!maxPeso && !numUvas)
		return false;

	for (int i = 0; i < numUvas; ++i)
		std::cin >> uvas[i];

	int sol = resolver(maxPeso, numUvas, uvas, 0, 0, 0);

	std::cout << sol << '\n';

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}