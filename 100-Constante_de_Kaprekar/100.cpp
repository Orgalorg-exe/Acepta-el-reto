#include <iostream>
#include <algorithm>
using namespace std;

const int CONST = 6174, MAX_TAM = 4;

int numIteracionesKaprekar(int n);

int main() {

	int c, n;
	cin >> c;

	while (c > 0) {
		cin >> n;
		cout << numIteracionesKaprekar(n) << endl;
		c--;
	}

	return 0;
}

//Comprobar si coincide con la constante
//Descuartizar el número
//Comprobar si las cuatro cifras son iguales
//Ordenar Desc y Asc
//Repetir con Desc-Asc

//Código bonito que funcione para cualquier constante 
// y cualquier número de cifras

/*{
	Pre: n >= 0;
}*/
int numIteracionesKaprekar(int n) {
	int ret = 1;
	int v[MAX_TAM];
	bool dif = false;

	if (n == CONST)
		ret = 0;

	else {

		//Descuartizo el número 
		//y compruebo si las cifras no son todas iguales
		for (int i = 0; i < MAX_TAM; i++) {
			v[i] = n % 10;
			n /= 10;
			if (i > 0 && !dif)
				dif = v[i] != v[i - 1];
		}

		if (!dif) {
			ret = 8;
		}
		else {
			//Ordeno el vector
			sort(v, v+MAX_TAM);

			//Formo los números
			int asc = 0, des = 0;
			for (int i = 0; i < MAX_TAM; i++) {
				asc = asc * 10 + v[i];
				des = des * 10 + v[MAX_TAM - (i+1)];
			}

			//LLamo recursivamente
			ret += numIteracionesKaprekar(des - asc);
		}
	}

	return ret;
}
/*{
	Post: 
}*/
