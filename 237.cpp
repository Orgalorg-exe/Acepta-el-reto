#include<iostream>
using namespace std;

string esPolidivisible(long long n);
bool esPolidivisible(long long n, short& numDig);

int main() {
	long long int n;
	cin >> n;

	while (cin) {
		cout << esPolidivisible(n) << endl;
		cin >> n;
	}

	return 0;
}

string esPolidivisible(long long n) {
	short foo;

	if (esPolidivisible(n, foo)) 
		return "POLIDIVISIBLE";

	return "NO POLIDIVISIBLE";
}

bool esPolidivisible (long long n, short & numDig ){
	//Caso base
	if (n < 10) {
		numDig = 1;
		return true;
	}

	//Caso recursivo
	bool ret = esPolidivisible(n/10, numDig);
	++numDig;
	return ret && (n % numDig == 0);
}