#include <iostream>
using namespace std;

const int MAX = 500000;

int fun(int v[], int n);

int main() {
	int* v = new int[MAX];
	int n;
	cin >> n;
	while (n) {
		for (int i = 0; i < n; ++i) cin >> v[i];
		cout << fun(v, n) << endl;
		cin >> n;
	}

	delete[] v;
	return 0;
}

int fun(int v[], int n) {
	int ret = 0;
	int i = n - 2;
	int max = v[n-1];

	while (i >= 0) {
		if (max > 0) {
			++ret;
		}
		max -= 1;
		max = (max> v[i]) ? max : v[i];
		--i;
	}

	return ret;
}