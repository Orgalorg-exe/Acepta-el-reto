#include <iostream>
#include <string>

using namespace std;

string cad;
int n;

int numSumas(string cad, int n);

int main() {
	
	int m = 0;
	cin >> m;

	for (m; m > 0; --m) {
	
		cin >> n >> cad;

		cout << numSumas(cad, n) << endl;
	}

	return 0;
}

int numSumas(string cad, int n) {

	int ret = 0;
	int a = 0, b = 1;
	int sum = (cad[a] - '0');

	if (sum == n) {
		ret = 1;
	}

	while (b < cad.length()) {

		if (sum + (cad[b] - '0') <= n) {
			sum += (cad[b] - '0');
			++b;
		}
		else {
			sum -= (cad[a] - '0');
			++a;

			if (a == b) {
				if ((cad[b] - '0') > n) {
					++a;
					++b;
				}
				else {
					sum = (cad[b] - '0');
					++b;
				}
			}
		}

		if (sum == n) {
			++ret;
		}
	}

	return ret;
}