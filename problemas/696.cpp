#include <iostream>
#include <iomanip>
#include <fstream>

bool resuelveCaso() {
    double aux;
    double lower, upper, n;
    unsigned long long sum = 0;

    std::cin >> aux;

    if (!std::cin)
        return false;

    upper = lower = sum = aux;
    n = 2;

    std::cin >> aux;
    while (aux != 0) {
        sum += aux;
        upper = (upper >  aux) ? upper : aux;
        lower = (lower < aux) ? lower : aux;
        n++;
        std::cin >> aux;
    }



    unsigned long long sol = ((upper + lower) * (n/2)) - sum;

    std::cout << sol << "\n";

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}