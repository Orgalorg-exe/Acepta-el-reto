#include <iostream>

using namespace std;

int ini, fin, k;

bool adivinaElNumero(int ini, int fin, int k);

int main() {

	cin >> ini >> fin >> k;

	while (ini != 0 && fin != 0 && k != 0) {

		if (adivinaElNumero(ini, fin + 1, k))
			cout << "LO SABE" << endl;
		else
			cout << "NO LO SABE" << endl;

		cin >> ini >> fin >> k;
	}

	return 0;
}

bool adivinaElNumero(int ini, int fin, int k) {

	int a = ini, b = fin;
	int n, v;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		
		cin >> v;

		if (a < v && v <= k)
			a = v;
		else if (k < v && v < b)
			b = v;
	}

	return b - a == 1;
}