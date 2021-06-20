//DATOS PREVIOS

//includes
#include<iostream>
using namespace std;

//constantes
const int MAX = 100000;

//Declaración de la función
long long int numParejas(int n, long long int v[]);
void lecturaDelVector(const int n, long long int v[]);

//MAIN
int main() {

	int n;
	long long int* v = new long long int[MAX];
	cin >> n;

	while (n != 0) {
		lecturaDelVector(n, v);
		cout << numParejas(n, v) << endl;
		cin >> n;
	}

	delete[] v;

	return 0;
}

//IMPLEMENTACIÓN DE LA FUNCIÓN SOLUCIÓN
//DETALLES DE LA SOLUCIÓN

//{ Pre: }
long long int numParejas(int n, long long int v[]) {
	//Invariante
	//
	long long int numParejas = 0;
	long long int suma = v[0];
	int i = 1;
	
	//Complejidad
	// O(n)
	// se recorre el vector
	while (i < n) {
		numParejas += v[i] * suma;
		suma += v[i];
		++i;
	}

	return numParejas;
}
//{ Pos: }

void lecturaDelVector(const int n, long long int v[]) {
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
}