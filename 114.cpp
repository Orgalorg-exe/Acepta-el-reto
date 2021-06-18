//DATOS PREVIOS

//includes
#include<iostream>
using namespace std;

//Declaraci�n de la funci�n
int ultDigFactorial(int n);

//MAIN
int main() {
	int numCasos, n;
	cin >> numCasos;

	for (numCasos; numCasos > 0; --numCasos) {
		cin >> n;
		cout << ultDigFactorial(n) << endl;
	}

	return 0;
}

//IMPLEMENTACI�N DE LA FUNCI�N SOLUCI�N
//DETALLES DE LA SOLUCI�N

//pre {n >= 0}
int ultDigFactorial(int n) {
	//Invariante
	//
	int ret = 0;

	//Complejidad
	// O(1) 
	// Para n >= 5 el �lt dig del
	// factorial siempre es cero
	// Para 0 <= n <= 4, se hace
	// un simple if o un switch

	if (n == 0 || n == 1) { ret = 1; }
	else if (n == 2) { ret = 2; }
	else if (n == 3) { ret = 6; }
	else if (n == 4) { ret = 4; }

	return ret;
}
//post
