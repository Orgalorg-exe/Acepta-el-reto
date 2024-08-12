#include<iostream>
using namespace std;

int baseDiez2baseSeis(int n);

int main() {

	int numCasos, n;
	cin >> numCasos;

	for (; numCasos > 0; --numCasos) {
		cin >> n;
		cout << baseDiez2baseSeis(n) << endl;
	}

	return 0;
}

int baseDiez2baseSeis(int n) {
	//Caso base
	if (n < 6)
		return n;

	//Caso recursivo
	return (baseDiez2baseSeis(n / 6) * 10) + n % 6;
}