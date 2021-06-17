//DATOS PREVIOS

//includes
#include<iostream>
#include<string>
using namespace std;

//Declaraci�n de la funci�n
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

//IMPLEMENTACI�N DE LA FUNCI�N SOLUCI�N
//DETALLES DE LA SOLUCI�N

//pre
string lectura(int max, int min) {

	//Invariante
	//

	//Complejidad
	// O(1) 
	// se trata de comprobar
	// una condici�n

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