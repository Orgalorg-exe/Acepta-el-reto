#include<iostream>

using namespace std;

int main() {

	long long int pesoTela, pesoElefante, pesoElefanteAcumulado, numElefantes;

	cin >> pesoTela; 

	while (pesoTela != 0) {

		pesoElefanteAcumulado = 0;
		numElefantes = 0;

		//Mejorable leyendo la entrada de pesos de elefantes como un string, detener el procesamiento del string cuando pEA > pT
		cin >> pesoElefante;
		pesoElefanteAcumulado += pesoElefante;
		while (pesoElefante != 0) {

			if (pesoElefanteAcumulado <= pesoTela) {
				numElefantes++;
			}

			cin >> pesoElefante;
			pesoElefanteAcumulado += pesoElefante;
		}

		cout << numElefantes << endl;
		cin >> pesoTela;
	}

	return 0;
}
