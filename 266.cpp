#include <iostream>

using namespace std;

const int MAX = 500;

void procesarCopistas(char v[]);

int main() {

	char* v = new char[MAX * MAX];
	int x = 0, y = 0;

	cin >> y >> x;

	while (x != 0 && y != 0) {
		char alpha[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
					       'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
					       'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
		//Guardo la matriz
		for (int i = 0; i < y; ++i) {
			for (int j = 0; j < x; ++j) {
				cin >> v[j + x*i];
			}
		}

		//Algoritmo
		procesarCopistas(alpha);

		//Imprimo la matriz
		for (int i = 0; i < y; ++i) {
			for (int j = 0; j < x; ++j) {
				cout << alpha[v[j + x*i] - 'A'];
			}
			cout << endl;
		}

		cin >> y >> x;
	}
	
	delete[] v;

	return 0;
}

void procesarCopistas(char v[]) {

	int numCopistas = 0;
	cin >> numCopistas;

	char in, out;

	for (int i = 0; i < numCopistas; ++i) {
		cin >> in >> out;
		for (int j = 0; j < 26; ++j) {
			if (v[j] == in) v[j] = out;
		}
	}
}