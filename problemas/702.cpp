#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

bool resuelveCaso() {
    int dinero_inicial;
    std::cin >> dinero_inicial;

    if (!std::cin)
        return false;

    int num_transacciones;
    std::cin >> num_transacciones;

    std::vector<int> cartilla(12, 0);

    int d, m, c;
    char sign, caux;
    std::string aux;
    for (int i = 0; i < num_transacciones; i++) {
        std::cin >> d >> caux >> m >> sign >> c;
        std::getline(std::cin, aux);

        if (sign == '-') c = -c;
        cartilla[m - 1] += c;
    }

    for (int i = 0; i < 11; i++) {
        dinero_inicial += cartilla[i];
        std::cout << dinero_inicial << " ";
    }
    dinero_inicial += cartilla[11];
    std::cout << dinero_inicial << "\n";

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}