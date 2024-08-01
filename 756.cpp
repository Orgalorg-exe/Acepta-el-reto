#include <iostream>
#include <iomanip>
#include <fstream>

const short MAX = 17;
short v[MAX] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

bool resolver() {
    short ret = 0;
    short k = 1;
    short a, b;

    while (k < MAX) {
        if (v[k] < v[k - 1]) {
            a = v[k];
            b = k;
            while (a < v[b-1]) {
                ret++;
                v[b] = v[b - 1];
                b--;
            }
            v[b] = a;
        }
        k++;
    }

    return ret % 2 == 0;
}

bool resuelveCaso() {
    // leer los datos de la entrada
    short n;
    std::cin >> n;

    if (!std::cin)
        return false;

    v[1] = n;
    for (short i = 2; i < MAX; i++) {
        std::cin >> v[i];
    }

    bool sol = resolver();

    // escribir sol
    if (sol) std::cout << "SI\n";
    else std::cout << "NO\n";

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}