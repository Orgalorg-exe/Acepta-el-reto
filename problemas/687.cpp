#include <iostream>
#include <iomanip>
#include <fstream>

bool resuelveCaso() {

    int V = 0, E = 0;
    std::cin >> V;
    if (!V) return false;

    int a, b;
    std::cin >> a >> b;
    while (a && b) {
        E++;
        std::cin >> a >> b;
    }

    std::cout << E - (V-1) << "\n";

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}