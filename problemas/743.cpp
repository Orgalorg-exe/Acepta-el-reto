#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

int resolver(int n) {
    int ret = 0, v;

    for (int i = 0; i < n; i++) {
        std::cin >> v;

        ret += v - ceil(v / 2.0);
    }

    return ret;
}


bool resuelveCaso() {
    int n;
    std::cin >> n;

    if (!n)
        return false;

    int sol = resolver(n);

    std::cout << sol << '\n';

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}
