//DATOS PREVIOS

//includes
#include<iostream>
using namespace std;

//constantes
const int MAX = 200000;

//Declaración de funciones
long long int numMultiplicaciones(int n, float v[]);
void lecturaDeDatos(const int n, float v[]);

//MAIN
int main() {

	int n;
	float* v = new float[MAX];
	cin >> n;

	while (n != 0) {
		lecturaDeDatos(n, v);
		cout << numMultiplicaciones(n, v) << endl;
		cin >> n;
	}

	delete[] v;
	return 0;
}

//IMPLEMENTACIÓN DE LA FUNCIÓN SOLUCIÓN
//Y DETALLES DE LA SOLUCIÓN

// { Pre: 0 <= n <= longitud(v) ^
//        P.t. i : 0 <= i < n: v[i] >= 0 }
long long int numMultiplicaciones(int n, float v[]) {

	//Invariante
	//
	long long int ret = 0;
	int i = 0;
	long long int a = 0, b = 0, c = 0;
	long long int A = 0, B = 0, C = 0;

	//Complejidad
	// O(n)
	// se recorre el vector
	while (i < n) {

		if (v[i] == 0 || v[i] == 1) {
			++c;
			C += n - c;
		}
		else if (v[i] < 1) {
			++a;
			A += a - 1;
		}
		else if (v[i] > 1){
			++b;
			B += b - 1;
		}

		++i;
	}

	ret = A + B + C;

	return ret;
}
//{ Pos: # i,j : 0 <= i < j < n : v[i]*v[j] <= i || j <= v[i]*v[j] }

void lecturaDeDatos(const int n, float v[]) {
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
}