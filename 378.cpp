#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>

int n;
std::map<int, int> mapa;

bool justicia() {
    std::map<int, int>::iterator it, ti;

    for (
        it = mapa.begin(), ti = ++mapa.begin();
        ti != mapa.end();
        it++, ti++
    ) {
        if (it->second >= ti->second) return false;
    }

    return true;
}

std::string resolver() {
    bool esJusta = justicia();
    if (esJusta) return "SI";
    return "NO";
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
            mapa.insert(std::pair<int, int>(a, b));
        else
            mapa[a] = b > mapa[a] ? b : mapa[a];
    }

    std::string sol = resolver();
    
    std::cout << sol << '\n';
    
    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}
