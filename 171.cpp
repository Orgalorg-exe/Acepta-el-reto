#include<iostream>
using namespace std;

const int MAX = 100000;

int numAbadias(int n, int v[]);

int main() {
	int n;
	int* v = new int[MAX];
	cin >> n;

	while (n != 0) {
		for(int i = 0; i < n; ++i) { cin >> v[i]; }
		cout << numAbadias(n, v) << endl;
		cin >> n;
	}

	delete[] v;
	return 0;
}

// pre { 0 < n <= 100.000 }
int numAbadias(int n, int v[]) {
	//Invariante
	//
	int ret = 0, max = 0;

	// O(n)
	while (n > 0) {
		--n;
		if (v[n] > max) {
			max = v[n];
			++ret;
		}
	}

	return ret;
}
//pos { #i: 0 <= i < n: v[i] > (max j: i < j < n: v[j] ) }