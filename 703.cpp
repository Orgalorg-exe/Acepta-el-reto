#include <iostream>
#include <iomanip>
#include <fstream>

void resuelveCaso() {
    char caux;
    int ent, cero, v;
    double frac;

    std::cin >> ent >> caux >> frac >> cero >> v;
    frac /= 60.0;

    int dist = ent * v + frac * v;

    std::cout << dist << "\n";
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}