#include <iostream>

using namespace std;

const int MAX_TAM = 200000;
float v[MAX_TAM];
int n;

long long int numMultiplicaciones(int n, float v[]);

int main() {

	cin >> n;
	while (n != 0) {

		for (int i = 0; i < n; i++) {
 			cin >> v[i];
		}

		cout << numMultiplicaciones(n, v) << endl;

		cin >> n;
	}

	return 0;
}

long long int numMultiplicaciones(int n, float v[]) {
	long long int ret = 0;
	int i = 0;
	long long int a = 0, b = 0, c = 0;
	long long int A = 0, B = 0, C = 0;

	while (i < n) {

		if (v[i] == 0 || v[i] == 1) {
			++c;
			C += n - c;
		}
		else if (v[i] < 1) {
			++a;
			A += a - 1;
		}
		else if (v[i] > 1){
			++b;
			B += b - 1;
		}
		++i;
	}

	ret = A + B + C;

	return ret;
}