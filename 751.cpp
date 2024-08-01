#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>


int resolver(int a1, int a2, int b1, int b2) {
    int ret = std::min(a2, b2) - std::max(a1, b1) + 1;
    if (ret < 0) ret = 0;

    return ret;
}

void resuelveCaso() {
    // leer los datos de la entrada
    int a1, a2, b1, b2;
    std::cin >> a1 >> a2 >> b1 >> b2;

    int sol = resolver(a1, a2, b1, b2);
    // escribir sol

    std::cout << sol << '\n';
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}