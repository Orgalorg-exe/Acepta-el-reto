#include <iostream>
using namespace std;

const int MAX = 50;
const char SOL = 'a', SOMBRA = 'b', ARBOL = 'c';

int numSombras(char v[][MAX], int c, int f, int n);

int main() {

	char v [MAX][MAX];
	int c, f, n;

	cin >> c >> f >> n;
	while (c) {
		for (int i = 0; i < c * f; ++i)
			v[i / c][i % c] = SOL;

		cout << numSombras(v, c, f, n) << endl;

		cin >> c >> f >> n;
	}

	return 0;
}

int numSombras(char v[][MAX], int c, int f, int n) {
	int ret = 0;
	int x = 0, y = 0;

	while (n) {
		cin >> x >> y;

		x -= 1; y -= 1;

		if (y - 1 >= 0) {
			if (x - 1 >= 0 && v[y - 1][x - 1] == SOL) {
				++ret;
				v[y - 1][x - 1] = SOMBRA;
			}

			if (v[y - 1][x] == SOL) {
				++ret;
				v[y - 1][x] = SOMBRA;
			}

			if (x + 1 < c && v[y - 1][x + 1] == SOL) {
				++ret;
				v[y - 1][x + 1] = SOMBRA;
			}
		}


		if (x - 1 >= 0 && v[y][x - 1] == SOL) {
			++ret;
			v[y][x - 1] = SOMBRA;
		}

		if (v[y][x] == SOMBRA) {
			--ret;
			v[y][x] = ARBOL;
		}
		else if (v[y][x] == SOL) {
			v[y][x] = ARBOL;
		}

		if (x + 1 < c && v[y][x + 1] == SOL) {
			++ret;
			v[y][x + 1] = SOMBRA;
		}

		if (y + 1 < f) {
			if (x - 1 >= 0 && v[y + 1][x - 1] == SOL) {
				++ret;
				v[y + 1][x - 1] = SOMBRA;
			}

			if (v[y + 1][x] == SOL) {
				++ret;
				v[y + 1][x] = SOMBRA;
			}

			if (x + 1 < c && v[y + 1][x + 1] == SOL) {
				++ret;
				v[y + 1][x + 1] = SOMBRA;
			}
		}

		--n;
	}

	return ret;
}