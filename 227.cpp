#include <iostream>

using namespace std;

const int MOD = 1000000007;

int Cardano(int n, int m);

int main() {
	int n, m;
	cin >> n >> m;

	while (n) {
		cout << Cardano(n, m) << endl;
		cin >> n >> m;
	}

	return 0;
}

int Cardano(int n, int m) {
	//Caso base
	if (m == 0)  return 1;
	else if (n == 0) return 0;

	// Caso recursivo
	Cardano(n - 1, m - 1);
	Cardano(n - 1, m);
}