#include <iostream>
using namespace std;

const int MAX_TAM = 1000000;
int v[MAX_TAM], n, d;

string caminandoVoy(int v[], int n, int d);

int main() {

	cin >> d >> n;

	while (cin) {

		for ( int i = 0; i < n; i++) {
			cin >> v[i];
		}

		cout << caminandoVoy(v, n, d) << endl;

		cin >> d >> n;
	}

	return 0;
}

string caminandoVoy(int v[], int n, int d) {

	string ret = "APTA";
	int a = 0, b = 1;

	while ((b < n) && (v[b] - v[a] <= d)) {
		
		if ((b +1 < n) && v[b + 1] <= v[b]) {
			++b;
			a = b;
		}

		if ((a + 1 < n) && (v[a + 1] < v[a]))
			++a;

		++b;
	}

	if (b < n)
		ret = "NO APTA";

	return ret;
}