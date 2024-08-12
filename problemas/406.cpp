#include <iostream>
#include <string>

using namespace std;

void updateYongeStreet(string& v);
void printYongeStreet(string v);

int main() {
	string v;
	cin >> v;
	while (cin) {
		updateYongeStreet(v);
		printYongeStreet(v);
		cin >> v;
	}

	return 0;
}


void updateYongeStreet(string& v) {

	int a = v.length() - 1, b = v.length() - 1;

	while (a > -1) {

		if (isalpha(v[a])) {
			if (b == v.length() - 1)
				v[a] = '.';
			else {
				swap(v[a], v[b]);
				--b;
			}
		}

		else if (v[a] == '|') {
			b = a - 1;
			while (b > -1 && v[b] != '.')
				--b;
			a = b;
		}

		--a;
	}
}

void printYongeStreet(string v) {
	int n, p;
	cin >> n;

	if (n > 0) {
		cin >> p;
		cout << v[p - 1];
		for (n; n > 1; --n) {
			cin >> p;
			cout << ' ' << v[p - 1];
		}
	}
	cout << endl;
}
