#include<iostream>
using namespace std;

const int MAX = 200000;

bool esApta(int n, int v[], int d);
string caminandoVoy(bool esApta);


int main() {
	int n, d;
	int* v = new int[MAX];
	cin >> d >> n;

	while (cin) {
		for (int i = 0; i < n; i++) { cin >> v[i]; }
		cout << caminandoVoy(esApta(n, v, d)) << endl;
		cin >> d >> n;
	}

	delete[] v;
	return 0;
}


// { Pre: 0 <= n <= longitud(v) ^ 0 <= d }
bool esApta(int n, int v[], int d) {
	bool ret;
	int a = 0, b = 0;
	// { I :
	// }

	// O(n)
	while ((b < n) && (v[b] - v[a] <= d)) {

		while ((b + 1 < n) && v[b + 1] <= v[b]) {
			++b;
			a = b;
		}

		++b;
	}

	ret = !(b < n);

	return ret;
}
/* { Pos: P.t. i,j : 0 <= i <= j < n : } */


string caminandoVoy(bool esApta) {
	if (esApta)
		return "APTA";
	return "NO APTA";
}

