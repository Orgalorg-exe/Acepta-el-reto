#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>

#define MAX 128

int numBarcos;
std::map<int, int> barcos;
int gridLen;
int grid[MAX][MAX];

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

bool resolver() {
	int barcoLen;
	int x, y;

	//Recorro de arriba a abajo, de izquierda a derecha
	for (int i = 0; i < gridLen; i++) {
		for (int j = 0; j < gridLen; j++) {

			//Cuando encuentra un barco
			if (grid[i][j] == 1) {
				grid[i][j] = 0;

				barcoLen = 1;
				x = j; y = i;

				// Comprueba las diagonales
				if (hayBarcoAbajoDer(y, x) || hayBarcoAbajoIzq(y, x)) return false;

				//El barco solo puede continuar hacia la derecha o hacia abajo
				if (hayBarcoDer(y, x)) {
					// Comprueba que no haya también abajo
					if (hayBarcoAbajo(y, x)) return false;

					//Mientras continue a la derecha
					while (hayBarcoDer(y, x)) {
						//Me desplazo a la derecha
						x++;
						grid[y][x] = 0;
						barcoLen++;

						//Y compruebo que no hay otro barco en la diagonal
						if (hayBarcoAbajoDer(y, x)) return false;
					}
				}
				else if (hayBarcoAbajo(y, x)) {
					// Si hubiera un barco en la derecha, habría entrado en el primer if

					while (hayBarcoAbajo(y, x)) {
						//Me desplazo abajo
						y++;
						grid[y][x] = 0;
						barcoLen++;

						// Y compruebo que no hay barcos en las diagonales
						if (hayBarcoAbajoIzq(y, x) || hayBarcoAbajoDer(y, x)) return false;
					}
				}

				//Si no era un barco
				if (barcos.find(barcoLen) == barcos.end() || barcos[barcoLen] <= 0)
					return false;

				barcos[barcoLen]--;
			}
		}
	}

	//Si queda algun barco por poner
	for (std::map<int, int>::iterator it = barcos.begin(); it != barcos.end(); it++) {
		if (it->second > 0) return false;
	}

	return true;
}


bool resuelveCaso() {
	barcos.clear();
	//grid.clear();

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
	for (int i = 0; i < gridLen; i++) {
		for (int j = 0; j < gridLen; j++) {
			std::cin >> grid[i][j];
		}
	}

	bool sol = resolver();


	if (sol) std::cout << "SI\n";
	else std::cout << "NO\n";

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}