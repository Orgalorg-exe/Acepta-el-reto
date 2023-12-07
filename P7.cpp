#include <iostream>
using namespace std;

bool uva(long long & max, long long &min);

int main() {

	long long a = 0, b = 1000000000000000001;

	while (cin) {
		if (uva(a, b))
			cout << a << " " << b << endl;
		else
			cout << "NO HAY MEJOR\n";
	}

	return 0;
}

bool uva(long long & max, long long & min) {
	long long a, b;
	long long maxAux = max, minAux = min;
	bool ret = false;

	cin >> a >> b;
	while (a) {
		if (a > maxAux && b < minAux) {
			maxAux = a; minAux = b;
			max = a; min = b;
			ret = true;
		}
		else if (a > maxAux) {
			maxAux = a;
			ret = false;
		}
		else if (b < minAux) {
			minAux = b;
			ret = false;
		}

		cin >> a >> b;
	}

	return ret;
}