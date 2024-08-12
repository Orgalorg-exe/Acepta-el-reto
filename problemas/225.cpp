#include <iostream>
#include <iomanip>
#include <fstream>

#define MOD 1000000007

int resolver(int n, unsigned long long x, unsigned long long y) {

	if (n == 0)
		return x;
	else if (n == 1)
		return y;

	int z = 0;

	for (int i = 1; i < n; i++) {
		z = ((x % MOD) + (y % MOD))% MOD;
		x = y; y = z;
	}

	return z;
}

bool resuelveCaso() {
    // leer los datos de la entrada
	int n;
	unsigned long long x, y;

	std::cin >> n;
    if (!std::cin)
        return false;

	std::cin >> x >> y;

    int sol = resolver(n, x, y);

    // escribir sol
	std::cout << sol << '\n';

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}
