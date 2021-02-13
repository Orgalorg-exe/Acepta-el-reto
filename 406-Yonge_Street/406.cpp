#include <iostream>
#include <string>

using namespace std;

void yongeStreet(string& calle);

int main() {

	string calle;
	int n, p;

	cin >> calle;

	while (cin) {

		yongeStreet(calle);

		cin >> n >> p;

		cout << calle[p - 1];

		for (int i = 1; i < n; ++i) {
			cin >> p;
			cout << ' ' << calle[p - 1];
		}

		cout << endl;

		cin >> calle;
	}

	return 0;
}

void yongeStreet(string& calle) {

	int a = calle.length() - 2, b = calle.length() - 1;

	if (isalpha(calle[b]))
		calle[b] = '.';

	while (b > -1 && calle[b] != '.')
		--b;

	a = b - 1;

	while (a > -1) {

		if (isalpha(calle[a])) {

			if (b == calle.length() - 1)
				calle[a] = '.';
			else {
				swap(calle[a], calle[b]);
				--b;
			}
		}

		else if (calle[a] == '|') {

			b = a;

			while (b > -1 && calle[b] != '.')
				--b;

			a = b;
		}

		--a;
	}
}