//DATOS PREVIOS

//includes
#include <iostream>
#include <string>

using namespace std;

//Declaración de la función
string baseRaizDiez(string n);

//MAIN
int main() {
	string n;
	cin >> n;

	while (cin) {
		cout << baseRaizDiez(n) << endl;
		cin >> n;
	}

	return 0;
}

//IMPLEMENTACIÓN DE LA FUNCIÓN SOLUCIÓN
//DETALLES DE LA SOLUCIÓN

//pre
string baseRaizDiez(string n) {

	//Invariante
	//
	string ret = "";
	ret += n[0];
	int i = 1;

	//Complejidad
	// O(n)
	// n = n.length
	while (i < n.length()) {
		ret += "0";
		ret += n[i];
		++i;
	}

	return ret;
}
//post
