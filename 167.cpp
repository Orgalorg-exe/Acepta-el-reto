//DATOS PREVIOS

//includes
#include<iostream>
using namespace std;

//Declaraci�n de funciones
int pintandoFractales(int n);

//MAIN
int main() {
	int n;
	cin >> n;

	while (cin) {
		cout << pintandoFractales(n) << endl;
		cin >> n;
	}

	return 0;
}

//IMPLEMENTACI�N DE LA FUNCI�N SOLUCI�N
//Y DETALLES DE LA SOLUCI�N

//Algoritmo recursivo

/* { Pre: 1 <= n} */
int pintandoFractales(int n) {
	//Complejidad
	// 
	
	//Caso base
	if (n == 1) { return 4; }

	//Caso recursivo
	return 4 *( pintandoFractales(n / 2) + n);
}
/* { Pos: } */