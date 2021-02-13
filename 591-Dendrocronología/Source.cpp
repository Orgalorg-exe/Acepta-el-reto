#include <iostream>

using namespace std;

void resuelveCaso(unsigned long long v[], int n, int y, int x);

const int MAX = 750;

int main() {

	unsigned long long ret[MAX]{};
	int n, c;

	cin >> n;

	while (cin) {
		if (n > 0) {
			c = (n - 1) / 2;
			for (int i = 0; i <= c; ++i) {
				ret[i] = 0;
			}

			for (int y = 0; y <= c; ++y) {
				resuelveCaso(ret, n, y, 0);
			}

			if (n % 2 == 0) {
				for (int y = c; y > -1; --y) {
					resuelveCaso(ret, n, y, 0);
				}
			}
			else {
				for (int y = c - 1; y > -1; --y) {
					resuelveCaso(ret, n, y, 0);
				}
			}

			cout << ret[c];
			for (int i = c - 1; i > -1; --i)
				cout << " " << ret[i];
			cout << endl;
		}
		else
			cout << 0 << endl;

		cin >> n;
	}

	return 0;
}

void resuelveCaso(unsigned long long v[], int n, int y, int x) {

	long long num;

	//Caso base
	if (x == y) {
		for (int i = x; i < n; ++i) {
			cin >> num;
			v[x] += num;
		}
		return;
	}

	//Caso recursivo
	cin >> num;
	v[x] += num;

	resuelveCaso(v, n - 1, y, x + 1);

	cin >> num;
	v[x] += num;
}