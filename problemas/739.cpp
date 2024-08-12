#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>


int resolver(int a1, int a2, int b1, int b2) {
    if (!a1 or !a2 or !b1 or !b2) return 0;

    int c1, c2;
    int d1, d2;

    c1 = ceil(float(a1) / b1);
    c2 = ceil(float(a2) / b2);

    d1 = ceil(float(a1) / b2);
    d2 = ceil(float(a2) / b1);

    return std::min(c1 * c2, d1 * d2);
}

void resuelveCaso() {
    // leer los datos de la entrada
    int anchoPared, altoPared;
    int anchoLosa, altoLosa;

    std::cin >> anchoPared >> altoPared >> anchoLosa >> altoLosa;

    int sol = resolver(anchoPared, altoPared, anchoLosa, altoLosa);

    // escribir sol
    std::cout << sol << '\n';
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}