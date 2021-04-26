#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_TAM = 25000;
int n, v[MAX_TAM];

int moda(int n, int v[]);

int main() {

	cin >> n;
	while (n != 0) {
		
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}

		sort(v, v + n);
		cout << moda(n, v) << endl;

		cin >> n;
	}

	return 0;
}

int moda(int n, int v[]) {
	int ret = v[0];
	int a = 1, b = 1;
	int i = 1;

	while (i < n) {
		
		if (v[i] == v[i - 1]) {
			++a; 
			if (a > b) {
				ret = v[i];
			}
		}
		else {
			if (a > b) {
				b = a;
			}
			a = 1;
		}

		++i;
	}

	return ret;
}