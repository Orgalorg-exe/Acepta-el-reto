#include <iostream>
using namespace std;

const int MAX = 24;

int numComb(int maxPeso, int numUvas, int uvas[], int k, int i, int pesoAcum);

int main() {
	int maxPeso, numUvas;
	int uvas[24];

	cin >> maxPeso >> numUvas;
	while (maxPeso && numUvas) {
		for (int i = 0; i < numUvas; ++i)
			cin >> uvas[i];

		cout << numComb(maxPeso, numUvas, uvas, 0, 0, 0) << endl;
		cin >> maxPeso >> numUvas;
	}

	return 0;
}

int numComb(
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
			ret += numComb(maxPeso, numUvas, uvas, k + 1, j + 1, pesoAcum + uvas[j]);

		++j;
	}

	return ret;
}