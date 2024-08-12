#include <iostream>
#include <iomanip>
#include <fstream>


long long resolver(long long n) {
    long long m = n - 2;
    return 2 * n * n + 2 * n * m + 2 * m * m;
}

void resuelveCaso() {
    long long n;
    std::cin >> n;

    long long sol = resolver(n);
    
    std::cout << sol << std::endl;
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}