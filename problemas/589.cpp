#include <iostream>

using namespace std;

int main() {

	long long n, max, next, ret;
	cin >> n;

	while (n != 0) {
		cin >> max;
		ret = 0;
		for (int i = 1; i < n; ++i) {
			cin >> next;
			if (max > next)
				ret += max - next;
			else if (next > max) {
				ret += (next - max) * i;
				max = next;
			}
		}

		cout << ret << endl;

		cin >> n;
	}

	return 0;
}