#include <iostream>
#include <iomanip>
#include <fstream>


void resuelveCaso() {
    int n;
    std::cin >> n;

    unsigned long long sum = 0, max= 0;
    int aux;
    int N = n * n;
    for (int i = 0; i < N; i++) {
        std::cin >> aux;
        if (aux >= max) {
            sum += max;
            max = aux;
        }
        else {
            sum += aux;
        }
    }

    if (sum == max)
        std::cout << "SI\n";
    else
        std::cout << "NO\n";
    
}

int main() {

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    return 0;
}