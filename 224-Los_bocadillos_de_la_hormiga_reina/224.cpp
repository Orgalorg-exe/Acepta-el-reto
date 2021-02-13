#include <iostream>

const int MAX = 100000;
int n, v[MAX]; 

using namespace std;

int bocadillos(int n, int v[]);

int main() {
	int numBocadillos = 0;

	cin >> n;

	while (n != 0) {
		for (int i = 0; i < n; ++i) { cin >> v[i]; }

		numBocadillos = bocadillos(n, v);

		if (numBocadillos != n) { cout << "SI " << numBocadillos << endl; }
		else { cout << "NO" << endl; }

		cin >> n;
	}

	return 0;
}


int bocadillos(int n, int v[]) {
	int i = n - 1;
	long long int suma = 0;
	int ret = n;

	while (i > -1) {
		if (v[i] == suma) {
			ret = i + 1;
		}
		suma += v[i];
		--i;
	}

	return ret;
}