#include <iostream>
#include <iomanip>
#include <fstream>

bool resolver(int n) {
    int a, b;
    for(int i = 0; i < 3; i++){
        a = n / 1000;
        b = n % 1000;
        if (a == b) return true;

        a = n / 100;
        b = n % 100;
        n = (b * 10000) + a;
    }
    return false;
}

void resuelveCaso() {
    int d, m, a, n;
    std::cin >> d >> m >> a;
    n = (d * 10000) + (m*100) + a;

    bool sol = resolver(n);
    if (sol)
        std::cout << "DIVERTIDOS\n";
    else
        std::cout << "INSULSOS\n";
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}