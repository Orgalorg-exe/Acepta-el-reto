//DATOS PREVIOS

//includes
#include<iostream>
using namespace std;


//Declaración de funciones
int pajaritasDePapel(int b, int a, int& n);

//MAIN
int main() {

	int b, a, n = 0;
	cin >> b >> a;

	while (b != 0) {
		cout << pajaritasDePapel(b, a, n) << endl;
		cin >> b >> a;
		n = 0;
	}

	return 0;
}

//IMPLEMENTACIÓN DE LA FUNCIÓN SOLUCIÓN
//Y DETALLES DE LA SOLUCIÓN

/* { Pre: } */
int pajaritasDePapel(int b, int a, int& n) {

	//Caso base
	if (b < 10 || a < 10) {
		return 0;
	}

	//Caso recursivo
	if (b >= a) {
		n += b / a;
		pajaritasDePapel(b % a, a, n);
	}
	else {
		n += a / b;
		pajaritasDePapel(b, a % b, n);
	}

	return n;
}
/* { Pos: } */