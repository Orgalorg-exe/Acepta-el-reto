#include <iostream>
#include <string>
using namespace std;

long long numPartidos(long long ini, long long fin, int r, string s, string& aux);

int main() {

	string s, aux;
	long long n, r;
	cin >> n >> r;

	while (n) {
		cin >> s;
		aux = "";

		cout << numPartidos(0, n, r, s, aux) << endl;

		cin >> n >> r;
	}

	return 0;
}

long long numPartidos(long long ini, long long fin, int r, string s, string& aux ) {
	//Caso base
	if (r == 1) {
		long long ret = 0;
		for (long long i = ini; i < fin - 1; i += 2) {
			if (s[i] == '1' && s[i + 1] == '1') {
				++ret;
				aux += '1';
			}
			else if (s[i] == '0' && s[i + 1] == '0') {
				aux += '0';
			}
			else {
				aux += '1';
			}
		}

		return ret;
	}

	//Caso recursivo
	long long m = ((ini + fin) / 2);
	string auxIzq = "", auxDer = "";

	long long rIzq = numPartidos(ini, m, r - 1, s, auxIzq);
	long long rDer = numPartidos(m, fin, r - 1, s, auxDer);

	auxIzq += auxDer;

	long long ret = 0;
	for (long long i = 0; i < auxIzq.length() - 1; i += 2) {
		if (auxIzq[i] == '1' && auxIzq[i + 1] == '1') {
			++ret;
			aux += '1';
		}
		else if (auxIzq[i] == '0' && auxIzq[i + 1] == '0') {
			aux += '0';
		}
		else {
			aux += '1';
		}
	}

	return ret + rIzq + rDer;

}