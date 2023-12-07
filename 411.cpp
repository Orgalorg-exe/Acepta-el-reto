#include<iostream>
#include <string>

using namespace std;

int numElefantes(int max);

int main() {

	long long int max;
	string aux;

	cin >> max;

	while (max != 0) {
		cout << numElefantes(max) << endl;
		getline(cin, aux);
		cin >> max;
	}

	return 0;
}

int numElefantes(int max) {

	long long int pesoAcum = 0, input;
	long long int ret = 0;
	
	cin >> input;
	pesoAcum += input;

	while (pesoAcum <= max && input != 0) {
		++ret;
		cin >> input;
		pesoAcum += input;
	}

	return ret;
}