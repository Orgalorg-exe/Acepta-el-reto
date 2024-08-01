#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <map>

int numBarcos;
std::map<int, int> barcos;
int gridLen;
std::vector<std::vector<int>>grid;

bool hayBarcoDer(int i, int j) {
	if (j + 1 < gridLen && grid[i][j + 1] == 1) return true;
	return false;
}

bool hayBarcoAbajoDer(int i, int j) {
	if (i + 1 < gridLen && j + 1 < gridLen && grid[i + 1][j + 1] == 1) return true;
	return false;
}

bool hayBarcoAbajo(int i, int j) {
	if (i + 1 < gridLen && grid[i + 1][j] == 1) return true;
	return false;
}

bool hayBarcoAbajoIzq(int i, int j) {
	if (i + 1 < gridLen && j - 1 >= 0 && grid[i + 1][j - 1] == 1) return true;
	return false;
}

bool correcto() {
	//Recorro de arriba a abajo, de izquierda a derecha
	for (int i = 0; i < gridLen; i++) {
		for (int j = 0; j < gridLen; j++) {

			//Cuando encuentra un barco
			if (grid[i][j] == 1) {
				grid[i][j] = 0;

				int barcoLen = 1;
				int x = j, y = i;

				//El barco solo puede continuar hacia la derecha o hacia abajo

				//Si continua hacia la derecha
				while (hayBarcoDer(y, x)) {
					//Si no toca con otro barco
					if (hayBarcoAbajoIzq(y, x) || hayBarcoAbajo(y, x) || hayBarcoAbajoDer(y, x)) return false;

					//Me desplazo a la derecha
					x++;
					grid[y][x] = 0;
					barcoLen++;

					//Y compruebo que no hay otro barco en la diagonal
					if (hayBarcoAbajoDer(y, x)) return false;
				}

				// Si no entro en el bucle anterior
				//		x = j, y = i
				// Si entro en el bucle
				//		si hayBarcoAbajo return false
				//		si !hayBarcoAbajo no entra en este bucle
				while (hayBarcoAbajo(y, x)) {
					// Si no toca con otro barco
					if (hayBarcoDer(y, x) || hayBarcoAbajoIzq(y, x) || hayBarcoAbajoDer(y, x)) return false;

					//Me desplazo abajo
					y++;
					grid[y][x] = 0;
					barcoLen++;

					// Y compruebo que no hay barcos en las diagonales
					if (hayBarcoAbajoIzq(y, x) || hayBarcoAbajoDer(y, x)) return false;
				}

				//Si no era un barco
				if (barcos.find(barcoLen) == barcos.end() || barcos[barcoLen] <= 0)
					return false;

				barcos[barcoLen]--;
			}
		}
	}

	//Si queda alun barco por poner
	for (std::map<int, int>::iterator it = barcos.begin(); it != barcos.end(); it++) {
		if (it->second > 0) return false;
	}

	return true;
}

std::string resolver() {
	if (correcto()) return "SI";
	return "NO";
}

bool resuelveCaso() {
	barcos.clear();
	grid.clear();

	std::cin >> numBarcos;
	if (!numBarcos)
		return false;

	int b;
	for (int i = 0; i < numBarcos; i++) {
		std::cin >> b;
		if (barcos.find(b) == barcos.end())
			barcos.insert(std::pair<int, int>(b, 1));
		else
			barcos[b]++;
	}

	std::cin >> gridLen;
	grid = std::vector<std::vector<int>>(gridLen, std::vector<int>(gridLen));
	for (int i = 0; i < gridLen; i++) {
		for (int j = 0; j < gridLen; j++) {
			std::cin >> grid[i][j];
		}
	}

	std::string sol = resolver();

	std::cout << sol << '\n';

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}