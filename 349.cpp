#include<iostream>
using namespace std;

int calculadoraPolaca();

int main() {

	int numCasos;
	cin >> numCasos;

	for (; numCasos > 0; --numCasos) {
		cout << calculadoraPolaca() << endl;
	}

	return 0;
}

int calculadoraPolaca() {
	char c;
	cin >> c;

	//Caso Base
	if (isdigit(c)) return c - '0';

	//Casos recursivo
	if (c == '+') return calculadoraPolaca() + calculadoraPolaca();
	if (c == '*') return calculadoraPolaca() * calculadoraPolaca();
	if (c == '-') return calculadoraPolaca() - calculadoraPolaca();
	if (c == '/') return calculadoraPolaca() / calculadoraPolaca();
}