#include <iostream>

const int MAX = 100000;

int resolver(int v[], int n, int k) {
	int ret = 0;
	int a = 0, b = 0;
	int ultUno = 0;
	int numCerosSeguidos = 0;

	//Coloco la ventana
	while (a < n && v[a] == 0) { ++a; }
	b = a;

	//Hago el recorrido
	while (b < n) {
		//Abro la ventana
		if (v[b]) {
			++b;
			numCerosSeguidos = 0;
			ultUno = b;
		}
		else if (numCerosSeguidos < k) {
			++b;
			++numCerosSeguidos;
		}
		//Cierro la ventana
		else {
			numCerosSeguidos = 0;
			a = ++b;
			while (a < n && v[a] == 0) { ++a; }
			ultUno = b = a;

		}

		ret = std::max(ret, ultUno - a);
	}

	return ret;
}

bool resuelveCaso() {
	int n, k;
	int* v = new int[MAX];

	std::cin >> n >> k;

	if (!n)
		return false;

	for (int i = 0; i < n; ++i) std::cin >> v[i];

	int sol = resolver(v, n, k);
	std::cout << sol << '\n';

	delete[] v;
	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}