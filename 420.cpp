//DATOS PREVIOS

//includes
#include <iostream>
#include <string>

using namespace std;

//constantes
const int MAX = 250000;

//Declaración de funciones
int numSumas(int n, int v[], int k);
void lecturaDeDatos(int& n, int v[], int& k);

//MAIN
int main() {

	int numCasos, n, k;
	int* v = new int[MAX];

	cin >> numCasos;

	for (numCasos; numCasos > 0; --numCasos) {
		n = k = 0;
		lecturaDeDatos(n, v, k);
		cout << numSumas(n, v, k) << endl;
	}

	delete[] v;
	return 0;
}

//IMPLEMENTACIÓN DE LA FUNCIÓN SOLUCIÓN
//DETALLES DE LA SOLUCIÓN

//Problema de ventana deslizante

/*{ Pre: 0 <= n <= longitud(v) 
          0 < k }*/
int numSumas(int n, int v[], int k) {
	//Invariante
	//
	int ret = 0;
	int a = 0, b = 0;
	int sum = 0;

	//Complejidad
	// O(n)
	// la ventana avanza en el 
	// recorrido del vector
	// con cada iteración.
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
/*{ Pos: #i, j : 0 <= i <= j < n : k = (S h : i <= h <= j : v[h])}*/


void lecturaDeDatos(int& n, int v[], int& k) {
	string aux;
	cin >> k >> aux; 
	for (int i = 0; i < aux.length(); ++i) {
		v[i] = aux[i] - '0';
		++n;
	}
}