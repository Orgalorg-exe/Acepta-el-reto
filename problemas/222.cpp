#include <iostream>
#include <math.h>

using namespace std;

int seriePotencias(int x, int n);

int main() {
	int x, n;

	while (cin >> x >> n) {
		cout << seriePotencias(x, n) << endl;
	}
}

int seriePotencias(int x, int n) {
	int ret = 1, a = 1;
	int i = 0;

	while (i < n) {
		a = (a * x) % 1000007;
		ret = (ret + a) % 1000007;
		++i;
	}

	return ret;
}
