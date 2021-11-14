#include<iostream>
using namespace std;

int ultDigFactorial(int n);

int main() {
	int numCasos, n;
	cin >> numCasos;

	for (numCasos; numCasos > 0; --numCasos) {
		cin >> n;
		cout << ultDigFactorial(n) << endl;
	}

	return 0;
}

// { Pre: 0 <= n}
int ultDigFactorial(int n) {
	int ret = 0;
	// { I : (ret = i : 0 <= i : n! mod 10)
	// }

	// O(1)
	if (n == 0) { ret = 1; }
	else if (n < 3 ) { ret = n; }
	else if (n == 3) { ret = 6; }
	else if (n == 4) { ret = 4; }

	return ret;
}
// { Pos: i : [0, 1, 2, 4, 6] : i = n! mod 10} 
