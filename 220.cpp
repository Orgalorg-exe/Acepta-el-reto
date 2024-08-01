#include <iostream>
#include <iomanip>
#include <fstream>

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

bool calculadora(int total, int ant) {

	//Caso base
	if (total == 31) return true;

	//Caso recursivo	
	bool ganaRival = true;
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

void resuelveCaso() {
    int total, ant;
	std::cin >> total >> ant;

	if (calculadora(total, ant))
		std::cout << "GANA\n";
	else
		std::cout << "PIERDE\n";
}


int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}