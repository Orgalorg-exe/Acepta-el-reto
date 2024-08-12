#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

bool resuelveCaso() {
    int c, m, n;
    std::cin >> c >> m >> n;

    if (!std::cin)
        return false;

    int max_altura, min_altura;
    int ant_nivel, curr_nivel, ant_altura, curr_altura;
    std::cin >> ant_nivel >> curr_nivel;

    max_altura = min_altura = ant_altura = curr_nivel - ant_nivel;
    ant_nivel = curr_nivel;

    bool ok = true;
    for (int i = 1; i < n; i++) {
        std::cin >> curr_nivel;
        curr_altura = curr_nivel - ant_nivel;

        if (std::abs(curr_altura - ant_altura) > c) {
            ok = false; break;
        }

        max_altura = (curr_altura > max_altura) ? curr_altura : max_altura;
        min_altura = (curr_altura < min_altura) ? curr_altura : min_altura;
        if (max_altura - min_altura > m) {
            ok = false; break;
        }

        ant_nivel = curr_nivel;
        ant_altura = curr_altura;
    }

    if (ok) std::cout << "Ok\n";
    else {
        std::string aux;
        std::getline(std::cin, aux);
        std::cout << "Tropiezo\n";
    }

    return true;

}

int main() {

    while (resuelveCaso());

    return 0;
}