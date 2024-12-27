#include <iostream>
#include <iomanip>
#include <fstream>

const int MAX = 750;

void resolver(unsigned long long v[], int n, int y, int x) {

	long long num;

	//Caso base
	if (x == y) {
		for (int i = x; i < n; ++i) {
			std::cin >> num;
			v[x] += num;
		}
		return;
	}

	//Caso recursivo
	std::cin >> num;
	v[x] += num;

	resolver(v, n - 1, y, x + 1);

	std::cin >> num;
	v[x] += num;
}

int resuelveCaso() {

	unsigned long long ret[MAX]{};
	int n, c;

	std::cin >> n;

	if (!std::cin) return false;

	if (n > 0) {
		c = (n - 1) / 2;
		for (int i = 0; i <= c; ++i) {
			ret[i] = 0;
		}

		for (int y = 0; y <= c; ++y) {
			resolver(ret, n, y, 0);
		}

		if (n % 2 == 0) {
			for (int y = c; y > -1; --y) {
				resolver(ret, n, y, 0);
			}
		}
		else {
			for (int y = c - 1; y > -1; --y) {
				resolver(ret, n, y, 0);
			}
		}

		std::cout << ret[c];
		for (int i = c - 1; i > -1; --i)
			std::cout << " " << ret[i];
		std::cout << '\n';
	}
	else std::cout << "0\n";

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}