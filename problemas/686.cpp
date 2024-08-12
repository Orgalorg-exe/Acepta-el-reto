#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>

bool allDigits(std::string s) {
    int aux = 0; // 0000 0000 0000 0000
    int e = 0, p = 0;
    for (char c : s) {
        if (c == '0') return false;
        e = int(c - '0') - 1;
        p = std::pow(2, e);
        aux = aux | p;
    }

    return aux == 511; // 0000 0001 1111 1111
}

int calc_cot_inf(int N, int D) {
    int ini = 2, fin = 10000, m;
    std::string aux = "";
    while (ini <= fin) {
        m = (ini + fin) / 2;
        aux = std::to_string(N * m) + std::to_string(D * m);
        if (aux.length() >= 9) fin = m-1;
        else ini = m+1;
    }

    return m;
}

int calc_cot_sup(int N, int D) {
    int ini = 2, fin = 10000, m;
    std::string aux = "";
    while (ini <= fin) {
        m = (ini + fin) / 2;
        aux = std::to_string(N * m) + std::to_string(D * m);
        if (aux.length() > 9) fin = m-1;
        else ini = m+1;
    }

    return m;
}

int resolver(int N, int D) {
    if (N % 10 == 0 || D % 10 == 0) return 0;

    int cot_inf = calc_cot_inf(N, D);
    int cot_sup = calc_cot_sup(N, D);
    int ret = 0;

    std::string aux = "";
    for (int i = cot_inf; i <= cot_sup; i++) {
        aux = std::to_string(N * i) + std::to_string(D * i);
        if (aux.length() == 9 && allDigits(aux)) ret++;
    }

    return ret;
}


bool resuelveCaso() {
    int N, D;

    std::cin >> N >> D;

    if (!N && !D)
        return false;

    int sol = resolver(N, D);

    std::cout << sol << "\n";

    return true;

}

int main() {

    while (resuelveCaso());

    return 0;
}