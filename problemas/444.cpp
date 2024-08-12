#include <iostream>
using namespace std;

const int MAX = 100000;

int maxVentana(int v[], int n, int k);

int main() {
	int n, k;
	int* v = new int[MAX];

	cin >> n >> k;
	while (n != 0) {
		for (int i = 0; i < n; ++i) { cin >> v[i]; }
		cout << maxVentana(v, n, k) << endl;
		cin >> n >> k;
	}

	delete[] v;
	return 0;
}


int maxVentana(int v[], int n, int k) {
	int ret = 0;
	int a = 0, b = 0;
	int ultUno = 0;
	int numCerosSeguidos = 0;

	//Coloco la ventana
	while (a < n && v[a] == 0) { ++a; }
	b = a;

	//Hago el recorrido
	while (b < n) {
		//Abro la ventana
		if (v[b]) {
			++b;
			numCerosSeguidos = 0;
			ultUno = b;
		}
		else if (numCerosSeguidos < k) {
			++b;
			++numCerosSeguidos;
		}
		//Cierro la ventana
		else {
			numCerosSeguidos = 0;
			a = ++b;
			while (a < n && v[a] == 0) { ++a; }
			ultUno = b = a;
			
		}

		ret = max(ret, ultUno - a);
	}

	return ret;
}