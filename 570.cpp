#include <iostream>

using namespace std;

int numDNIvalido(string dni, int nif, int k);
char letra[] = { 'T', 'R', 'W', 'A', 'G', 'M', 'Y', 'F', 'P', 'D', 'X', 'B', 'N', 'J', 'Z', 'S', 'Q', 'V', 'H', 'L', 'C', 'K', 'E' };

int main() {

	int n;
	cin >> n;

	string DNI;

	for (n; n > 0; --n) {
		cin >> DNI;
		cout << numDNIvalido(DNI, 0, 0) << endl;
	}

	return 0;
}

int numDNIvalido(
	//Datos del problema
	string dni,
	//Datos de la solución
	int nif, int k

) {
	//Caso Base: DNI válido
	if (k == 8 && letra[nif % 23] == dni[k])
		return 1;

	//Caso recursivo
	int ret = 0;

	while (isdigit(dni[k])) {
		nif = nif*10 + ((int)dni.at(k) - (int)'0');
		++k;
	}

	if (k < 8) {
		for (int i = 0; i < 10; ++i) {
			nif = nif*10 + i;
			++k;
			ret += numDNIvalido(dni, nif, k);
			nif /= 10;
			--k;
		}
	}
	//Caso Base de nuevo wtf: DNI válido
	else if (k == 8 && letra[nif % 23] == dni[k])
		ret = 1;

	return ret;
}