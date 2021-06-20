//DATOS PREVIOS

//includes
#include <iostream>
#include <algorithm>

using namespace std;

//constantes y variables
const int MAX_TAM = 25000;

//Declaración de la función
int moda(int n, int v[]);
void lecturaDelVector(const int n, int v[]);

//MAIN
int main() {

	int n, v[MAX_TAM];
	cin >> n;

	while (n != 0) {
		lecturaDelVector(n, v);
		sort(v, v + n);
		cout << moda(n, v) << endl;

		cin >> n;
	}

	return 0;
}

//IMPLEMENTACIÓN DE LA FUNCIÓN SOLUCIÓN
//DETALLES DE LA SOLUCIÓN

//pre
int moda(int n, int v[]) {
	//Invariante
	//
	int ret = v[0];
	int countAct = 1, countMax = 1;
	int i = 1;

	//Complejidad
	// O(n)
	// se recorre el vector
	while (i < n) {

		if (v[i] == v[i - 1]) {
			++countAct;
			if (countAct > countMax) {
				ret = v[i];
			}
		}
		else {
			if (countAct > countMax) {
				countMax = countAct;
			}
			countAct = 1;
		}

		++i;
	}

	return ret;
}
//post 

void lecturaDelVector(const int n, int v[]) {
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
}