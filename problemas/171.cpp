#include <iostream>
#include <iomanip>
#include <fstream>

const int MAX = 100000;

int resolver(int n, int v[]) {

	int ret = 0, max = 0;

	while (n > 0) {
		--n;
		if (v[n] > max) {
			max = v[n];
			++ret;
		}
	}

	return ret;
}

bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
	int* v = new int[MAX];
	std::cin >> n;

    if (!n)
        return false;

	for(int i = 0; i < n; ++i) 
		std::cin >> v[i];

	int sol = resolver(n, v);

    // escribir sol
    std::cout << sol << '\n';

	delete[] v;
    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}
