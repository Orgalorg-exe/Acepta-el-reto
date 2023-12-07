#include <iostream>
#include <iomanip>
#include <fstream>

int resolver(int n) {
	int ret = 0;

	if (n == 0) { ret = 1; }
	else if (n < 3 ) { ret = n; }
	else if (n == 3) { ret = 6; }
	else if (n == 4) { ret = 4; }

	return ret;
}

void resuelveCaso() {
    int n;
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