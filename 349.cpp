//DATOS PREVIOS

//includes
#include<iostream>
using namespace std;

//Declaraci�n de funciones
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

//IMPLEMENTACI�N DE LA FUNCI�N SOLUCI�N
//Y DETALLES DE LA SOLUCI�N

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