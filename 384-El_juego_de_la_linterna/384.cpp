#include <iostream>

using namespace std;

const int MAX = 500000;
int v[MAX], n, posMenor, posMayor, posMedio;

bool puedePerder(int v[], int posMenor, int posMayor, int posMedio, int n, int o);

int main() {

	cin >> n;

	while (cin) {

		//Relleno el vector y busco el mayor
		posMayor = 0;
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			if (v[posMayor] < v[i])
				posMayor = i;
		}

		//Búsqueda del menor y el mediano
		posMenor = 0;

		if (posMayor < n - 1)
			posMedio = posMayor + 1;
		else
			posMedio = posMayor;

		for (int i = 0; i < n; ++i) {
			if (i < posMayor && v[posMenor] > v[i])
				posMenor = i;
			else if (i > posMayor && v[posMedio] < v[i])
				posMedio = i;
		}

		if (puedePerder(v, posMenor, posMayor, posMedio, n, 0))
			cout << "ELEGIR OTRA\n";
		else
			cout << "SIEMPRE PREMIO\n";

		cin >> n;
	}

	return 0;
}

bool puedePerder(int v[], int posMenor, int posMayor, int posMedio, int n, int o) {
	
	//Caso base
	if (v[posMenor] < v[posMedio] && v[posMayor] > v[posMedio]) {
		return true;
	}

	//Caso recursivo
	bool puedePerderIZQ, puedePerderDER;

	if (posMayor - o < 3)
		puedePerderIZQ = false;

	else {
		int oIZQ, posMenorIZQ, posMayorIZQ, posMedioIZQ, nIZQ;

		oIZQ = o;
		nIZQ = posMayor;
		
		//Busco el mayor
		posMayorIZQ = oIZQ;
		for (int i = oIZQ; i < nIZQ; ++i) {
			if (v[posMayorIZQ] < v[i])
				posMayorIZQ = i;
		}

		//Busco el menor y el mediano
		posMenorIZQ = oIZQ;

		if (posMayorIZQ < nIZQ - 1)
			posMedioIZQ = posMayorIZQ + 1;
		else
			posMedioIZQ = posMayorIZQ;

		for (int i = oIZQ; i < nIZQ; ++i) {
			if (i < posMayorIZQ && v[posMenorIZQ] > v[i])
				posMenorIZQ = i;
			else if (i > posMayorIZQ && v[posMedioIZQ] < v[i])
				posMedioIZQ = i;
		}
		
		puedePerderIZQ = puedePerder(v, posMenorIZQ, posMayorIZQ, posMedioIZQ, nIZQ, oIZQ);
	}

	if (n - posMayor < 3)
		puedePerderDER = false;
	else {
		int oDER, posMenorDER, posMayorDER, posMedioDER, nDER;

		oDER = posMayor + 1;
		nDER = n;

		posMayorDER = posMedio;

		//Busco el menor y el mediano
		posMenorDER = oDER;

		if (posMayorDER < nDER - 1)
			posMedioDER = posMayorDER + 1;
		else
			posMedioDER = posMayorDER;

		for (int i = oDER; i < nDER; ++i) {
			if (i < posMayorDER && v[posMenorDER] > v[i])
				posMenorDER = i;
			else if (i > posMayorDER && v[posMedioDER] < v[i])
				posMedioDER = i;
		}

		puedePerderDER = puedePerder(v, posMenorDER, posMayorDER, posMedioDER, nDER, oDER);
	}

	return puedePerderIZQ || puedePerderDER;
}