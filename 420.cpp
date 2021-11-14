#include <iostream>
#include <string>

using namespace std;

const int MAX = 250000;

int numSumas(int n, int v[], int k);

int main() {

	int numCasos, n, k;
	int* v = new int[MAX];
	char c;

	cin >> numCasos;

	for (numCasos; numCasos > 0; --numCasos) {
		n = k = 0;
		cin >> k;
		c = getchar();
		c = getchar();
		while (c != '\n') {
			v[n++] = c - '0';
			c = getchar();
		}

		cout << numSumas(n, v, k) << endl;
	}

	delete[] v;
	return 0;
}

//Problema de ventana deslizante
// { Pre: 0 <= n <= longitud(v) ^ 0 < k }
int numSumas(int n, int v[], int k) {
	//Invariante
	//
	int ret = 0;
	int a = 0, b = 0;
	int sum = 0;


	// O(n)
	while (b < n) {

		if (sum + v[b] <= k) {
			sum += v[b];
			++b;
		}
		else if ( a < b) {
			sum -= v[a];
			++a;
		}
		else if (a == b){
			++a;
			++b;
			sum = 0;
		}

		ret = (sum == k) ? ret + 1 : ret;
	}

	return ret;
}
// { Pos: #i, j : 0 <= i <= j < n : k = (S h : i <= h <= j : v[h])}
