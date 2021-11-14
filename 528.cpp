#include<iostream>
using namespace std;

const int MAX = 200000;

long long int numMultiplicaciones(int n, float v[]);

int main() {

	int n;
	float* v = new float[MAX];
	cin >> n;

	while (n != 0) {
		for (int i = 0; i < n; i++) { cin >> v[i]; }
		cout << numMultiplicaciones(n, v) << endl;
		cin >> n;
	}

	delete[] v;
	return 0;
}

// { Pre: 0 <= n <= longitud(v) ^
//        P.t. i : 0 <= i < n: v[i] >= 0 }
long long int numMultiplicaciones(int n, float v[]) {
	long long int ret = 0;
	int i = 0;
	long long int a = 0, b = 0, c = 0;
	// { I :
	// }

	// O(n)
	while (i < n) {
		if (v[i] == 0 || v[i] == 1)
			ret += n - ++a;
		else if (v[i] < 1)
			ret += ++b - 1;
		else
			ret += ++c - 1;
		++i;
	}

	return ret;
}
//{ Pos: # i,j : 0 <= i < j < n : v[i]*v[j] <= i || j <= v[i]*v[j] }
