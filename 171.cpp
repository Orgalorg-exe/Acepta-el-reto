#include <iostream>

using namespace std;

const int MAX = 100000;

int numAbadias(int n, int v[]);


int main() {
	int n, v[MAX];

	cin >> n;

	//Bucle principal
	while (n != 0) {
		
		//Cargo el vector
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}

		//Ejecuto el algoritmo
		cout << numAbadias(n, v) << endl;

		cin >> n;
	}
}


/*
	pre: 0 < n <= 100.000
*/
int numAbadias(int n, int v[]) {
	int num = 0, max = 0;

	while (n > 0) {
		--n;
		if (v[n] > max) {
			max = v[n];
			++num;
		}
	}

	return num;
}

/*
	pos: npi
*/