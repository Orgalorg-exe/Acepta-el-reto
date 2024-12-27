#include <iostream>

long long resolver(long long n) {
	long long max, next, ret = 0;

	std::cin >> max;
	for (int i = 1; i < n; ++i) {
		std::cin >> next;
		if (max > next)
			ret += max - next;
		else if (next > max) {
			ret += (next - max) * i;
			max = next;
		}
	}
	
	return ret;
}

bool resuelveCaso() {

	long long n;
	std::cin >> n;

	if (!n) return false;

	long long sol = resolver(n);

	std::cout << sol << '\n';

	return true;
}

int main() {

	while (resuelveCaso());

	return 0;
}