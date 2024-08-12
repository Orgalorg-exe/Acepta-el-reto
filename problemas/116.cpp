#include <iostream>
#include <iomanip>
#include <fstream>

bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    std::cin >> n;
    
    if (! std::cin)
        return false;
    
    for (int i = 0; i < n; i++){
        std::cout << "Hola mundo.\n";
    }
    
    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}
