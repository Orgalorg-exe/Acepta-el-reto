#include <iostream>

using namespace std;

const int MAX_TAM = 10000;
int n, v[MAX_TAM];

void temperaturasExtremas(int n, int v[]);

int main() {
	int numCasos;
	cin >> numCasos;

	for (; numCasos > 0; numCasos--) {
		cin >> n;
		for (int j = 0; j < n; j++) { cin >> v[j]; }
		temperaturasExtremas(n, v);
	}

	return 0;
}

// { Pre : 0 < n <= longitud(v)}
void temperaturasExtremas(int n, int v[]) {
	int numPicos = 0, numValles = 0;
	int i = 1;

	while (i < n - 1 ) {
		if (v[i - 1] < v[i] && v[i] > v[i + 1]) { numPicos++; }
		else if (v[i - 1] > v[i] && v[i] < v[i + 1]) { numValles++; }
		++i;
	}

	cout << numPicos << " " << numValles << endl;
}