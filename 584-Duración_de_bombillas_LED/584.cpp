#include <iostream>

using namespace std;

int main() {

	int n, a, b, c;

	cin >> n;

	for (n; n > 0; --n) {

		cin >> a >> b >> c;

		if (b * c > a)
			cout << "HORAS" << endl;
		else if (b * c < a)
			cout << "ENCENDIDOS" << endl;
		else
			cout << "AMBAS" << endl;
	}

	return 0;
}