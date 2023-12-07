#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>


int resolver(float n, float cap) {
    return 10 * ceil(n / cap);
}

bool resuelveCaso() {
    float n, cap;

    std::cin >> n >> cap;

    if (n == 0 && cap == 0)
        return false;

    int sol = resolver(n, cap);

    std::cout << sol << std::endl;

    return true;

}

int main() {

    while (resuelveCaso());

    return 0;
}