//DATOS PREVIOS

//includes
#include<iostream>
using namespace std;

//Declaraci�n de funciones
int baseDiez2baseSeis(int n);

//MAIN
int main() {

	int numCasos, n;
	cin >> numCasos;

	for (numCasos; numCasos > 0; --numCasos) {
		cin >> n;
		cout << baseDiez2baseSeis(n) << endl;
	}

	return 0;
}

//IMPLEMENTACI�N DE LA FUNCI�N SOLUCI�N
//Y DETALLES DE LA SOLUCI�N

/* { Pre: 0 <= n } */
int baseDiez2baseSeis(int n) {

	//Caso base
	if (n < 6) {
		return n;
	}

	//Caso recursivo
	int ret;
	ret = baseDiez2baseSeis(n/6);
	ret *= 10;
	ret += n % 6;
	return ret;
}
/* { Pos: } */