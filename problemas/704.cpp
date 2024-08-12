#include <iostream>
#include <iomanip>
#include <fstream>

void resuelveCaso() {
    int W, H;
    std::cin >> W >> H;

    W *= 2; H *= 2;

    int num_colores;
    std::cin >> num_colores;

    int min = std::min(W, H);
    int max = std::max(W, H);
    bool min_ok = false;
    bool max_ok = false;

    int n;
    for (int i = 0; i < num_colores; i++) {
        std::cin >> n;
        if (n >= max && !max_ok) {
            max_ok = true;
        }
        else if (n >= min) {
            min_ok = true;
        }
    }

    if (min_ok && max_ok) {
        std::cout << "SI\n";
    }
    else {
        std::cout << "NO\n";
    }
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}