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

string baseRaizDiez(string n) {

	string ret = "";
	ret += n[0];
	int i = 1;

	while (i < n.length()) {
		ret += "0";
		ret += n[i];
		++i;
	}

	return ret;
}