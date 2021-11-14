#include<iostream>
using namespace std;

int encadenandoTrolls(int h, int c, int& p);

int main() {

	int h, c, p = 0;
	cin >> h >> c;

	while (h != 0) {
		cout << encadenandoTrolls(h, c, p) << endl;
		cin >> h >> c;
		p = 0;
	}

	return 0;
}


//IMPLEMENTACI�N DE LA FUNCI�N SOLUCI�N
//Y DETALLES DE LA SOLUCI�N

/* { Pre: } */
int encadenandoTrolls(int h, int c, int& p) {

	//Caso base
	if (c <= h * 2) {
		return 0;
	}

	//Caso recursivo
	int pp = ((c / 3) * 2) + c % 3;
	int pl = c / 3;
	p++;

	encadenandoTrolls(h, pp, p);
	encadenandoTrolls(h, pl, p);
	return p;
}
/* { Pre: } */