#include <iostream>
#include <iomanip>
#include <fstream>


long long resolver(float n) {
    return 3 * ((n + 1) * (n / 2));
}

bool resuelveCaso() {
    float n;
    std::cin >> n;

    if (n == 0)
        return false;

    long long sol = resolver(n);

    std::cout << sol << std::endl;

    return true;

}

int main() {

    while (resuelveCaso());

    return 0;
}
