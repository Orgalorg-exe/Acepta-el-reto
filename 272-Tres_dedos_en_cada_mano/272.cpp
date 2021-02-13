#include <iostream>

using namespace std;

void baseDiez2baseSeis(int n);

int main() {

	int c, n;
	cin >> c;

	for (c; c > 0; --c) {

		cin >> n;

		if (n == 0)
			cout << "0";
		else
			baseDiez2baseSeis(n);

		cout << endl;
	}

	return 0;
}

void baseDiez2baseSeis(int n) {

	//Caso base
	if (n == 0) {
		return;
	}

	baseDiez2baseSeis(n/6);
	cout << n % 6;
}