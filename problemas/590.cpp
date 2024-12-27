#include <iostream>

const int MAX = 300000;

int resolver(int v[], int n, int k, int sumTotal) {

	int ret = sumTotal;
	int a = 0, b = 0;
	int suma = 0;

	while (b < n || suma >= k) {

		if (suma < k) {
			suma += v[b];
			++b;
		}
		else {
			ret = suma < ret ? suma : ret;

			suma -= v[a];
			++a;
		}
	}

	return ret;
}

bool resuelveCaso() {
	int* v = new int[MAX];
	int n, k, sum;
	std::cin >> n >> k;

	if (!n) return false;

	sum = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> v[i];
		sum += v[i];
	}

	if (sum < k) std::cout << "IMPOSIBLE\n";
	else std::cout << resolver(v, n, k, sum) << '\n';

	delete[] v;
	return true;
}


int main() {

	while (resuelveCaso());

	return 0;
}