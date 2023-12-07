#include <iostream>
using namespace std;

int main() {

	int numCasos, n;
	cin >> numCasos;
	for (; numCasos > 0; --numCasos) {
		cin >> n;
		if (n % 2 == 0) {
			cout << n + 1 << endl;
		}
		else {
			cout << n - 1 << endl;
		}
	}

	return 0;
}