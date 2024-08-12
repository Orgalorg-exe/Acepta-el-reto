#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using vii = std::vector<std::pair<int, int>>;

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

long long resolver(vii const & v, int n) {
    long long sol = INT_MAX;
    double numerador, denominador;
    double instante;

    for (int j = 1; j < n; j++) {
        if (v[j].first == v[j - 1].first) {
            //if(sgn(v[j - 1].second) != sgn(v[j].second)) continue;
            if (v[j - 1].second == v[j].second) { sol = 0; break; }
        }
        denominador = v[j - 1].second - v[j].second;
        if (denominador != 0) {
            numerador = v[j].first - v[j - 1].first;
            instante = numerador / denominador;
            if (instante >= 0) {
                sol = std::min(sol, (long long)std::floor(instante));
                if (sol == 0) break;
            }
        }
    }
    return sol;
}



bool resuelveCaso() {
    int n;
    std::cin >> n;
    
    if (!n)
        return false;

    vii ciclistas(n);

    int x, v;
    for (int i = 0; i < n; i++) {
        std::cin >> x >> v;
        ciclistas[i] = std::make_pair(x, v);
    }

    std::sort(ciclistas.begin(), ciclistas.end());
    long long sol = resolver(ciclistas, n);

    if (sol == INT_MAX) {
        std::cout << "SIN COLISION\n";
    }
    else {
        std::cout << sol << "\n";
    }

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}