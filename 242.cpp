#include<iostream>
using namespace std;

const int MAX = 100000;

long long int numParejas(int n, long long int v[]);

int main() {
	int n;
	long long int* v = new long long int[MAX];
	cin >> n;

	while (n != 0) {
		for (int i = 0; i < n; ++i) { cin >> v[i]; }
		cout << numParejas(n, v) << endl;
		cin >> n;
	}

	delete[] v;

	return 0;
}

//{ Pre: 0 < n <= 100.000}
long long int numParejas(int n, long long int v[]) {

	//Invariante
	//
	long long int numParejas = 0;
	long long int suma = v[0];
	int i = 1;
	
	// O(n)
	while (i < n) {
		numParejas += v[i] * suma;
		suma += v[i];
		++i;
	}

	return numParejas;
}
//{ Pos: #i : : }