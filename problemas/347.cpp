#include<iostream>
using namespace std;

int pajaritasDePapel(int b, int a) {

	//Caso base
	if (b < 10 || a < 10)
		return 0;

	//Caso recursivo
	int n;
	if (b >= a) {
		n += b / a;
		pajaritasDePapel(b % a, a);
	}
	else {
		n += a / b;
		pajaritasDePapel(b, a % b);
	}

	return n;
}

int main() {

	int b, a, n = 0;
	cin >> b >> a;

	while (b != 0) {
		cout << pajaritasDePapel(b, a) << endl;
		cin >> b >> a;
	}

	return 0;
}