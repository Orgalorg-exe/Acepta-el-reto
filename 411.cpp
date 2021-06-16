//DATOS PREVIOS

//includes
#include<iostream>
#include <string>

using namespace std;

//Declaraci�n de la funci�n
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


//IMPLEMENTACI�N DE LA FUNCI�N SOLUCI�N
//DETALLES DE LA SOLUCI�N

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


