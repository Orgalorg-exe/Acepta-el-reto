#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>

int resolver(std::map<int, int> & map, int n) {
    std::map<int, int>::iterator it;
    int ret = 0;
    for (auto const& x : map) {
        ret += x.second / 2;
    }

    return ret;
}

bool resuelveCaso() {
    int n;
    std::cin >> n;

    if (!n)
        return false;

    std::map<int, int> map;
    int aux;
    for (int i = 0; i < n; i++) {
        std::cin >> aux;
        if (map.find(aux) != map.end()) {
            map[aux] ++;
        }
        else {
            map.insert(std::pair<int, int>(aux, 1));
        }
    }

    int sol = resolver(map, n);

    std::cout << sol << '\n';

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}
