#include <iostream>

using namespace std;

bool saltarines(int n);

int main() {
	int numCasos = 0, n = 0;
	cin >> numCasos;

	for (int i = 0; i < numCasos; ++i) {
		cin >> n;
		if (saltarines(n)) { cout << "SALTARINES" << endl;  }
		else { cout << "NORMALES" << endl; }
	}

	return 0;
}

bool saltarines(int n) {
	bool ret = false;

	return ret;
}