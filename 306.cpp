#include <iostream>

using namespace std;

const int MOD = 46337;

int fibDyV(int n, int& a, int& b, int& d);

int main() {

	int n, a, b, d;
	cin >> n;

	while (n != 0) {
	
		cout << fibDyV(n, a, b, d) << endl;

		cin >> n;
	}

	return 0;
}

int fibDyV(int n, int& a, int& b, int& d) {
	
	//Caso base
	if (n == 1) {
		a = 0;
		b = 1;
		d = 1;
		return 1;
	}

	//Caso recursivo
	fibDyV(n / 2, a, b, d);

	a %= MOD;
	b %= MOD;
	d %= MOD;

	int a_aux = (a * a) % MOD + (b * b) % MOD;
	int b_aux = (a * b) % MOD + (b * d) % MOD;
	int d_aux = (b * b) % MOD + (d * d) % MOD;

	a = a_aux %= MOD;
	b = b_aux %= MOD;
	d = d_aux %= MOD;

	if (n % 2 == 1) {
		a_aux = b;
		b_aux = a + b;
		d_aux = b + d;

		a = a_aux %= MOD;
		b = b_aux %= MOD;
		d = d_aux %= MOD;
	}

	return b;
}