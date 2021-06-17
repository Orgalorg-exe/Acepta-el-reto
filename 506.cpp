//DATOS PREVIOS

//includes
#include<iostream>
#include<string>
using namespace std;

//Declaración de la función
void getInput(int& max, int& min);
string lectura(int max, int min);

//MAIN
int main() {

	int max, min;
	int numCasos;

	cin >> numCasos;

	for (numCasos; numCasos > 0; --numCasos) {
		getInput(max, min);
		cout << lectura(max, min) << endl;
	}

	return 0;
}

//IMPLEMENTACIÓN DE LA FUNCIÓN SOLUCIÓN
//DETALLES DE LA SOLUCIÓN

//pre
string lectura(int max, int min) {

	//Invariante
	//

	//Complejidad
	// O(1) 
	// se trata de comprobar
	// una condición

	if (max >= min)
		return "BIEN";
	else
		return "MAL";
}
//post

void getInput(int& max, int& min) {
	string aux;
	scanf_s("%d%*3c%d", &max, &min);
	getline(cin, aux);
}