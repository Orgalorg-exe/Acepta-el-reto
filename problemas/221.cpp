#include <iostream>
#include <iomanip>
#include <fstream>

const int MAX = 10000;

bool resolver(int n, int v[], int& k) {
	bool ret = true, zonaPar = true;
	int i = 0;

	while (i < n && ret) {
		if (v[i] % 2 == 0) {
			if (zonaPar) ++k;
			else ret = false;
		}
		else zonaPar = false;

		++i;
	}

	return ret;
}

int resuelveCaso() {

	int n, k;
	int *v = new int[MAX];

	k = 0;
	std::cin >> n;
	for (int i = 0; i < n; ++i) 
		std::cin >> v[i];

	bool sol = resolver(n, v, k);

	if (sol)
		std::cout << "SI " << k << '\n';
	else
		std::cout << "NO" << '\n';

	delete[] v;

	return 0;
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}