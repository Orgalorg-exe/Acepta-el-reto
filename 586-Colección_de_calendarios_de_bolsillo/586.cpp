#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 61;

int main() {

	int v[MAX], n, c, ret;

	cin >> c;

	for (c; c > 0; --c) {

		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}

		ret = 0;
		sort(v, v + n);
		for (int i = 1; i < n; ++i) {
			ret += v[i] - v[i - 1] - 1;
		}

		cout << ret << endl;
	}

	return 0;
}