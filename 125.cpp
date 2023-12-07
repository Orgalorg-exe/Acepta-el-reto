#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <math.h>
#include <map>

std::map<int, int> digs;

bool BackTracking(
	//Datos del problema
	int num,
	int numLength,

	//Sol parcial
	int colmillos, // solParcial
	int k //index
) {

	//Caso base
	if (k == numLength) {
		int pot10 = pow(10, (numLength / 2));
		int colm1 = colmillos / pot10;
		int colm2 = colmillos % pot10;

		bool ambosTerminanEnCero = colm1 % 10 == 0 && colm2 % 10 == 0;
		bool multCorrecta = num == colm1 * colm2;

		return multCorrecta && !ambosTerminanEnCero;
	}

	//Caso recursivo
	bool esVamp = false;
	auto it = digs.begin();

	while (it != digs.end() && !esVamp) {

		if (it->second > 0) {

			colmillos = (colmillos * 10) + it->first;
			it->second -= 1;

			esVamp |= BackTracking(num, numLength, colmillos, k + 1);

			colmillos /= 10;
			it->second += 1;
		}

		++it;
	}

	return esVamp;
}

std::string resolver(int num, int numLen){
	if (numLen % 2 == 1) return "NO"; 

	bool esVamp = BackTracking(num, numLen, 0, 0);

	if(esVamp) return "SI";

	return "NO";
}

void resuelveCaso() {
    digs.clear();

    std::string numAsString;
	int num, numLen;

	std::cin >> numAsString;
	num = std::stoi(numAsString);
	numLen = numAsString.length();

	for (char const& c : numAsString) {
		if (digs.count(c - '0') > 0) 
			digs[c - '0'] += 1;
		
		else 
			digs.insert(std::pair<int, int>(c - '0', 1));
	}
    
    std::string sol = resolver(num, numLen);
    
	std::cout << sol << '\n';
    
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}