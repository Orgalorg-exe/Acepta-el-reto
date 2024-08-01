#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>
#include <cmath>


void resolver(
    int n,
    int k,
    int nPart,
    int sumAux,
    std::set<int>& sol
) {

    // Caso Base
    if (!n) {
        sol.insert(nPart + sumAux);
        return;
    }

    // Caso Recursivo
    int d = n / 10;
    int r = n % 10;
    
    // hay suma
    resolver(d, 0, 0, sumAux + (r*pow(10, k) + nPart), sol);

    // no hay suma
    resolver(d, k + 1, r*pow(10, k) + nPart, sumAux, sol);

}

void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;

    std::set<int> sol;
    resolver(n, 0, 0, 0, sol);

    std::set<int>::iterator it = sol.begin();
    std::cout << *it;
    it++;
    while (it != sol.end())
        std::cout <<' ' << *it++;
    std::cout << '\n';
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}