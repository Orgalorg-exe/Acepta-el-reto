#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <queue>

bool resuelveCaso() {
    int F, A, C;
    std::cin >> F >> A >> C;

    if (!std::cin)
        return false;

    std::priority_queue<int, std::vector<int>, std::less<int>> cola;
    int aux;
    for (int i = 0; i < F; i++) {
        std::cin >> aux;
        if (A-aux > 0) 
            cola.push(A - aux);
    }

    long long sol = 0;

    while (!cola.empty() && C) {
        aux = cola.top(); cola.pop();
        sol += aux;
        if (aux -1 > 0)
            cola.push(aux - 1);
        C--;
    }
    
    std::cout << sol << "\n"; 

    return true;

}

int main() {

    while (resuelveCaso());

    return 0;
}