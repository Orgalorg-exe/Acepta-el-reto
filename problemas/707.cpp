#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

//Búsqueda en el espacio de soluciones

//¿tenemos enemigos para todos?
bool hayEnemigosParaTodos(std::vector<int> const& v, int e, int n, int m) {
	int numBatallas = 0;
	int i = 0;

	while (numBatallas <= n && i < e) {
		numBatallas += std::ceil((double)v[i] / (double)m);
		++i;
	}

	return n >= numBatallas;
}

//Si admitimos un máximo de k enemigos por cada aliado
int busquedaBinaria(std::vector<int> const&v, int e, int n) {

	int ini = -1, fin = v[0], m;

	while (fin - ini != 1) {
		m = (fin + ini) / 2;
		if (m != 0 && hayEnemigosParaTodos(v, e, n, m))
			fin = m;
		else
			ini = m;
	}

	return fin;
}

bool resuelveCaso() {
	int n, e;
	std::cin >> n;

    if (!std::cin)
        return false;

	std::cin >> e;

	std::vector<int> v(e);
	for (int i = 0; i < e; ++i)
		std::cin >> v[i];
	std::sort(v.begin(), v.end(), std::greater<int>());

    int sol = busquedaBinaria(v, e, n);

	std::cout << sol << "\n";

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}