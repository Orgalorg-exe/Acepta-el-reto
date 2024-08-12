#include<iostream>
using namespace std;

int pintandoFractales(int n);

int main() {
	int n;
	cin >> n;

	while (cin) {
		cout << pintandoFractales(n) << endl;
		cin >> n;
	}

	return 0;
}

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