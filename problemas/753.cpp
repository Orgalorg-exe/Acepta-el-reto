#include <iostream>
#include <iomanip>
#include <fstream>

#define MAX 12

int v[MAX];

bool VA(
    int n, int v[],
    int k, int izq, int der
) {
    // Caso Base
    if (k == n) {
        return izq == der;
    }

    // Caso recursivo

    bool ret;

    ret = VA(n, v, k + 1, izq + v[k], der);
    if (ret) return true;
    
    return VA(n, v, k + 1, izq, der + v[k]);
}

bool resolver(int n, int v[]) {
    return VA(n, v, 0, 0, 0);
}

bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;

    if (!n)
        return false;

    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    bool sol = resolver(n, v);

    // escribir sol
    if (sol) std::cout << "SI\n";
    else std::cout << "NO\n";

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}