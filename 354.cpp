#include <iostream>
using namespace std;

const int MAX = 200000;

int minNin(int v[], int n);

int main() {
	int* v = new int[MAX];
	int n;

	cin >> n;
	while (n != 0) {
		for (int i = 0; i < n; ++i) { cin >> v[i]; }
		cout << minNin(v, n) << endl;
		cin >> n;
	}

	delete[] v;
	return 0;
}


int minNin(int v[], int n) {
	int ret = 1;
	int i = 1;
	int maxHVec = v[0];
	int maxHNin = v[0];

	while (i < n) {
		if (v[i] <= maxHNin) {
			ret = i + 1;
			maxHNin = maxHVec;
		}
		else if (v[i] > maxHVec) {
			maxHVec = v[i];
		}
		++i;
	}

	return ret;
}
