#include <iostream>

using namespace std;

#define MAX_TAM 100000
int v[MAX_TAM];
int n;

long long int numParejas( int n, int v[]);

int main() {

	cin >> n;

	//Bucle principal
	while (n != 0) {
		
		//Cargo el caso de prueba
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}

		//Ejecuto el algoritmo principal
		cout << numParejas(n, v) << endl;

		cin >> n;
	}

	return 0;
}

//{ Pre: }
long long int numParejas(int n, int v[]) {
	long long int numParejas = 0;
	long long int suma = v[n - 1];
	int i = n - 2;
	
	while (i >= 0) {
		numParejas += v[i] * suma;
		suma += v[i];
		--i;
	}

	return numParejas;
}
//{ Pos: }