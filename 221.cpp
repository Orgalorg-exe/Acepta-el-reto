#include <iostream>

using namespace std;

const int MAX = 10000;

bool puedeAbrir(int n, int v[], int &k);

int main() {

	int n, k;
	int *v = new int[MAX];

	int numCasos;
	cin >> numCasos;

	for (; numCasos > 0; --numCasos) {
		k = 0;
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> v[i];

		if (puedeAbrir(n, v, k))
			cout << "SI " << k << endl;
		else
			cout << "NO" << endl;
	}

	delete[] v;

	return 0;
}

bool puedeAbrir(int n, int v[], int& k) {
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