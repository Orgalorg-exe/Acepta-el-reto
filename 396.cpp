#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 100000;

int busquedaBinaria(int v[], int n, int numPartituras);
bool hayPartiturasParaTodos(int v[], int n, int numPartituras, int m);

int main() {
	int n, k;
	int* v = new int[MAX];

	cin >> k >> n;
	while (cin) {
		for (int i = 0; i < n; ++i) cin >> v[i];

		sort(v, v + n, greater<int>());
		cout << busquedaBinaria(v, n, k) << endl;

		cin >> k >> n;
	}

	delete[] v;
	return 0;
}


//Búsqueda en el espacio de soluciones


//Si admitimos un máximo de k personas en un atril
int busquedaBinaria(int v[], int n, int numPartituras) {

	int ini = -1, fin = (n == 0) ? 0 : v[0], m;

	while (fin - ini != 1) {
		m = (fin + ini) / 2;
		if (m != 0 && hayPartiturasParaTodos(v, n, numPartituras, m))
			fin = m;
		else
			ini = m;
	}

	return fin;
}

//¿tenemos partituras para todos?
bool hayPartiturasParaTodos(int v[], int n, int numPartituras, int m) {
	int numAtriles = 0;
	int i = 0;

	while (numAtriles <= numPartituras && i < n ) {
		// nAtr += nMusic / maxMuicPorAtr
		numAtriles += ceil((float)v[i] / (float) m);
		++i;
	}

	return numPartituras >= numAtriles;
}