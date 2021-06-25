//DATOS PREVIOS

//includes
#include<iostream>
using namespace std;

//Declaración de funciones
string esPolidivisible(long long n);
bool esPolidivisible(long long n, short& numDig);

//MAIN
int main() {
	long long int n;
	cin >> n;

	while (cin) {
		cout << esPolidivisible(n) << endl;
		cin >> n;
	}

	return 0;
}

//IMPLEMENTACIÓN DE LA FUNCIÓN SOLUCIÓN
//Y DETALLES DE LA SOLUCIÓN

string esPolidivisible(long long n) {
	short foo;

	if (esPolidivisible(n, foo)) {
		return "POLIDIVISIBLE";
	}

	return "NO POLIDIVISIBLE";
}

//Algoritmo recursivo

 /* { Pre: } */
bool esPolidivisible (long long n, short & numDig ){
	//Complejidad
	// O(n)
	// depende del número de
	// dígitos de n

	//Caso base
	if (n < 10) {
		numDig = 1;
		return true;
	}

	//Caso recursivo
	bool ret = esPolidivisible(n/10, numDig);
	++numDig;
	return ret && (n % numDig == 0);
}
/* { Pos: } */