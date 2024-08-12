#include <iostream>

using namespace std;

const int MAX = 300000;


int minUvas(int v[], int n, int k, int sumTotal);

int main() {
	int* v = new int[MAX];
	int n, k, sum;
	cin >> n >> k;

	while (n != 0) {

		sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			sum += v[i];
		}

		if (sum < k) {
			cout << "IMPOSIBLE\n";
		}
		else {
			cout << minUvas(v, n, k, sum) << endl;
		}

		cin >> n >> k;
	}

	delete[] v;

	return 0;
}

//Ventana deslizante
int minUvas(int v[], int n, int k, int sumTotal) {

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