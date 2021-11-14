#include<iostream>
using namespace std;

bool adivinaElNumero (int ini, int fin, int n, int k);

int main() {
	int ini, fin, n, k;

	cin >> ini >> fin >> n;
	while (ini != 0 && fin != 0 && n != 0) {
		cin >> k;

		if (adivinaElNumero(ini, fin + 1, n, k-1))
			cout << "LO SABE" << endl;
		else
			cout << "NO LO SABE" << endl;

		cin >> ini >> fin >> n;
	}

	return 0;
}


/* { Pre: 1 <= ini <= n <= fin <= 250.000} */
bool adivinaElNumero(int ini, int fin, int n, int k) {
	
	//Caso base
	if (k < 0)
		return fin - ini == 1;

	//Caso recursivo
	int v;
	cin >> v;

	if (ini < v && v <= n)
		return adivinaElNumero(v, fin, n, k - 1);
	else if (n < v && v < fin)
		return adivinaElNumero(ini, v, n, k - 1);
	else
		return adivinaElNumero(ini, fin, n, k - 1);
}
/* { Pos: } */