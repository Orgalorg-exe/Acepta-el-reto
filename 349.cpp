//DATOS PREVIOS

//includes
#include<iostream>
using namespace std;

//Declaración de funciones
int calculadoraPolaca();

//MAIN
int main() {

	int c;
	cin >> c;

	for (c; c > 0; --c) {
		cout << calculadoraPolaca() << endl;
	}

	return 0;
}

//IMPLEMENTACIÓN DE LA FUNCIÓN SOLUCIÓN
//Y DETALLES DE LA SOLUCIÓN

/* { Pre: } */
int calculadoraPolaca() {

	char c;
	cin >> c;

	//Caso Base
	if (isdigit(c)) return c - '0';

	//Casos recursivo
	if (c == '+') return calculadoraPolaca() + calculadoraPolaca();
	if (c == '*') return calculadoraPolaca() * calculadoraPolaca();
	if (c == '-') return calculadoraPolaca() - calculadoraPolaca();
	if (c == '/') return calculadoraPolaca() / calculadoraPolaca();
}
/* { Pos: } */