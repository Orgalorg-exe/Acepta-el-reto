#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>

using is = std::pair<int, std::string>;
using vis = std::vector<is>;

bool resuelveCaso() {
    int n;
    std::cin >> n;
    if (!n)
        return false;

    std::map<std::string, int> mapita; //nombre, index
    std::vector<is> v; // mins, nombre

    int mins;
    char c;
    std::string nombre;
    for (int i = 0, j = 0; i < n; ++i) {
        std::cin >> mins;
        std::getline(std::cin, nombre);
        nombre.erase(nombre.begin());
        if (mapita.find(nombre) == mapita.end()) {
            mapita.insert(std::make_pair( nombre, j));
            v.push_back(std::make_pair(mins, nombre));
            j++;
        }
        else {
            v[mapita[nombre]].first += mins;
        }
    }

    sort(v.begin(), v.end(), 
        [](const is& x, const is& y) {
            // compare the second value
            if (x.first != y.first) {
                return x.first > y.first;
            }

            // compare first only if the second value is equal
            return x.second < y.second;
        });

    int i = 0;
    int limit = std::min(3, (int)v.size());
    while (i < limit && v[i].first >= 30) {
        std::cout << v[i].second << "\n";
        i++;
    }

    std::cout << "---\n";

    return true;

}

int main() {

    while (resuelveCaso());

    return 0;
}