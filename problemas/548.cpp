#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


bool esPosible(int n, int p, std::vector<int> const& v, int m) {
    int p_cnt = 0;
    int aux = 0;

    for (int i = 0; i < n; i++) {
        if (v[i] > m) return false;
        else if (aux + v[i] > m) {
            aux = v[i];
            p_cnt++;
        }
        else aux += v[i];

        if (p_cnt > p) return false;
    }

    return true;
}


int resolver(int n, int p, int acum, int max, std::vector<int>const& v) {
    int ini = max, fin = acum, m = (max + acum) / 2;

    while (ini < fin) {
        if (esPosible(n, p, v, m)) fin = m;
        else ini = m + 1;
        m = (fin + ini) / 2;
    }

    return m;
}

bool resuelveCaso() {
    int n, p;
    std::cin >> n >> p;

    if (!std::cin)
        return false;

    std::vector<int> v(n);
    int acum = 0;
    int max = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
        acum += v[i];
        max = (v[i] > max) ? v[i] : max;
    }

    int sol = resolver(n, p, acum, max, v);
    std::cout << sol << '\n';

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}