#include <iostream>
#include <iomanip>
#include <fstream>


void resuelveCaso() {
    int n, m;
    std::cin >> n >> m;
    
    if(m * 12 <= n)
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