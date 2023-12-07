#include <iostream>
using namespace std;

long long tam(int n);
char letra(int n, long long k);

int main() {
	int n;
	long long k;
	
	while (cin >> n >> k) {
		cout << letra(n, k) << endl;
	}

	return 0;
}


long long tam(int n) {
	if (n == 1)
		return 3;
	return (tam(n - 1) * 2) + 2 + n;
}

char letra(int n, long long k) {
	//Caso base
	if (n == 1) {
		if (k == 1)
			return 'B';
		else if (k == 2)
			return 'U';
		else
			return 'H';
	}

	//Caso recursivo
	long long l = tam(n - 1);

	if (k < l) {
		return letra(n - 1, k);
	}
	else if (l < k && k < l + 3 + n) {
		if (k == l + 1)
			return 'B';
		else if (k == l + 2 + n)
			return 'H';
		else
			return 'U';
	}
	else
		return letra(n-1, k - l - n - 2);
}