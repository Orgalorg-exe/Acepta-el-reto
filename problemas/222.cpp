#include <iostream>
#include <iomanip>
#include <fstream>

#include <math.h>

int resolver(int x, int n) {
	int ret = 1, a = 1;
	int i = 0;

	while (i < n) {
		a = (a * x) % 1000007;
		ret = (ret + a) % 1000007;
		++i;
	}

	return ret;
}

int resuelveCaso() {
	int x, n;

	std::cin >> x >> n;
	if (!std::cin)
        return false;

	int sol = resolver(x, n);

	std::cout << sol << '\n';
}

int main() {

    while (resuelveCaso());

    return 0;
}