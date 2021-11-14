#include <iostream>
using namespace std;

const int MAX = 500000;

bool puedePerder(int v[], int n, int rangos[], int& m);
bool nEnRangos(int rangos[], int& m, int k);

int main() {
	int n, m;
	int* v = new int[MAX];
	int* w = new int[MAX];

	cin >> n;
	while (cin) {
		for (int i = 0; i < n; i++) cin >> v[i];

		if (puedePerder(v, n, w, m))
			cout << "ELEGIR OTRA\n";
		else
			cout << "SIEMPRE PREMIO\n";

		cin >> n;
	}

	delete[] w;
	delete[] v;
	return 0;
}


// 3 <= n <= longitud(v)	
bool puedePerder(int v[], int n, int rangos[], int& m) {

	int posMin = (v[0] < v[1]) ? 0 : 1;
	int posMax = (v[0] > v[1]) ? 0 : 1;

	int i = 2;
	while (i < n) {
		
	}



	//Caso base
	if (n == 2) {
		if (v[0] < v[1]) {
			posMin = 0; posMax = 1;
			rangos[0] = v[0]; rangos[1] = v[1];
			m = 2;
		}
		else {
			posMin = 1; posMax = 0;
			m = 0;
		}
		return false;
	}

	//Caso recursivo
	if (puedePerder(v, n - 1, posMin, posMax, rangos, m)) {
		return true;
	}

	if (v[n - 1] < v[posMin]) {
		posMin = n - 1;
		return false;
	}

	if (v[n - 1] > v[posMax]) {
		posMax = n - 1;
		rangos[0] = v[posMin]; rangos[1] = v[posMax];
		m = 2;
		return false;
	}

	if (!nEnRangos(rangos, m, v[n - 1])) {
		rangos[m] = v[posMin]; rangos[m + 1] = v[n - 1];
		m += 2;
		return false;
	}

	return true;
}

bool nEnRangos(int rangos[], int& m, int k) {
	int i = 0;
	while (i < m && !((rangos[i] < k) && (k < rangos[i +1]))) {

		if (k > rangos[i + 1]) {
			rangos[i] = rangos[m - 2];
			rangos[i + 1] = k;
			m = i + 2;
		}

		i += 2;
	}
	return i < m;
}
