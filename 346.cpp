#include <iostream>

using namespace std;

const int MAX_TAM = 200000;
int v[MAX_TAM], n, k;

int nacimientosConSeisDedos(int v[], int n, int k);

int main() {

	cin >> n >> k;

	while ( n != 0 && k != 0)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
		}
		
		cout << nacimientosConSeisDedos(v, n, k) << endl;

		cin >> n >> k;
	}

	return 0;
}

int nacimientosConSeisDedos(int v[], int n, int k) {
	int ret = 1;
	int a = 0, b = 1;

	while (a <= b && b < n)
	{
		if (v[b] - v[a] < k) {
			++b;
		}
		else {
			++a;
		}

		if (b - a > ret) {
			ret = b - a;
		}
	}

	return ret;
}