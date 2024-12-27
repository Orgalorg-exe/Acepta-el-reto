#include <iostream>
using namespace std;

int sol(int n) {
	if (n == 1 || !(n % 2))
		return n;
	return n - 1;
}

int main() {
	int n;
	cin >> n;

	while (n != 0) {
		cout << sol(n) << endl;
		cin >> n;
	}

	return 0;
}