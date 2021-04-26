#include <iostream>

using namespace std;

int cajasYBolas(int n);

int main() {
	int n;

	cin >> n;

	while (cin) {
		cout << cajasYBolas(n) << endl;
		cin >> n;
	}

	return 0;
}

int cajasYBolas(int n) {
	int ret = 1;

	while (n != 1) {
		n /= 2;
		++ret;
	}

	return ret;
}