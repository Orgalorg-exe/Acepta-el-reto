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

int nacimientosConSeisDedos(int v[], int n, int k) {
	int ret = 0;
	int a = 0, b = 0;

	while (a <= b && b < n) {
		if (v[b] - v[a] < k) { ++b; }
		else { ++a; }

		ret = (b - a > ret) ? b - a : ret;
	}

	return ret;
}
