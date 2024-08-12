#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>

bool resuelveCaso() {
    int n;
    std::cin >> n;
    if (!n)
        return false;

    int b; 
    std::cin >> b;

    std::map<int, int> productos;
    int key, value;
    for (int i = 0; i < b; i++) {
        std::cin >> value >> key;
        if (productos.find(key) == productos.end()) {
            productos.insert({key, value});
        } else{
            productos[key] += value;
        }
    }

    std::map<int, int>::reverse_iterator rit = productos.rbegin();
    while (rit != productos.rend() && n > rit->second) {
        n -= rit->second;
        rit++;
    }

    if (rit != productos.rend())
        std::cout << rit->first << "\n";
    else
        std::cout << productos.begin()->first << "\n";

    return true;
}

int main() {

    while (resuelveCaso());

    return 0;
}