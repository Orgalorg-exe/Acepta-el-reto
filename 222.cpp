#include <iostream>
#include <math.h>

using namespace std;

int x, n;

int seriePotencias_v1(int x, int n);
int seriePotencias_v2(int x, int n);
int seriePotencias_v3(int x, int n);

int main() {

	cin >> x >> n;

	while (cin) {

		cout << seriePotencias_v3(x, n) << endl;

		cin >> x >> n;
	}
}

int seriePotencias_v1(int x, int n) { // Time Limit
	int ret = 1;
	int i = 1;

	while (i <= n) {
		ret = (ret + (int)pow(x, i)) % 1000007;
		++i;
	}

	return ret;
}

int seriePotencias_v2(int x, int n) { // Memory Limit
	int ret;

	if (n == 0) { ret = 1; }
	else if (n == 1) { ret = 1 + x; }
	else { ret = (1 + x * seriePotencias_v2(x, n - 1)) % 1000007; }

	return ret;
}

int seriePotencias_v3(int x, int n) { // Accept
	int ret = 1, a = 1;
	int i = 0;

	while (i < n) {
		a = (a * x) % 1000007;
		ret = (ret + a) % 1000007;
		++i;
	}

	return ret;
}
