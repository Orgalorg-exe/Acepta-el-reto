#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>


bool resolver(int n1, int n2) {
    return std::min(n1, n2) % 2 == 0 && abs(n2 - n1) == 1;
}

void resuelveCaso() {
    int n1, n2;
    char c;
    std::cin >> n1 >> c >> n2;

    bool sol = resolver(n1, n2);
    
    if (sol)
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