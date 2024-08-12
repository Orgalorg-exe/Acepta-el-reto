#include <iostream>
#include <iomanip>
#include <fstream>


int resolver(int n) {
    int num_ceros = 0;
    int d;
    int n_aux = 1;

    while (n >= 10) {
        while (n > 0) {
            d = n % 10;
            while (!d) {
                num_ceros++;
                n /= 10;
                d = n % 10;
            }
            n_aux *= d;
            n /= 10;
        }
        n = n_aux;
        n_aux = 1;
    }

    return n*10 + num_ceros;
}

bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;

    if (!n)
        return false;

    int sol = resolver(n);

    // escribir sol
    std::cout << sol << '\n';

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}
