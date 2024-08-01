#include <iostream>
#include <iomanip>
#include <fstream>

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}


unsigned long long resolver(unsigned long long w, unsigned long long h) {
    int mcd;
    if (w > h) mcd = gcd(w, h);
    else mcd = gcd(h, w);

    return (w / mcd) * (h / mcd);
}

void resuelveCaso() {
    // leer los datos de la entrada
    unsigned long long w, h;
    std::cin >> w >> h;

    unsigned long long sol = resolver(w, h);
    
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