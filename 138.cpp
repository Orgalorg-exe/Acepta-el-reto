#include <iostream>
#include <iomanip>
#include <fstream>

int resolver(long long n) {
	int ret = n / 5;

	if (ret > 0) {
		ret += resolver(ret);
	}

	return ret;
}

void resuelveCaso() {
    long long n;
	std::cin >> n;
    
    int sol = resolver(n);
    
	std::cout << sol << '\n';
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}