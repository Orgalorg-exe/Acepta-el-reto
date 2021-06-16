//DATOS PREVIOS

//includes
#include<iostream>
#include <string>

using namespace std;

//Declaración de la función
int numElefantes(int max);

//MAIN
int main() {

	long long int max;
	string aux;

	cin >> max;

	while (max != 0) {
		cout << numElefantes(max) << endl;
		getline(cin, aux);
		cin >> max;
	}

	return 0;
}


//IMPLEMENTACIÓN DE LA FUNCIÓN SOLUCIÓN
//DETALLES DE LA SOLUCIÓN

//pre
int numElefantes(int max) {

	long long int pesoAcum = 0, input;
	long long int ret = 0;
	//Invariante
	
	cin >> input;
	pesoAcum += input;

	// O(n)
	// n = max, como mucho,
	// acumularemos max elefantes
	// de peso = 1
	while (pesoAcum <= max && input != 0) {
		++ret;
		cin >> input;
		pesoAcum += input;
	}

	return ret;
}
//post


