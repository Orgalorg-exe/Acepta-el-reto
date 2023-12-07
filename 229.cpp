#include<iostream>

using namespace std;

const int MAX = 100000;

int cuentasParalelas(int n, int v[], int sum);

int main() {
	int n, sum;
	int* v = new int[MAX];
	cin >> n;

	while (n != 0) {
		sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			sum += v[i];
		}

		cout << cuentasParalelas(n, v, sum) << endl;

		cin >> n;
	}

	delete[] v;
	return 0;
}


int cuentasParalelas(int n, int v[], int sum) {

	int i = 0;
	int saldo = 0;
	int ret = 0;

	while (i <= n ) {
		if (saldo == sum) { ++ret; }

		if (i < n) {
			saldo += v[i];
			sum -= v[i];
		}

		++i;
	}

	return ret;
}
