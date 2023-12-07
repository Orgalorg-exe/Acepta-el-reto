#include <iostream>
#include <iomanip>
#include <fstream>

const char letra[] =
{ 'T', 'R', 'W', 'A',
'G', 'M', 'Y', 'F', 'P',
'D', 'X', 'B', 'N', 'J',
'Z', 'S', 'Q', 'V', 'H',
'L', 'C', 'K', 'E' };

// VA contar soluciones
int resolver(
	//Datos
	std::string dni, 
	//Sol Parcial
	int dniParcial, int k
) {
	int ret = 0;

	while (isdigit(dni[k])) {
		dniParcial = dniParcial * 10 + ((int)dni.at(k) - (int)'0');
		++k;
	}

	if (dni[k] == '?') {
		for (int i = 0; i < 10; ++i) {
			dniParcial = dniParcial * 10 + i;
			ret += resolver(dni, dniParcial, k + 1);
			dniParcial /= 10;
		}
	}
	else if (dni[k] == letra[dniParcial % 23])
		ret = 1;

	return ret;
}

void resuelveCaso() {
	std::string DNI;
	std::cin >> DNI;

	int sol = resolver(DNI, 0, 0);

	std::cout << sol << std::endl;
}

int main() {

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();

	return 0;
}