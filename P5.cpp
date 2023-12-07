#include <iostream>
#include <algorithm> // std::max
using namespace std;

const int MAX = 3000;

bool maxP(int v[], int ini, int fin, int& p);

int main() {
	int n, v[MAX], p;

	int numCasos;
	cin >> numCasos;
	for (; numCasos > 0; --numCasos) {

		cin >> n;
		for (int i = 0; i < n; ++i) cin >> v[i];
		p = 0;

		if (maxP(v, 0, n, p)) {
			cout << p << endl;
		}
		else {
			cout << "NO HAY NINGUNO\n";
		}
	}

	return 0;
}

bool maxP(int v[], int ini, int fin, int& p) {
	//Caso Base
	if (fin - ini < 3) {
		return false;
	}
	else if (fin - ini == 3) {
		if (v[ini] < v[ini + 1] + v[ini + 2] &&
			v[ini + 1] < v[ini] + v[ini + 2] &&
			v[ini + 2] < v[ini] + v[ini + 1]
			) {
			p = v[ini] + v[ini + 1] + v[ini + 2];
			return true;
		}
		return false;
	}

	//Caso recursivo
	int m = (fin + ini) / 2;

	int pIzq, pDer;
	bool izq = 
}

/*
int maxP(int v[], int n) {
	int ret = 0;
	int i = 3;

	if (n >= 3) {
		int a = v[0], b = v[1], c = v[2];
		if (a < b + c &&
			b < a + c &&
			c < a + b
		) {
			ret = a + b + c;
		}

		while (i < n) {
			int aAux = 0, bAux = 0, cAux = 0, may = 0;

			if (v[i] < b + c &&
				b < v[i] + c &&
				c < v[i] + b &&
				(a < v[i] || ret == 0)
				) {
				aAux = v[i];
			}

			if (a < v[i] + c &&
				v[i] < a + c &&
				c < a + v[i] &&
				(b < v[i] || ret == 0)
				) {
				bAux = v[i];
			}

			if (a < b + v[i] &&
				b < a + v[i] &&
				v[i] < a + b &&
				(c < v[i] || ret == 0)
			) {
				cAux = v[i];
			}


			if (aAux || bAux || cAux) {
				may = max(a + b + cAux, max(a + bAux + c, aAux + b + c));
				ret = may;
				if (may = a + b + cAux)
					c = cAux;
				else if (may = a + bAux + c)
					b = bAux;
				else
					a = aAux;
			}

			++i;
		}
	}

	return ret;
}
*/
