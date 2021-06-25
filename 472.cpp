//DATOS PREVIOS

//includes
#include<iostream>
using namespace std;

//constantes
const int MAX = 200000;

//Declaraci�n de funciones
bool esApta(int n, int v[], int d);
string caminandoVoy(int n, int v[], int d);
void lecturaDeDatos(int n, int v[]);

//MAIN
int main() {
	int n, d;
	int* v = new int[MAX];
	cin >> d >> n;

	while (cin) {
		lecturaDeDatos(n, v);
		cout << caminandoVoy(n, v, d) << endl;
		cin >> d >> n;
	}

	delete[] v;
	return 0;
}

//IMPLEMENTACI�N DE LA FUNCI�N SOLUCI�N
//Y DETALLES DE LA SOLUCI�N

/* { Pre: 0 <= n <= longitud(v) ^
          0 <= d} */
bool esApta(int n, int v[], int d) {

	//Invariante
	//
	bool ret;
	int a = 0, b = 0;

	//Complejidad
	// O(n)
	// b�squeda 
	// La ventana contin�a el recorrido del
	// vector en el bucle while anidado
	while ((b < n) && (v[b] - v[a] <= d)) {

		while ((b + 1 < n) && v[b + 1] <= v[b]) {
			++b;
			a = b;
		}

		++b;
	}

	ret = !(b < n);

	return ret;
}
/* { Pos: P.t. i,j : 0 <= i <= j < n : } */

string caminandoVoy(int n, int v[], int d) {
	if (esApta(n, v, d))
		return "APTA";
	return "NO APTA";
}

void lecturaDeDatos(int n, int v[]) {
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
}

