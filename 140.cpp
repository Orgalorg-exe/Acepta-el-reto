//DATOS PREVIOS

//includes
#include<iostream>
using namespace std;

//Declaraci�n de funciones
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

//IMPLEMENTACI�N DE LA FUNCI�N SOLUCI�N
//Y DETALLES DE LA SOLUCI�N

//Algoritmo recursivo

/* { Pre: 0 <= n} */
int sumaDigitos(int n){
	//Complejidad
	// O(n)
	// depende del n�mero de
	// d�gitos de n
	 
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