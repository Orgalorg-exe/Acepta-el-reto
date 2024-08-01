#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>

std::set<std::pair<int, int>> set;

unsigned long long resolver(unsigned long long c, unsigned long long f, int h) {
    unsigned long long ret;
    std::pair<int, int> coord;

    ret = c * (f - 1) + f * (c - 1);

    for (int i = 0; i < h; i++) {
        std::cin >> coord.first >> coord.second;

        if (coord.first - 1 > 0 && set.find(std::pair<int, int>(coord.first - 1, coord.second)) == set.end()) ret--;
        if (coord.first + 1 <= c && set.find(std::pair<int, int>(coord.first + 1, coord.second)) == set.end()) ret--;
        if (coord.second - 1 > 0 && set.find(std::pair<int, int>(coord.first, coord.second -1)) == set.end()) ret--;
        if (coord.second + 1 <= f && set.find(std::pair<int, int>(coord.first, coord.second + 1)) == set.end()) ret--;

        set.insert(coord);
    }

    return ret;
}

bool resuelveCaso() {
    // leer los datos de la entrada
    unsigned long long c, f;
    int h;
    std::cin >> c >> f >> h;

    if (!c || !f)
        return false;

    set.clear();
    unsigned long long sol = resolver(c, f, h);

    // escribir sol
    std::cout << sol << '\n';

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}
