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

// { Pre: 1 <= n}
long long tam(int n) {
	if (n == 1)
		return 3;
	return (tam(n - 1) * 2) + 2 + n;
}
// { Pos: }


// { Pre: 0 < n ^ 0 < k < tam(n) + 1}
char letra(int n, long long k) {
	// recursión por resta
	// a = 1;
	// b = 1;
	// k = 1;



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
// { Pos: }