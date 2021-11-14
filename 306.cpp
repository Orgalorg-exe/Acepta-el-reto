#include <iostream>
using namespace std;

const int MOD = 46337;

int fibDyV(int n, int& fibNAnt, int& fibN, int& fibNPos);

int main() {
	int n, a, b, c;
	cin >> n;

	while (n != 0) {
		cout << fibDyV(n, a, b, c) << endl;
		cin >> n;
	}

	return 0;
}

int fibDyV(int n, int& fibNAnt, int& fibN, int& fibNPos) {
	
	//Caso base
	if (n == 1) {
		fibNAnt = 0; fibN = 1; fibNPos = 1;
		return 1;
	}

	//Caso recursivo
	fibDyV(n / 2, fibNAnt, fibN, fibNPos);

	int fibNCuad = (fibN * fibN) % MOD;
	fibN = (fibN * ((fibNAnt + fibNPos) % MOD)) % MOD;
	fibNAnt = ((fibNAnt * fibNAnt) % MOD + fibNCuad) % MOD;
	fibNPos = (fibNCuad + (fibNPos * fibNPos) % MOD) %MOD;

	if (n % 2 == 1) {
		fibNPos = (fibN + fibNPos) % MOD;
		swap(fibNAnt, fibN);
		fibN = (fibNAnt + fibN) % MOD;
	}

	return fibN;
}