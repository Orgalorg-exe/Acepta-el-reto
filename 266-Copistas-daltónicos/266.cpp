#include <iostream>

using namespace std;

const int MAX = 500;

void procesarCopistas(char beta[]);

int main() {

	char cuadro[MAX][MAX];
	char alpha[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

		
	int c = 0, f = 0;
	cin >> f;
	cin >> c;

	//Bucle principal
	while ((f != 0) && (c != 0)) {

		char beta[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

		
		//Guardo la matriz
		for (int i = 0; i < f; ++i) {
			for (int j = 0; j < c; ++j) {
				cin >> cuadro[i][j];
			}
		}

		//Algoritmo
		procesarCopistas(beta);

		//Imprimo la matriz
		for (int i = 0; i < f; ++i) {
			for (int j = 0; j < c; ++j) {
				//Busco la letra de cuadro en alpha e imprimo su correspondiente
				int k = 0;
				while (cuadro[i][j] != alpha[k]) {
					++k;
				}
				cout << beta[k];
			}
			cout << endl;
		}

		cin >> f;
		cin >> c;
	}
	
	return 0;
}

void procesarCopistas(char beta[]) {
	int numCopistas = 0;
	cin >> numCopistas;

	char in, out;

	//Configuro la leyenda
	for (int i = 0; i < numCopistas; ++i) {
		cin >> in;
		getchar();
		cin >> out;

		//Busco y reemplazo
		for (int j = 0; j < 26; ++j) {
			if (beta[j] == in) { beta[j] = out; }
		}
	}
}