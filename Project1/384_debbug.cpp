#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 500000;

bool puedePerder(int v[], int o, int n, int posMax);

bool puedePerder(int v[], int n, int& posMin, int& posMax, int rangos[], int& m);
bool nEnRangos(int rangos[], int& m, int k);

int main() {
	int n = 8, posMax;
	int v[] = {1, 2, 3, 5, 8, 13, 21, 34};

	int m, fooPosMax, fooPosMin;
	int* w = new int[MAX];

	do {
		posMax = *max_element(v, v + n);
		for (int i = 0; i < n; ++i) cout << v[i] << " ";
		cout << endl << puedePerder(v, n, fooPosMin, fooPosMax, w, m) << endl;
	} while (next_permutation(v, v + n));

	delete[] w;
	return 0;
}

bool puedePerder(int v[], int o, int n, int posMax) {

	//Caso base
	if (n - o < 3)
		return false;


	//Caso recursivo
	int posMinIzq = o, posMaxIzq = o, posMaxDer = posMax + 1;
	// posMax + 1 podría ser n

// posMaxIzq y posMinDer
	for (int i = o; i < posMax; ++i) {
		posMinIzq = (v[posMinIzq] < v[i]) ? posMinIzq : i;
		posMaxIzq = (v[posMaxIzq] > v[i]) ? posMaxIzq : i;
	}

	// posMaxDer
	if (posMax + 1 == n)
		posMaxDer = posMax;
	else {
		for (int i = posMax + 1; i < n; ++i) {
			posMaxDer = (v[posMaxDer] > v[i]) ? posMaxDer : i;
		}
	}

	if (!((v[posMinIzq] < v[posMaxDer]) && (v[posMaxDer] < v[posMax])))
		return puedePerder(v, o, posMax, posMaxIzq) || puedePerder(v, posMax + 1, n, posMaxDer);
	return true;
}




// 3 <= n <= longitud(v)	
bool puedePerder(int v[], int n, int& posMin, int& posMax, int rangos[], int& m) {

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
	while (i < m && !((rangos[i] < k) && (k < rangos[i + 1]))) {

		if (k > rangos[i + 1]) {
			rangos[i] = rangos[m - 2];
			rangos[i + 1] = k;
			m = i + 2;
		}

		i += 2;
	}
	return i < m;
}