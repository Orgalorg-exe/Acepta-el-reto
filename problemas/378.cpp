#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>

int n;
//        idx           max, min
std::map<int, std::pair<int, int>> mapa;

bool resolver() {
    std::map<int, std::pair<int, int>>::iterator ita, itb;
    ita = itb = mapa.begin();
    ita++;

    for (; ita != mapa.end(); ita++, itb++) {
        if (ita->second.second <= itb->second.first) return false;
    }

    return true;
}

bool resuelveCaso() {
    std::cin >> n;

    if (!n)
        return false;

    mapa.clear();
    int a, b;
    for (int i = 0; i < n; i++) {
        std::cin >> a >> b;
        if (mapa.find(a) == mapa.end())
            mapa.insert(std::pair<int, std::pair<int, int>>(a, std::pair<int, int>(b, b)));
        else {
            mapa[a].first = b > mapa[a].first ? b : mapa[a].first;
            mapa[a].second = b < mapa[a].second ? b : mapa[a].second;
        }
    }

    bool sol = resolver();

    if (sol) std::cout << "SI\n";
    else std::cout << "NO\n";

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}
