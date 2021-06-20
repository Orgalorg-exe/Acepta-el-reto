//DATOS PREVIOS

//includes
#include<iostream>
#include<string>

using namespace std;

//constantes
const int MAX = 100000;

//Declaración de la función
string solBocadillos(int n, int v[]);
int numBocadillos(int n, int v[]);
void lecturaDelVector(const int n, int v[]);

//MAIN
int main() {

	int n, v[MAX];
	int numBocadillos = 0;
	cin >> n;

	while (n != 0) {
		lecturaDelVector(n, v);
		cout << solBocadillos(n, v) << endl;

		cin >> n;
	}

	return 0;
}

//IMPLEMENTACIÓN DE LA FUNCIÓN SOLUCIÓN
//DETALLES DE LA SOLUCIÓN

string solBocadillos(int n, int v[]) {
	string ret = "NO";
	int numB = numBocadillos(n, v);

	if (numB != n)
		ret = "SI " + to_string(numB);

	return ret;
}

//pre: 
int numBocadillos(int n, int v[]) {
	//Invariante
	//
	int i = n - 1;
	long long int suma = 0;
	int ret = n;

	//Complejidad
	// O(n)
	// se recorre el vector
	while (i > -1) {
		if (v[i] == suma) {
			ret = i + 1;
		}
		suma += v[i];
		--i;
	}

	return ret;
}
//post: i + 1 :  0 < i < n : v[i] = (S j: i < j < n: v[j])


void lecturaDelVector(const int n, int v[]) {
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
}
