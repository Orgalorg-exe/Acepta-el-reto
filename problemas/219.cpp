#include <iostream>

using namespace std;

const int MAX_TAM = 10000;
int n, v[MAX_TAM];

int numPares(int n, int v[]);

int main() {
	int numCasos;
	cin >> numCasos;

	for (; numCasos > 0; numCasos--) {
		cin >> n;
		for (int j = 0; j < n; j++) { cin >> v[j]; }
		cout << numPares(n, v) << endl;
	}

	return 0;
}

int numPares(int n, int v[]) {
	int ret = 0;
	int i = 0;
	
	while (i < n) {
		if (!(v[i] % 2)) { ret++; }
		i++;
	}

	return ret;
}