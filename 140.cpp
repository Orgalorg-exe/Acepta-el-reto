//DATOS PREVIOS

//includes
#include<iostream>
using namespace std;

//Declaración de funciones
int sumaDigitos(int n);

//MAIN
int main() {
	int n;
	cin >> n;

	while (n > -1) {
		cout << " = " << sumaDigitos(n) << endl;
		cin >> n;
	}

	return 0;
}

//IMPLEMENTACIÓN DE LA FUNCIÓN SOLUCIÓN
//Y DETALLES DE LA SOLUCIÓN

//Algoritmo recursivo

/* { Pre: 0 <= n} */
int sumaDigitos(int n){
	//Complejidad
	// O(n)
	// depende del número de
	// dígitos de n
	 
	//Caso base
	if (n < 10) { 
		cout << n;
		return n;
	}

	//LLamada recursiva
	//Invariante
	//
	int ret = sumaDigitos(n / 10);
	cout << " + " << n % 10;
	return ret + (n % 10);
}
/* { Pos: } */