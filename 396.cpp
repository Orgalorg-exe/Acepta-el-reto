#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_TAM = 100000;
int v[MAX_TAM], n, k;

int busquedaBinaria(int v[], int n, int k);
bool hayAtrilesParaTodos(int v[], int n, int k, int m);

int main() {

	cin >> k >> n;

	while (cin) {

		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}

		sort(v, v + n, greater<int>());
		cout << busquedaBinaria(v, n, k) << endl;

		cin >> k >> n;
	}

	return 0;
}


//Si admitimos un máximo de k personas en un atril
int busquedaBinaria(int v[], int n, int k) {

	int ini = -1, fin = v[0], m;

	while (fin - ini != 1) {
		m = (fin + ini) / 2;
		if (m != 0 && hayAtrilesParaTodos(v, n, k, m))
			fin = m;
		else
			ini = m;
	}

	if (n == 0)
		fin = 0;

	return fin;
}

//¿tenemos atriles para todos?
bool hayAtrilesParaTodos(int v[], int n, int k, int m) {

	int count = 0;
	int i = 0;

	while (count <= k && v[i] > m && i < n) {

		count += v[i] / m;

		if (v[i] % m != 0)
			++count;

		++i;
	}
	count += n - i;

	return count <= k;
}