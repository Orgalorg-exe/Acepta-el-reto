#include <iostream>
#include <iomanip>
#include <fstream>

void resolver(
	//Datos del problema
	int c, int v,

	//SolParcial
	int i, int j,
	std::string solParcial,

	//Marcaje
	bool& prim
) {

	//Caso base
	if (i == c && j == v) {
		if (prim) {
			std::cout << solParcial;
			prim = false;
		}
		else {
			std::cout << " " << solParcial;
		}
	}

	//Caso recursivo
	if (i < c) {
		resolver(c, v, i + 1, j, solParcial + "C", prim);
	}
	if (j < v) {
		resolver(c, v, i, j + 1, solParcial + "V", prim);
	}
}

void resuelveCaso() {
    // leer los datos de la entrada
	int c, v;
	bool foo;

	std::cin >> c >> v;
	foo = true;
	resolver(c, v, 0, 0, "", foo);
	std::cout << '\n';
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}