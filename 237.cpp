#include <iostream>

using namespace std;

bool esPolidivisible(long long n);
bool esPolidivisible(long long n, short & numDig);

int main() {
	long long int n;
	cin >> n;

	while (cin) {

		if (esPolidivisible(n)) {
			cout << "POLIDIVISIBLE" << endl;
		}
		else {
			cout << "NO POLIDIVISIBLE" << endl;
		}

		cin >> n;
	}

	return 0;
}

bool esPolidivisible(long long n) {
	short dummy;
	return esPolidivisible(n, dummy);
}

bool esPolidivisible (long long n, short & numDig ){

	if (n < 10) {
		numDig = 1;
		return true;
	}

	bool ret = esPolidivisible(n/10, numDig);
	++numDig;
	return ret && (n % numDig == 0);
}