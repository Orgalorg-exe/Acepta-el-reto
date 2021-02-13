#include <iostream>

using namespace std;

const int MAX_TAM = 10000;
int n, v[MAX_TAM];

void temperaturasExtremas(int n, int v[]);

int main() {
	int numCasos;
	cin >> numCasos;

	for (int i = 0; i < numCasos; i++) {

		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> v[j];
		}

		temperaturasExtremas(n, v);
	}

	return 0;
}

void temperaturasExtremas(int n, int v[]) {
	int a = 0, b = 0;
	int i = 1;

	while (i < n - 1 ) {
		if (v[i - 1] < v[i] && v[i] > v[i + 1]) { a++; }
		else if (v[i - 1] > v[i] && v[i] < v[i + 1]) { b++; }

		++i;
	}

	cout << a << " " << b << endl;
}