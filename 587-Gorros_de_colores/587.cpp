#include <iostream>

using namespace std;

int minExtra(string gorros);

int main() {

	string gorros;
	int c;

	cin >> c;
	for (c; c > 0; --c) {
		cin >> gorros;
		cout << minExtra(gorros) << endl;
	}

	return 0;
}

int minExtra(string gorros) {
	int ret = 1;

	for (int i = 1; i < gorros.length(); ++i) {
		if (i % 2 == 0)
			++ret;
		if (i % 2 == 1 && gorros[i] == gorros[i - 1])
			++ret;
	}

	return ret;
}