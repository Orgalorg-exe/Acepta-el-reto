#include <iostream>

using namespace std;

const int MAX = 10000;

bool haySecuencia(int n, int v[], int& ini, int& fin);

int main() {
	int n, i, f;
	int* v = new int[MAX];

	int numCasos;
	cin >> numCasos;

	for (; numCasos > 0; --numCasos) {
		i = 0; f = 0;
		cin >> n;
		for (int j = 0; j < n; ++j) cin >> v[j];

		if (haySecuencia(n, v, i, f))
			cout << ((f - i) + 1) << " -> [" << i << "," << f << "]" << endl;
		else
			cout << "SIGUE BUSCANDO" << endl;
	}

	delete[] v;

	return 0;
}

bool haySecuencia(int n, int v[], int& ini, int& fin) {
	bool ret = false, primSec = true;
	int iniAux = 0, finAux = 0, i = 0;

	while (i < n) {

		if (v[i] != 0) {
			ret = true;

			//El comienzo de la secuencia
			if (i - 1 >= 0 && v[i - 1] == 0) {
				iniAux = i;
			}

			//Secuencia de naturales positivos
			finAux = i;
		}

		else {
			//Termina sequencia
			if (i - 1 >= 0 && v[i - 1] != 0) {
				finAux = i - 1;
			}

			//Secuencia de ceros
			iniAux = i;
		}

		//Si mejor mi solución
		if ((ret && primSec) || fin - ini < finAux - iniAux) {
			fin = finAux; ini = iniAux;
			primSec = false;
		}

		++i;
	}

	return ret;
}
