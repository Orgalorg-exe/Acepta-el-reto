#include <iostream>
#define MAX 100000
int n, v[MAX], sum;

using namespace std; 

int cuentasParalelas(int n, int v[], int sum);

int main() {
	cin >> n;

	while (n != 0) {
		sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
			sum += v[i];
		}

		cout << cuentasParalelas(n, v, sum) << endl;
		cin >> n;
	}

	return 0;
}

//{ Pre: 1 <= n <= longitud(v), sum <= 10^9}
int cuentasParalelas(int n, int v[], int sum) {

	int i = 0;
	int saldo = 0;
	int ret = 0;

	/*{ I:
	
	}*/

	while (i < n + 1) {
		if (saldo == sum) { ++ret; }
		
		if (i < n) {
			saldo += v[i];
			sum -= v[i];
		}

		++i;
	}

	return ret;
}
//{ Pos: ret = max saldo = sum wtf }