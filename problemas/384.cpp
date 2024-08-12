#include <iostream>
using namespace std;

const int MAX = 500000;

bool puedePerder(int v[], int o, int n, int& posMin, int& posMax);

int main() {
	int n, posMin, posMax;
	int* v = new int[MAX];

	cin >> n;
	while (cin) {

		for (int i = 0; i < n; ++i) cin >> v[i];

		if (puedePerder(v, 0, n, posMin, posMax))
			cout << "ELEGIR OTRA\n";
		else
			cout << "SIEMPRE PREMIO\n";

		cin >> n;
	}

	delete[] v;
	return 0;
}

bool puedePerder(int v[], int o, int n, int& posMin, int& posMax) {

	//Caso base
	if (n - o < 3) {
		if (n - o == 0 && o != 0) {
			posMin = n - 1; posMax = n - 1;
		}
		else if (n - o < 2) {
			posMin = o; posMax = o;
		}
		else if (n - o == 2) {
			posMin = (v[o] < v[o + 1]) ? o : o + 1;
			posMax = (v[o] > v[o + 1]) ? o : o + 1;
		}
		return false;
	}


	//Caso recursivo

	posMax = o;
	for (int i = o; i < n; i++) posMax = (v[posMax] > v[i]) ? posMax : i;

	int posMinIzq, posMaxIzq, posMinDer, posMaxDer;
	
	bool pierdeIzq = puedePerder(v, o, posMax, posMinIzq, posMaxIzq);
	bool pierdeDer = puedePerder(v, posMax + 1, n, posMinDer, posMaxDer);
	bool pierde = v[posMinIzq] < v[posMaxDer] && v[posMaxDer] < v[posMax];

	posMin = (v[posMinIzq] < v[posMinDer]) ? posMinIzq : posMinDer;

	return pierdeIzq || pierde || pierdeDer;
}