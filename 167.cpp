//DATOS PREVIOS

//includes
#include<iostream>
using namespace std;

//Declaración de funciones
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

//IMPLEMENTACIÓN DE LA FUNCIÓN SOLUCIÓN
//Y DETALLES DE LA SOLUCIÓN

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