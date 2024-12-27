#include<iostream>
using namespace std;

int pintandoFractales(int n);

int main() {
	int n;
	cin >> n;

	while (cin) {
		cout << pintandoFractales(n) << endl;
		cin >> n;
	}

	return 0;
}

int pintandoFractales(int n) {
	//Caso base
	if (n == 1) { return 4; }

	//Caso recursivo
	return 4 *(pintandoFractales(n / 2) + n);
}