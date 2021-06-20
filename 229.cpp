//DATOS PREVIOS

//includes
#include<iostream>
using namespace std;

//constantes
const int MAX = 100000;

//Declaración de funciones
int cuentasParalelas(int n, int v[], int sum);
void lecturaDeDatos(int n, int v[], int& sum);

//MAIN
int main() {
	int n, sum;
	int* v = new int[MAX];
	cin >> n;

	while (n != 0) {
		lecturaDeDatos(n, v, sum);
		cout << cuentasParalelas(n, v, sum) << endl;
		cin >> n;
	}

	delete[] v;
	return 0;
}

//IMPLEMENTACIÓN DE LA FUNCIÓN SOLUCIÓN
//DETALLES DE LA SOLUCIÓN

//{ Pre: 1 <= n <= longitud(v), sum <= 2*10^9}
int cuentasParalelas(int n, int v[], int sum) {

	//Invariante
	// 
	int i = 0;
	int saldo = 0;
	int ret = 0;

	//Complejidad
	// O(n)
	// se recorre el vector
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
/*{ Pos: #i : 0 <= i < n : sum(0, i, v) = sum(i, n, v)
    donde: sum(a, b, V[]) = (S j: a <= j < b: V[j])
}*/

void lecturaDeDatos(int n, int v[], int& sum) {
	sum = 0;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		sum += v[i];
	}
}