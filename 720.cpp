#include <iostream>
#include <iomanip>
#include <fstream>

int resolver(int x, int n) {
    int m = 0;
    int aux;
    while (m < x) {
        aux = n + m;
        m = aux / 2;
        if (aux % 2 == 1) m++;
    }

    return n - m;
}

bool resuelveCaso() {
    int n;
    std::cin >> n;

    if (!std::cin)
        return false;

    long long a, b;
    int x = 0;
    std::cin >> a;
    for (int i = 1; i < n; i++) {
        std::cin >> b;
        if (b < a) x = i;
        a = b;
    }

    int sol = resolver(x, n);

    std::cout << sol << '\n';

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}