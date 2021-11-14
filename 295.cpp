#include <iostream>

using namespace std;

const int MOD = 31543;

int elevar(int n, int e);

int main() {
	int n, e;
	cin >> n >> e;

	while (n != 0 || e != 0) {
		cout << elevar(n % MOD, e) << endl;
		cin >> n >> e;
	}

	return 0;
}

int elevar(int n, int e) {
	
	//Caso base
	if (n == 0)
		return 0;
	else if (n == 1 || e == 0)
		return 1;
	else if (e == 1)
		return n;

	//Caso recursivo
	int aux = elevar(n, e/2);
	int ret = (aux*aux) % MOD;

	if (e % 2 == 1)
		ret = (ret * n) % MOD;

	return ret;
}