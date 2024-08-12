#include <iostream>
using namespace std;

void combinaciones(int c, int v, int i, int j, string solParcial, bool& prim);

int main() {
	int c, v;
	bool foo;

	int numCasos;
	cin >> numCasos;
	for (; numCasos > 0; --numCasos) {
		cin >> c >> v;
		foo = true;
		combinaciones(c, v, 0, 0, "", foo);
		cout << endl;
	}
	return 0;
}

void combinaciones(
	//Datos del problema
	int c, int v,

	//SolParcial
	int i, int j,
	string solParcial,

	//Marcaje
	bool& prim
) {

	//Caso base
	if (i == c && j == v) {
		if (prim) {
			cout << solParcial;
			prim = false;
		}
		else {
			cout << " " << solParcial;
		}
	}

	//Caso recursivo
	if (i < c) {
		combinaciones(c, v, i + 1, j, solParcial + "C", prim);
	}
	if (j < v) {
		combinaciones(c, v, i, j + 1, solParcial + "V", prim);
	}
}