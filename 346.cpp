#include<iostream>
using namespace std;

const int MAX = 200000;

int nacimientosConSeisDedos(int v[], int n, int k);

int main() {
	int n, k;
	int* v = new int[MAX];

	cin >> n >> k;

	while (n != 0 && k != 0) {
		for (int i = 0; i < n; ++i) { cin >> v[i]; }
		cout << nacimientosConSeisDedos(v, n, k) << endl;
		cin >> n >> k;
	}

	delete[] v;
	return 0;
}

//Ventana deslizante
/* { Pre: 0 <= n <= longitud(v), 0 < k} */
int nacimientosConSeisDedos(int v[], int n, int k) {
	//Invariante
	//
	int ret = 0;
	int a = 0, b = 0;


	// O(n)
	while (a <= b && b < n) {
		if (v[b] - v[a] < k) { ++b; }
		else { ++a; }

		ret = (b - a > ret) ? b - a : ret;
	}

	return ret;
}
/*{ Pos: max i,j: 0 <= i <= j < n: v[j] - v[i] < k }*/