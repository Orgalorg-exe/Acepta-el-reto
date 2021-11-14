#include <iostream>
#include <string>

using namespace std;

string baseRaizDiez(string n);

int main() {
	string n;
	cin >> n;

	while (cin) {
		cout << baseRaizDiez(n) << endl;
		cin >> n;
	}

	return 0;
}


//pre
string baseRaizDiez(string n) {

	//Invariante
	//
	string ret = "";
	ret += n[0];
	int i = 1;

	//Complejidad
	// O(n)
	// n = n.length
	while (i < n.length()) {
		ret += "0";
		ret += n[i];
		++i;
	}

	return ret;
}
//post
