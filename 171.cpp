//DATOS PREVIOS

//includes
#include<iostream>
using namespace std;

//constantes y variables
const int MAX = 100000;

//Declaración de la función
int numAbadias(int n, int v[]);
void lecturaDelVector(const int n, int v[]);

//MAIN
int main() {

	int n, v[MAX];
	cin >> n;

	while (n != 0) {
		lecturaDelVector(n, v);
		cout << numAbadias(n, v) << endl;
		cin >> n;
	}

	return 0;
}

//IMPLEMENTACIÓN DE LA FUNCIÓN SOLUCIÓN
//DETALLES DE LA SOLUCIÓN

//pre: 0 < n <= 100.000
int numAbadias(int n, int v[]) {
	//Invariante
	//
	int ret = 0, max = 0;

	//Complejidad
	// O(n)
	// Se realiza un recorrido del vector
	while (n > 0) {
		--n;
		if (v[n] > max) {
			max = v[n];
			++ret;
		}
	}

	return ret;
}
//pos: #i: 0 <= i < n: v[i] > (max j: i < j < n: v[j] )

void lecturaDelVector(const int n, int v[]) {
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
}